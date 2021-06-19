#include "enemy.h"

Enemy::Enemy(sf::Texture *look_from_game, sf::Texture *skill_look_from_game, sf::RectangleShape &game_boarder)
{
    this->setPosition(sf::Vector2f(rand()%1800,rand()%1800));
    this->map_edge = game_boarder;
    this->clock.restart();
    move_dir = rand()%5;

    this->look=look_from_game;
    this->setTexture(*look);

    this->skill_look=skill_look_from_game;
    this->ability.setTexture(*skill_look);
}
Enemy::~Enemy()
{
}
void Enemy::walk_animate(){}
void Enemy::attack_animate(float &angle_from_trigger){}
void Enemy::updateGUI(sf::RenderTarget &win)
{
    bar.setPosition(hit_box.getPosition()+sf::Vector2f(50,-25));
    bar_back.setPosition(bar.getPosition());
    bar.setSize(sf::Vector2f(this->HP,20));

    win.draw(bar_back);
    win.draw(bar);
}
void Enemy::untrigger()
{
        if_triggered=false;
}
void Enemy::root()
{
    this->move_dir=IDLE;
    clock.restart();
}

void Enemy::trigger_AI(const sf::RectangleShape &trigger_box)
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
            if (this->shot_interval<shoot_timer)
            {
                shot_interval++;
            }
            else
            {
                this->shooter_center =sf::Vector2f(this->getPosition().x+(float(0.5)*this->getGlobalBounds().width),
                                             this->getPosition().y+float(0.5)*this->getGlobalBounds().height);

                this->targetPosition = sf::Vector2f(trigger_box.getPosition().x+(float(0.5)*trigger_box.getGlobalBounds().width),
                                                    trigger_box.getPosition().y+float(0.5)*trigger_box.getGlobalBounds().height);
                skill = std::make_unique<Projectile>();
                switch (this->enemy_type)
                {
                case SOLDIER: skill->make_fireball(this->skill_look,short(FIREBALL)); break;
                case SLIME:   skill->make_iceCone(this->skill_look,short(ICECONE)); break;
                case GOLEM: skill->make_boulder(this->skill_look, short(BOULDER)); break;
                case WORM: skill->make_fireball(this->skill_look, short(FIREBALL)); break;
                case FIRE_LORD: skill->make_fireball(this->skill_look, short(FIREBALL)); break;
                }
                this->angle = this->get_angle(shooter_center,targetPosition);
                skill->launchProjectile(this->shooter_center,targetPosition);
                this->attack_animate(angle);
                move_dir=IDLE;
                this->shots.push_back(std::move(skill));
                this->shot_interval=0;
            }
        }
    }
}
void Enemy::hit_box_position(){}

void Enemy::AI_movement(const float &dt_)
{
    if (hit_box.getPosition().x<0 ) // push right
    {
        this->move(movementSpeed*dt_,0);
    }
    else if (hit_box.getPosition().y<0) // push down
    {
        this->move(0,movementSpeed*dt_);
    }
    else if (hit_box.getPosition().x+hit_box.getGlobalBounds().width>map_edge.getGlobalBounds().width)  // push left
    {
        this->move(-movementSpeed*dt_,0);
    }
    else if (hit_box.getPosition().y+hit_box.getGlobalBounds().height>map_edge.getGlobalBounds().height) // push up
    {
        this->move(0,-movementSpeed*dt_);
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
    this->hit_box_position();
}

void Enemy::AI(const float &dt_, const sf::RectangleShape &avatar_target, sf::RenderTarget &win)
{
    for (size_t s=0; s<shots.size();s++)
    {
        this->shots[s]->update_movement(dt_);
    }
    this->trigger_AI(avatar_target);
    this->AI_movement(dt_);
    if (clock.getElapsedTime().asSeconds()>pause_time)
    {
        move_dir = rand()%5; clock.restart();
        this->walk_animate();
    }
    this->updateGUI(win);
}
