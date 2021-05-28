#include "avatar.h"

Avatar::Avatar(float x, float y,float width, float height)
{
    shape.setPosition(x,y);
    shape.setSize(sf::Vector2f(width,height));
    shape.setFillColor(sf::Color::Cyan);

    if(!avatar_Sheet.loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/avatarSheet.png"))
        std::cerr << "Could not load texture" << std::endl;
//    avatar_Sheet.setRepeated(0);
    this->sprite.setTexture(avatar_Sheet);
    this->sprite.setScale(2.5,2.5);
//    this->standing.push_back(sf::IntRect(0,0,24,36));
    this->sprite.setTextureRect(idle[0]);
        this->animation_timer.restart();
}

void Avatar::steering(float dt_)
{
    this->animState = IDLE;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        shape.move(0,-avatar_movement_speed*dt_);
        view.move(0,-avatar_movement_speed*dt_);
        this->animState = MOVING_UP;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        shape.move(0,avatar_movement_speed*dt_);
        view.move(0,avatar_movement_speed*dt_);
        this->animState = MOVING_DOWN;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        shape.move(-avatar_movement_speed*dt_,0);
        view.move(-avatar_movement_speed*dt_,0);
        this->animState = MOVING_LEFT;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        shape.move(avatar_movement_speed*dt_,0);
        view.move(avatar_movement_speed*dt_,0);
        this->animState = MOVING_RIGHT;
    }
    this->sprite.setPosition(this->shape.getPosition());
}

void Avatar::idle_animation()
{
    if (this->animState==IDLE)
    {
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.15)
        {
            this->idle_counter+=1;
            if (this->idle_counter>=7)
                this->idle_counter=0;
            this->sprite.setTextureRect(this->idle[idle_counter]);
            this->animation_timer.restart();
        }
    }
    else if (this->animState==MOVING_UP)
    {
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.15)
        {
            this->up_counter+=1;
            if (this->up_counter>=10)
                this->up_counter=0;
            this->sprite.setTextureRect(this->walkUp[up_counter]);
            this->animation_timer.restart();
        }
    }
    else if (this->animState==MOVING_DOWN)
    {
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.15f)
        {
            this->down_counter+=1;
            if (this->down_counter>=9)
                this->down_counter=0;
            this->sprite.setTextureRect(this->walkDown[down_counter]);
            this->animation_timer.restart();
        }
    }
    else if (this->animState==MOVING_LEFT)
    {
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.15)
        {
            this->left_counter+=1;
            if (this->left_counter>=3)
                this->left_counter=0;
            this->sprite.setTextureRect(this->walkLeft[left_counter]);
            this->animation_timer.restart();
        }
    }
    else if (this->animState==MOVING_RIGHT)
    {
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.15)
        {
            this->right_counter+=1;
            if (this->right_counter>=3)
                this->right_counter=0;
            this->sprite.setTextureRect(this->walkRight[right_counter]);
            this->animation_timer.restart();
        }
    }
//    this->animation_timer.restart();
}

void Avatar::shooting(Projectile &bullet, std::vector<Enemy> &enemies, float dt_)
{
    this->playerCenter = sf::Vector2f(this->shape.getPosition().x+(float(0.5)*this->shape.getGlobalBounds().width),this->shape.getPosition().y+float(0.5)*this->shape.getGlobalBounds().height);
    mousePos = sf::Vector2f(mousePosView);
    this->aimDirection = mousePosView-playerCenter;
    this->aimDirNorm = aimDirection / float(sqrt(powf(aimDirection.x,2.f)+powf(aimDirection.y,2.f)));


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        bullet.shape.setPosition(playerCenter);
        bullet.speedVector=aimDirNorm*bullet.maxSpeed*100.f*dt_;

        shots.emplace_back(bullet);
    }
    for(size_t i =0; i<shots.size(); i++)
    {
        shots[i].shape.move(shots[i].speedVector);
    }
//    for(size_t i =0; i<shots.size();i++)
//    {
//        for(size_t k =0; k<enemies.size();k++)
//        if(shots[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
//        {
//            shots.erase(shots.begin()+i);
//            enemies.erase(enemies.begin()+k);

//        }
//    }
}
void Avatar::animate(float dt_)
{
//    this->animation_timer.restart();
    this->idle_animation();
    this->steering(dt_);
}
