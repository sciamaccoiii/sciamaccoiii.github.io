import pygame

class Ship:
    def __init__(self, game, vector = pygame.math.Vector2):
        self.game = game
        self.screen = game.screen
        self.velocity = vector
        self.screen_rect = game.screen.get_rect()
        self.image = pygame.image.load('ship.png')
        self.rect = self.image.get_rect()
        self.rect.midbottom = self.screen_rect.midbottom
        self.lasers = pygame.sprite.Group()

    def center_ship(self):
        self.rect.midbottom = self.screen_rect.midbottom

    def fire(self):
        laser = Laser(game = self.game)
        self.lasers.add(laser)

    def remove_lasers(self):
        self.lasers.remove()

    def move(self):
        if self.velocity == Vector():
            return
        self.rect.left += self.velocity.x
        self.rect.top += self.velocity.y
        self.game.limit_on_screen(self.rect)

    def draw(self):
        self.screen.blit(self.image, self.rect)

    def update(self):
        fleet = self.game.fleet
        self.move()
        self.draw()
        for laser in self.lasers.sprites():
            laser.update()
        for laser in self.lasers.copy():
            if laser.rect.bottom <= 0:
                self.lasers.remove(laser)
        aliens_hit = pygame.sprite.groupcollide(fleet.aliens, self.lasers, False, True)
        for alien in aliens_hit:
            alien.hit()
            if alien.health <= 0:
                fleet.aliens.remove(alien)
            if not fleet.aliens:
                self.game.restart()

class Vector:
    def __init__(self):
        self.x = 0.0
        self.y = 0.0

    def __repr__(self):
        return “Vector ({}, {})”.format(self.x, self.y)

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return self.__add__(-1 * other)

    def __rmul__(self, k: float):
        return Vector(k * self.x, k * self.y)

    def __mul__(self, k: float):
        return self.__rmul__(k)

    def __truediv__(self, k: float):
        return self.__rmul__(1.0 / k)

    def __neg__(self):
        self.x *= -1
        self.y *= -1

    def __eq__(self):
        return self.x == other.x and self.y == other.y

@staticmethod
def test(): # feel free to change the test code
    v = Vector(x=5, y=5)
    u = Vector(x=4, y=4)
    print("v is {}".format(v))
    print("u is {}".format(u))
    print("u plus v is {}".format(u + v))
    print("u minus v is {}".format(u - v))
    print("k * u is {}".format(3 * u))
    print("-u is {}".format(-1 * u))

def main():
    Vector.test()