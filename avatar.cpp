#include "avatar.h"

Avatar::Avatar(sf::RectangleShape &game_boarder)
{
    this->setPosition(start_pos);
    this->hit_box.setSize(sf::Vector2f(40.f,90.f));

    this->shoot_timer=0.5;
    this->map_edge=game_boarder;
    this->trigger_area.setSize(sf::Vector2f(900.f,900.f));
//    this->trigger_area.setFillColor(sf::Color::Transparent);
//    this->trigger_area.setOutlineThickness(3.f);
//    this->trigger_area.setOutlineColor(sf::Color::Green);
    this->trigger_area.setPosition(start_pos-sf::Vector2f(400.f,400.f));

    this->walkSize.resize(5);
    this->attackSize.resize(5);

    this->setScale(2.5,2.5);
    this->animation_timer.restart();

}
void Avatar::get_textures(std::vector<sf::Texture> *mv_game, std::vector<sf::Texture> *at_game, std::vector<sf::Texture> *sk_game)
{
    move_textures = *mv_game;
    attack_textures = *at_game;
    skill_textures=*sk_game;

    for(size_t mv = 0; mv<mv_game->size(); mv++)
    {
        walkSize[mv] = move_textures[mv].getSize();
    }
    walkSize[IDLE].x /= 8;
    walkSize[MOVING_DOWN].x /= 10;
    walkSize[MOVING_UP].x /=10;
    walkSize[MOVING_LEFT].x /= 4;
    walkSize[MOVING_RIGHT].x /= 4;
    for(size_t at = 0; at<at_game->size(); at++)
    {
        attackSize[at] = attack_textures[at].getSize();
        attackSize[at].x /= 5;
    }
    this->animState = IDLE;
}
void Avatar::steering(float dt_)
{
  /*if(!this->hit_box.getGlobalBounds().intersects(this->map_edge.getGlobalBounds()))
    {
        switch(animState)
        {
        case 0:                                           break;
        case 1: this->move(0,avatar_movement_speed*dt_);

            break;
        case 2: this->move(0,-avatar_movement_speed*dt_);

            break;
        case 3: this->move(avatar_movement_speed*dt_,0);

            break;
        case 4: this->move(-avatar_movement_speed*dt_,0);

            break;
        }
    } */
    this->animState = IDLE;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->move(0,-avatar_movement_speed*dt_);
        view.move(0,-avatar_movement_speed*dt_);
        this->trigger_area.move(0,-avatar_movement_speed*dt_);
        this->animState = MOVING_UP;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(0,avatar_movement_speed*dt_);
        view.move(0,avatar_movement_speed*dt_);
        this->trigger_area.move(0,avatar_movement_speed*dt_);
        this->animState = MOVING_DOWN;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->move(-avatar_movement_speed*dt_,0);
        view.move(-avatar_movement_speed*dt_,0);
        this->trigger_area.move(-avatar_movement_speed*dt_,0);
        this->animState = MOVING_LEFT;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(avatar_movement_speed*dt_,0);
        view.move(avatar_movement_speed*dt_,0);
        this->trigger_area.move(avatar_movement_speed*dt_,0);
        this->animState = MOVING_RIGHT;
    }

    this->hit_box.setPosition(sf::Vector2f(this->getPosition().x+20.f,this->getPosition().y));
}

