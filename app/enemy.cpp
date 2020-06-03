#include "enemy.h"

Enemy::Enemy()
{
    dx = 5;
    dy = 5;
    look = UP;
}

void Enemy::setStartPosition(int tileno)
{
    pos = tileno;

    int row = tileno / LWIDTH;
    int col = tileno % LWIDTH;

    x = col * TILESIZE + TILESIZE / 2 - ENEMYW / 2;
    y = row * TILESIZE + TILESIZE / 2 - ENEMYH / 2;
    sprite.setPosition(x, y);
}

void Enemy::load(sf::Texture *enemy_texture)
{
    texture = enemy_texture;
    sprite.setTexture(*texture);

    sprite.setTextureRect(sf::IntRect(0, 0, ENEMYW, ENEMYH));
}
