#include "avatar.h"

Avatar::Avatar(sf::RenderTarget &win, sf::RectangleShape &game_boarder)
{
    view.setSize(win.getSize().x,win.getSize().y);
    view.setCenter(win.getSize().x/2.f,win.getSize().y/2.f);
    this->setPosition(start_pos);
    this->hit_box.setSize(sf::Vector2f(40.f,90.f));

    this->shoot_timer=0.5;
    this->map_edge=game_boarder;
    this->trigger_area_.setSize(sf::Vector2f(900.f,900.f));
//    this->trigger_area_.setFillColor(sf::Color::Transparent);
//    this->trigger_area_.setOutlineThickness(3.f);
//    this->trigger_area_.setOutlineColor(sf::Color::Green);
    this->trigger_area_.setPosition(start_pos-sf::Vector2f(400.f,400.f));

    this->walkSize.resize(5);
    this->attackSize.resize(5);

    this->setScale(2.5,2.5);
    this->animation_timer.restart();

 // SETTING UP GUI
    this->HP=100;
    this->mana=100;
    HPbar.setSize(sf::Vector2f(this->HP*5,50.f));
    HPbar.setFillColor(sf::Color::Red);

    ManaBar.setSize(sf::Vector2f(this->mana*5,50.f));
    ManaBar.setFillColor(sf::Color::Cyan);

    HPback.setSize(sf::Vector2f(this->HP*5,50.f));
    HPback.setFillColor(sf::Color(25,25,25,200));

    Manaback.setSize(sf::Vector2f(this->mana*5,50.f));
    Manaback.setFillColor(sf::Color(25,25,25,200));

    this->chosen_element=AIR;

    icon.setScale(0.7f,0.7f);
}
void Avatar::updateGUI(sf::RenderTarget &win)
{
    skill1.setTexture(buttons[1]);
    skill1.setScale(1.f,1.f);
    skill2.setTexture(buttons[2]);
    skill2.setScale(0.3f,0.3f);
    skill3.setTexture(buttons[3]);
    skill3.setScale(0.35f,0.35f);

    HPbar.setPosition(this->view.getCenter().x-950,this->view.getCenter().y+390);
    ManaBar.setPosition(this->view.getCenter().x-950,this->view.getCenter().y+450);
    HPback.setPosition(this->view.getCenter().x-950,this->view.getCenter().y+390);
    Manaback.setPosition(this->view.getCenter().x-950,this->view.getCenter().y+450);

    HPbar.setSize(sf::Vector2f(this->HP*5,50.f));
    ManaBar.setSize(sf::Vector2f(this->mana*5,50.f));

    icon.setPosition(this->view.getCenter().x-350,this->view.getCenter().y+385);
    skill1.setPosition(this->view.getCenter().x-190,this->view.getCenter().y+390);
    skill2.setPosition(this->view.getCenter().x-135,this->view.getCenter().y+390);
    skill3.setPosition(this->view.getCenter().x,this->view.getCenter().y+400);

    switch (this->chosen_element)
    {
        case AIR: icon.setTexture(icons[AIR]); break;
        case WATER: icon.setTexture(icons[WATER]); break;
        case EARTH: icon.setTexture(icons[EARTH]); break;
        case FIRE: icon.setTexture(icons[FIRE]); break;
    }

    if (ability_cooldown[0]<1)
    {
        skill1.setTexture(buttons[0]);
        skill1.setScale(0.1f,0.1f);
    }
    if (ability_cooldown[1]<10)
    {
        skill2.setTexture(buttons[0]);
    }
    if (ability_cooldown[2]<15)
    {
        skill3.setTexture(buttons[0]);
    }

    win.draw(HPback);
    win.draw(HPbar);
    win.draw(Manaback);
    win.draw(ManaBar);
    win.draw(icon);
    win.draw(skill1);
    win.draw(skill2);
    win.draw(skill3);
}

sf::RectangleShape Avatar::trigger_area()
{
    return trigger_area_;
}

