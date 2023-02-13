#include "Entity.h"

void eng::Entity::move(const float x, const float y, const float &dt)
{
    this->x = x * speed * dt;
    this->y = y * speed * dt;
    this->sprite->move(sf::Vector2f(x, y));
}

void eng::Entity::update(const float &dt)
{
}

void eng::Entity::draw(sf::RenderTarget *target)
{

    if (this->visible)
    {
        if (this->sprite)
            target->draw(*this->sprite);
    }
}

void eng::Entity::loadSprite(sf::Texture *texture)
{
    this->EntityTexture = texture;
    this->sprite = new sf::Sprite(*this->EntityTexture);
}

void eng::Entity::setPosition(const float x, const float y)
{
    if (this->sprite)
        this->sprite->setPosition(x, y);
}

eng::Entity::Entity() : Object("Entity")
{
    // Need the sprite configuration
    this->speed = 100.f;
}

eng::Entity::Entity(std::string name) : Object(name)
{
    this->sprite = nullptr;
    this->EntityTexture = nullptr;
    this->speed = 100.f;
}

eng::Entity::~Entity()
{
    delete this->sprite;
}
