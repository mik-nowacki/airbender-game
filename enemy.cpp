#include "enemy.h"

Enemy::Enemy()
{
}
Enemy::~Enemy()
{

}

void Enemy::walk_animate()
{

}

void Enemy::attack_animate(float &angle_from_trigger)
{

}

void Enemy::trigger_AI(sf::RectangleShape &trigger_box)
{
    if(this->enemy_type!=DUMMY)
    {
        if(this->hit_box.getGlobalBounds().intersects(trigger_box.getGlobalBounds()))
        {
            this->if_triggered = 1;
            this->pause_time = 4;
        }
        if (this->if_triggered)
        {
            if (this->shoot_timer<500)
            {
                shoot_timer++;
            }
            else
            {
                this->shooter_center =sf::Vector2f(this->getPosition().x+(float(0.5)*this->getGlobalBounds().width),
                                             this->getPosition().y+float(0.5)*this->getGlobalBounds().height);

                this->targetPosition = sf::Vector2f(trigger_box.getPosition().x+(float(0.5)*trigger_box.getGlobalBounds().width),
                                                    trigger_box.getPosition().y+float(0.5)*trigger_box.getGlobalBounds().height);
                skill = new Projectile();
                switch (this->enemy_type)
                {
                case SOLDIER: skill->make_fireball(this->skill_look,short(FIREBALL)); break;
                case SLIME:   skill->make_iceCone(this->skill_look,short(ICECONE)); break;
                case GOLEM: skill->make_boulder(this->skill_look, short(BOULDER)); break;
                case WORM: skill->make_fireball(this->skill_look, short(FIREBALL)); break;
                }
                this->angle = this->get_angle(shooter_center,targetPosition);
                skill->launchProjectile(this->shooter_center,targetPosition);
                this->attack_animate(angle);
                move_dir=IDLE;
                this->shots.push_back(skill);
                this->shoot_timer=0;
            }
        }
    }
}

void Enemy::AI(const float &dt_,sf::RectangleShape &avatar_target)
{
    this->hit_box.setPosition(this->getPosition());
    for (size_t s=0; s<shots.size();s++)
    {
        this->shots[s]->update_movement(dt_);
    }
    this->trigger_AI(avatar_target);
    if(!this->getGlobalBounds().intersects(this->map_edge.getGlobalBounds())) // COUNTER MOVEMENT
    {
        switch (this->move_dir)
        {
        case 1: move_dir = 2; break;
        case 2: move_dir = 1; break;
        case 3: move_dir = 4; break;
        case 4: move_dir = 3; break;
        }
        this->walk_animate();
    }
    switch(this->move_dir)
    {
    case 0:                                       // STAY
        break;
    case 1:
        this->move(0.f,-movementSpeed*dt_);       // UP
        break;
    case 2:
        this->move(0.f,movementSpeed*dt_);        // DOWN
        break;
    case 3:
        this->move(-movementSpeed*dt_,0.f);       // LEFT
        break;
    case 4:
        this->move(movementSpeed*dt_,0.f);        // RIGHT
        break;
    }
    if (clock.getElapsedTime().asSeconds()>pause_time)
    {
        move_dir = rand()%5; clock.restart();
        this->walk_animate();
    }
}