sf::View Avatar::getView()
{
    return view;
}

void Avatar::get_textures(std::vector<sf::Texture> *mv_game, std::vector<sf::Texture> *at_game,
                          std::vector<sf::Texture> *sk_game, std::vector<sf::Texture> *ic_game,std::vector<sf::Texture> *bt_game)
{
    move_textures = *mv_game;
    attack_textures = *at_game;
    skill_textures=*sk_game;
    icons = *ic_game;
    buttons= *bt_game;

    for(size_t mv = 0; mv<mv_game->size(); mv++)
    {
        walkSize[mv] = move_textures[mv].getSize();
    }
    walkSize[IDLE].x /= 8;
    walkSize[MOVING_DOWN].x /= 10;
    walkSize[MOVING_UP].x /=11;
    walkSize[MOVING_LEFT].x /= 4;
    walkSize[MOVING_RIGHT].x /= 4;
    for(size_t at = 0; at<at_game->size(); at++)
    {
        attackSize[at] = attack_textures[at].getSize();
        attackSize[at].x /= 5;
    }
    this->animState = IDLE;
    skill1.setTexture(buttons[1]);
    skill2.setTexture(buttons[2]);
    skill2.setScale(0.3f,0.3f);
    skill3.setTexture(buttons[3]);
    skill3.setScale(0.35f,0.35f);
}
void Avatar::steering(float dt_)
{
    this->animState = IDLE;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->move(0,-avatar_movement_speed*dt_);
        view.move(0,-avatar_movement_speed*dt_);
        this->animState = MOVING_UP;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(0,avatar_movement_speed*dt_);
        view.move(0,avatar_movement_speed*dt_);
        this->animState = MOVING_DOWN;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->move(-avatar_movement_speed*dt_,0);
        view.move(-avatar_movement_speed*dt_,0);
        this->animState = MOVING_LEFT;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(avatar_movement_speed*dt_,0);
        view.move(avatar_movement_speed*dt_,0);
        this->animState = MOVING_RIGHT;
    }
    // if player is outside the map //
    if (hit_box.getPosition().x<0 ) // push right
    {
        this->move(avatar_movement_speed*dt_,0);
        view.move(avatar_movement_speed*dt_,0);
    }
    else if (hit_box.getPosition().y<0) // push down
    {
        this->move(0,avatar_movement_speed*dt_);
        view.move(0,avatar_movement_speed*dt_);
    }
    else if (hit_box.getPosition().x+hit_box.getGlobalBounds().width>map_edge.getGlobalBounds().width)  // push left
    {
        this->move(-avatar_movement_speed*dt_,0);
        view.move(-avatar_movement_speed*dt_,0);
    }
    else if (hit_box.getPosition().y+hit_box.getGlobalBounds().height>map_edge.getGlobalBounds().height) // push up
    {
        this->move(0,-avatar_movement_speed*dt_);
        view.move(0,-avatar_movement_speed*dt_);
    }

    this->trigger_area_.setPosition(getPosition()-sf::Vector2f(400.f,400.f));
    this->hit_box.setPosition(sf::Vector2f(this->getPosition().x+20.f,this->getPosition().y));
}