void Avatar::shooting(float dt_)
{
    this->attack_anim_timer+=dt_;
    this->on_cooldown+=dt_;
    this->element_swap+=dt_;

    if (attack_anim_timer >= pause_time)
    {
        this->shooter_center = sf::Vector2f(this->getPosition().x+(float(0.5)*this->getGlobalBounds().width),
                                            this->getPosition().y+float(0.5)*this->getGlobalBounds().height);
        mousePos = sf::Vector2f(mousePosView);
        this->angle = get_angle(shooter_center,mousePos);

        if (element_swap>=2)
        {element_swap=0;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                chosen_element=AIR;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                chosen_element=WATER;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                chosen_element=EARTH;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                chosen_element=FIRE;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&on_cooldown>=ability_cooldown[0])
        {this->on_cooldown=0; shot = true; // BASICS
            if(chosen_element==AIR&&permission[TEMPEST])
            {
                this->projectile = new Projectile();
                this->projectile->make_tempest(&skill_textures[TEMPEST],short(TEMPEST));
                this->projectile->launchProjectile(this->shooter_center,this->mousePos);
                this->shots.push_back(projectile);

            }
            if((chosen_element==WATER)&&permission[ICECONE])
            {
                this->projectile = new Projectile();
                this->projectile->make_iceCone(&skill_textures[ICECONE],short(ICECONE));
                this->projectile->launchProjectile(this->shooter_center,this->mousePos);
                this->shots.push_back(projectile);
            }
//      if((chosen_element==EARTH)&&permission[WALL])
//        {
//            Projectile *skill = new Projectile(30.f);
//            projectile.push_back(skill);
//            projectile.back()->launchProjectile(this->shape,mousePos);
//        }
        if((chosen_element==FIRE)&&permission[FIREBALL])
        {
            this->projectile = new Projectile();
            this->projectile->make_fireball(&skill_textures[FIREBALL],short(FIREBALL));
            this->projectile->launchProjectile(this->shooter_center,this->mousePos);
            this->shots.push_back(projectile);
        }

    }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)&&on_cooldown>=ability_cooldown[1])
    {this->on_cooldown=0;  //PASSIVES
        if((chosen_element==AIR)&&permission[MS])
        {
            this->avatar_movement_speed = 900.f;
            passive_timer.first=true;
            passive_timer.second=0;
        }
        if(chosen_element==WATER&&permission[HEAL])
        {
            this->heal.first=true;
            this->heal.second=0;
            passive_timer.first=true;
            passive_timer.second=0;

        }
        if((chosen_element==EARTH)&&permission[ARMOR])
        {
            this->armor=this->HP;
            this->HP= armor+75;
            passive_timer.first=true;
            passive_timer.second=0;
        }
        if((chosen_element==FIRE)&&permission[DMG])
        {
            this->add_dmg=25;
            passive_timer.first=true;
            passive_timer.second=0;
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&on_cooldown>=ability_cooldown[2])
    {this->on_cooldown=0; this->shot=true; // SUPERS
//        if((chosen_element==AIR)||(chosen_element==BOSS))
//        {
//            Projectile *skill = new Projectile(30.f);
//            projectile.push_back(skill);
//            projectile.back()->launchProjectile(this->shape,mousePos);
//        }
//        if((chosen_element==WATER)||(chosen_element==BOSS))
//        {
//            Projectile *skill = new Projectile(30.f);
//            projectile.push_back(skill);
//            projectile.back()->launchProjectile(this->shape,mousePos);
//        }
        if((chosen_element==EARTH)&&permission[BOULDER])
        {
            this->projectile = new Projectile();
            this->projectile->make_boulder(&skill_textures[BOULDER],short(BOULDER));
            this->projectile->launchProjectile(this->shooter_center,this->mousePos);
            this->shots.push_back(projectile);

        }
//        if((chosen_element==FIRE)||(chosen_element==BOSS))
//        {
//            Projectile *skill = new Projectile(30.f);
//            projectile.push_back(skill);
//            projectile.back()->launchProjectile(this->shape,mousePos);
//        }
        }
    }
    if (shot)
    {
        this->shot=false;
        attack_anim_timer = 0;
        this->at_counter = 0;
    }

  // PASSIVE EFFECTS
    if (passive_timer.first)
    {
        passive_timer.second+=dt_;
        heal.second+=dt_;
        if (heal.first&&heal.second>=1)
        {
            this->HP+=5;
            heal.second=0;
        }
        if (passive_timer.second>=5)
        {
            this->avatar_movement_speed = 500.f;
            this->heal.first=false;
            this->add_dmg=0;
            if (HP>armor)
                this->HP=armor;
        }
    }

}

