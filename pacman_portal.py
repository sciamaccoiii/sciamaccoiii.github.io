import sys
import pygame

pygame.init()
vec = pygame.math.Vector2

#Settings ------------------------------------------------------------------------------

WINDOW_WIDTH = 610
WINDOW_HEIGHT = 670
EDGE_SPACE = 50
MAZE_WIDTH = WINDOW_WIDTH-EDGE_SPACE
MAZE_HEIGHT = WINDOW_HEIGHT-EDGE_SPACE
FPS = 60
TITLE_TEXT_SIZE = 16
FONT = 'lithograph'

#Player --------------------------------------------------------------------------------

class Player:
    def __init__(self, game, position):
        self.game = game
        self.grid_position = position
        self.pixel_position = vec((self.grid_position.x*self.game.cell_width)+EDGE_SPACE, (self.grid_position.y*self.game.cell_height)+EDGE_SPACE)

    def draw(self):
        pygame.draw.circle(self.game.screen, (190, 194, 15), (int(self.pixel_position.x), int(self.pixel_position.y)), self.game.cell_width//2-2)

    def update(self):
        pass

#Enemies -----------------------------------------------------------------------------

class Enemy:
    def __init__(self, game, position, name):
        self.game = game
        self.grid_position = position
        self.start_position = [position.x, position.y]
        self.pixel_position = vec((self.grid_position.x*self.game.cell_width)+EDGE_SPACE//2+self.game.cell_width//2,
                   (self.grid_position.y*self.game.cell_height)+EDGE_SPACE//2 +
                   self.game.cell_height//2)
        self.radius = int(self.game.cell_width//2.3)
        self.name = name
        self.color = self.set_color()
        self.direction = vec(0, 0)
        self.target = None
        self.speed = self.set_speed()

    def draw(self):
            pygame.draw.circle(self.game.screen, self.colour, (int(self.pixel_position.x), int(self.pixel_position.y)), self.radius)

    def set_color(self):
        if self.name == "Blinky":
            return (43, 78, 203)
        elif self.name == "Pinky":
            return (197, 200, 27)
        elif self.name == "Inky" :
            return (189, 29, 29)
        elif self.name == "Clyde" :
            return (215, 159, 33)

    def set_speed(self):
        if self.name == "Blinky":
            speed = 2
        else:
            speed = 1
        return speed

    def update(self):
        pass

#Game -------------------------------------------------------------------------------

class Game:
    def __init__(self):
        self.screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
        self.clock = pygame.time.Clock()
        self.running = True
        self.state = 'title_screen'
        self.cell_width = MAZE_WIDTH//27
        self.cell_height = MAZE_HEIGHT//27
        self.walls = []
        self.pills = []
        self.enemies = []
        self.enemy_position = []
        self.player_position = None
        self.load()
        self.player = Player(self, vec(self.player_position))
        self.load_enemies()

        self.load()


    def run(self):
        while self.running:
            if self.state == 'title_screen':
                self.title_events()
                self.title_update()
                self.title_draw()
            elif self.state == 'play':
                self.play_events()
                self.play_update()
                self.play_draw()
            elif self.state == 'game_over':
                self.over_events()
                self.over_update()
                self.over_draw()
            else:
                self.running = False
            self.clock.tick(FPS)
        pygame.quit()
        sys.exit()

    def draw_text(self, writing, screen, position, size, color, font_name, centered = False):
        font = pygame.font.SysFont(font_name, size)
        text = font.render(writing, False, color)
        text_size = text.get_size()
        position = list(position)
        if centered:
            position[0] = position[0] - text_size[0]//2
            position[1] = position[1] - text_size[1]//2
        screen.blit(text, position)

    def load(self):
        self.background = pygame.image.load('maze.png')
        self.background = pygame.transform.scale(self.background, (MAZE_WIDTH, MAZE_HEIGHT))

    def load_enemies(self):
        for idx, position in enumerate(self.enemy_position):
            self.enemies.append(Enemy(self, vec(position), idx))

    def draw_grid(self):
        for x in range(MAZE_WIDTH//self.cell_width):
            pygame.draw.line(self.background, (107, 107, 107), (x*self.cell_width, 0), (x*self.cell_width, MAZE_HEIGHT))
        for x in range(MAZE_HEIGHT//self.cell_height):
            pygame.draw.line(self.background, (107, 107, 107), (0, x*self.cell_height), (MAZE_WIDTH, x*self.cell_height))

# Title Screen ---------------------------------------------------------------------------------

    def title_events(self):
        pygame.mixer.music.queue('')
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                self.state = 'play'

    def title_update(self):
        pass

    def title_draw(self):
        self.screen.fill((0, 0, 0))
        self.draw_text('PRESS SPACEBAR TO BEGIN', self.screen, (WINDOW_WIDTH//2, WINDOW_HEIGHT//2), TITLE_TEXT_SIZE, (170, 132, 58), FONT, centered=True)
        self.draw_text('1 PLAYER', self.screen, (WINDOW_WIDTH//2, WINDOW_HEIGHT//2+50), TITLE_TEXT_SIZE, (33, 137, 156), FONT, centered=True)
        self.draw_text('HIGH SCORE', self.screen, (4, 0), TITLE_TEXT_SIZE, (255, 255, 255), FONT)
        pygame.display.update()

# Play -------------------------------------------------------------

    def play_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False

    def play_update(self):
        pass

    def play_draw(self):
        self.screen.fill((0, 0, 0))
        self.screen.blit(self.background, (EDGE_SPACE//2, EDGE_SPACE//2))
        self.draw_grid()
        self.draw_text('SCORE: 0', self.screen, [25, 6], 18, (255, 255, 255), FONT)
        self.draw_text('HIGHSCORE: 0', self.screen, [WINDOW_WIDTH//2, 6], 18, (255, 255, 255), FONT)
        self.player.draw()
        pygame.display.update()

# Game Over --------------------------------------------------------

    def over_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                self.state = 'play'

    def over_update(self):
        pass

    def over_draw(self):
        self.screen.fill((0, 0, 0))
        self.draw_text('GAME OVER', self.screen, (WINDOW_WIDTH // 2, WINDOW_HEIGHT // 2), TITLE_TEXT_SIZE,
                       (170, 132, 58), FONT, centered=True)
        self.draw_text('PRESS SPACEBAR TO PLAY AGAIN OR ESC TO QUIT', self.screen, (WINDOW_WIDTH // 2, WINDOW_HEIGHT // 2 + 50), TITLE_TEXT_SIZE,
                       (33, 137, 156), FONT, centered=True)
        pygame.display.update()

def main():
    game = Game()
    game.run()


# -------------------------------------------------------------------------------------
if __name__ == '__main__':
    main()