void Avatar::shooting(float dt_)
{
    this->attack_anim_timer+=dt_;
    this->element_swap+=dt_;
    if (mana<=100)
        this->mana+=10*dt_;
    for (auto &cd : ability_cooldown)
    {
        cd+=dt_;
    }

    if (attack_anim_timer >= pause_time)
    {
        this->shooter_center = sf::Vector2f(this->getPosition().x+(float(0.5)*this->getGlobalBounds().width),
                                            this->getPosition().y+float(0.5)*this->getGlobalBounds().height);
        mousePos = sf::Vector2f(mousePosView);
        this->angle = get_angle(shooter_center,mousePos);

        if (element_swap>=1)
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

        if (mana>=15)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&ability_cooldown[0]>=1)
            {this->ability_cooldown[0]=0; this->mana-=15; shot = true; // BASICS
                if(chosen_element==AIR&&permission[TEMPEST])
                {
                    projectile = std::make_unique<Projectile>();
                    projectile->make_tempest(&skill_textures[TEMPEST],short(TEMPEST));
                    projectile->launchProjectile(this->shooter_center,this->mousePos);
                    shots.push_back(std::move(projectile));

                }
                if((chosen_element==WATER)&&permission[ICECONE])
                {
                    projectile = std::make_unique<Projectile>();
                    projectile->make_iceCone(&skill_textures[ICECONE],short(ICECONE));
                    projectile->launchProjectile(this->shooter_center,this->mousePos);
                    this->shots.push_back(std::move(projectile));
                }
                if((chosen_element==EARTH)&&permission[ROCK])
                {
                    projectile = std::make_unique<Projectile>();
                    projectile->make_rock(&skill_textures[ROCK],short(ROCK));
                    projectile->launchProjectile(this->shooter_center,this->mousePos);
                    this->shots.push_back(std::move(projectile));
                }
                if((chosen_element==FIRE)&&permission[FIREBALL])
                {
                    for (int i =0; i<=add_dmg; i++)
                    {
                        projectile = std::make_unique<Projectile>();
                        projectile->make_fireball(&skill_textures[FIREBALL],short(FIREBALL));
                        projectile->launchProjectile(this->shooter_center,this->mousePos);
                        this->shots.push_back(std::move(projectile));
                    }
                }

            }
        }
        if (mana>=30)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)&&ability_cooldown[1]>=10)
            {this->ability_cooldown[1]=0; this->mana-=30;  //PASSIVES
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
                    this->armor = this->HP;
                    this->HP= armor+75;
                    passive_timer.first=true;
                    passive_timer.second=0;
                }
                if((chosen_element==FIRE)&&permission[DMG])
                {
                    this->add_dmg=1;
                    passive_timer.first=true;
                    passive_timer.second=0;
                }
            }
        }
        if (mana>=50)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&ability_cooldown[2]>=15)
            {this->ability_cooldown[2]=0; this->mana-=50; this->shot=true; // SUPERS
                if((chosen_element==AIR)&&permission[CDR])
                {
                    this->ability_cooldown[0]+=1;
                    this->ability_cooldown[1]+=8;
                    this->ability_cooldown[2]+=15;
                    this->element_swap = 2;
                    this->mana=100;
                }
                if((chosen_element==WATER)&&permission[STUN])
                {
                    projectile = std::make_unique<Projectile>();
                    projectile->make_boulder(&skill_textures[STUN],short(STUN));
                    projectile->launchProjectile(this->shooter_center,this->mousePos);
                    this->shots.push_back(std::move(projectile));

                }
                if((chosen_element==EARTH)&&permission[BOULDER])
                {
                    projectile = std::make_unique<Projectile>();
                    projectile->make_boulder(&skill_textures[BOULDER],short(BOULDER));
                    projectile->launchProjectile(this->shooter_center,this->mousePos);
                    this->shots.push_back(std::move(projectile));

                }
                if((chosen_element==FIRE)&&permission[CIRCLE])
                {
                    projectile = std::make_unique<FireCircle>(&skill_textures[CIRCLE],short(CIRCLE));
                    projectile->launchProjectile(this->shooter_center,this->mousePos);
                    this->shots.push_back(std::move(projectile));
                }
            }
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
        if ((heal.first&&heal.second>=1)&&(this->HP<100))
        {
            this->HP+=10;
            heal.second=0;
        }
        if (passive_timer.second>=5)
        {
            this->avatar_movement_speed = 500.f;
            this->heal.first=false;
            this->add_dmg=0;
            if (HP>armor) // reduce any excess HP
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
            if (this->up_counter>11)
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

void Avatar::animate(float dt_, sf::RenderWindow &win)
{
    mousePosView=win.mapPixelToCoords(sf::Mouse::getPosition(win));

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
    this->updateGUI(win);
}