void Avatar::movement_animation()
{
    if (this->animState==IDLE)
    {
        this->setTexture(move_textures[IDLE]);
        this->setTextureRect(sf::IntRect(walkSize[IDLE].x*0,0,walkSize[IDLE].x,walkSize[IDLE].y));
//        if (this->animation_timer.getElapsedTime().asSeconds() > 0.15)
//        {
//            if (this->idle_counter>7)
//                this->idle_counter=0;
//            this->setTextureRect(sf::IntRect(walkSize[IDLE].x*idle_counter,0,walkSize[IDLE].x,walkSize[IDLE].y));
//            this->idle_counter++;
//            this->animation_timer.restart();
//        }
    }
    else if (this->animState==MOVING_UP)
    {
        this->setTexture(move_textures[MOVING_UP]);
//        this->setTextureRect(sf::IntRect(walkSize[MOVING_UP].x*idle_counter,0,walkSize[MOVING_UP].x,walkSize[MOVING_UP].y));
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.15)
        {
            if (this->up_counter>10)
                this->up_counter=0;
            this->setTextureRect(sf::IntRect(walkSize[MOVING_UP].x*up_counter,0,walkSize[MOVING_UP].x,walkSize[MOVING_UP].y));
            this->up_counter++;
            this->animation_timer.restart();
        }
    }
    else if (this->animState==MOVING_DOWN)
    {
        this->setTexture(move_textures[MOVING_DOWN]);
//        this->setTextureRect(sf::IntRect(walkSize[MOVING_DOWN].x*idle_counter,0,walkSize[MOVING_DOWN].x,walkSize[MOVING_DOWN].y));
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.15f)
        {
            if (this->down_counter>10)
                this->down_counter=0;
            this->setTextureRect(sf::IntRect(walkSize[MOVING_DOWN].x*down_counter,0,walkSize[MOVING_DOWN].x,walkSize[MOVING_DOWN].y));
            this->down_counter++;
            this->animation_timer.restart();
        }
    }
    else if (this->animState==MOVING_LEFT)
    {
        this->setTexture(move_textures[MOVING_LEFT]);
//        this->setTextureRect(sf::IntRect(walkSize[MOVING_LEFT].x*idle_counter,0,walkSize[MOVING_LEFT].x,walkSize[MOVING_LEFT].y));
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.15)
        {
            if (this->left_counter>3)
                this->left_counter=0;
            this->setTextureRect(sf::IntRect(walkSize[MOVING_LEFT].x*left_counter,0,walkSize[MOVING_LEFT].x,walkSize[MOVING_LEFT].y));
            this->left_counter++;
            this->animation_timer.restart();
        }
    }
    else if (this->animState==MOVING_RIGHT)
    {
        this->setTexture(move_textures[MOVING_RIGHT]);
//        this->setTextureRect(sf::IntRect(walkSize[MOVING_RIGHT].x*idle_counter,0,walkSize[MOVING_RIGHT].x,walkSize[MOVING_RIGHT].y));
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.15)
        {
            if (this->right_counter>3)
                this->right_counter=0;
            this->setTextureRect(sf::IntRect(walkSize[MOVING_RIGHT].x*right_counter,0,walkSize[MOVING_RIGHT].x,walkSize[MOVING_RIGHT].y));
            this->right_counter++;
            this->animation_timer.restart();
        }
    }
}

void Avatar::attack_animation()
{
    if (at_counter<5)
    {
    if (this->angle>-45 && this->angle<= 45)
    {
        this->setTexture(attack_textures[RIGHT]);
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.1 )
        {
         this->setTextureRect(sf::IntRect(attackSize[RIGHT].x*at_counter, 0,attackSize[RIGHT].x,attackSize[RIGHT].y)); //RIGHT
         this->at_counter++;
         this->animation_timer.restart();
        }
    }
    if (this->angle>-135 && this->angle<= -45)
    {
        this->setTexture(attack_textures[UP]);
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.1 )
        {
         this->setTextureRect(sf::IntRect(attackSize[UP].x*at_counter, 0,attackSize[UP].x,attackSize[UP].y)); //RIGHT
         this->at_counter++;
         this->animation_timer.restart();
        }
    }

    if (this->angle> 45 && this->angle<= 135)
    {
        this->setTexture(attack_textures[DOWN]);
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.1 )
        {
         this->setTextureRect(sf::IntRect(attackSize[DOWN].x*at_counter, 0,attackSize[DOWN].x,attackSize[DOWN].y)); //RIGHT
         this->at_counter++;
         this->animation_timer.restart();
        }
    }

    if (this->angle>135 || this->angle<=-135 )
    {
        this->setTexture(attack_textures[LEFT]);
        if (this->animation_timer.getElapsedTime().asSeconds() > 0.1 )
        {
         this->setTextureRect(sf::IntRect(attackSize[LEFT].x*at_counter, 0,attackSize[LEFT].x,attackSize[LEFT].y)); //RIGHT
         this->at_counter++;
         this->animation_timer.restart();
        }
    }

    }

}

void Avatar::animate(float dt_)
{
    for (size_t i=0; i<this->shots.size(); i++)
    {
        this->shots[i]->update_movement(dt_);
    }
    if (attack_anim_timer > pause_time)
    {
        this->steering(dt_);
     this->movement_animation();
    }
    else
        this->attack_animation();
    this->shooting(dt_);
}
