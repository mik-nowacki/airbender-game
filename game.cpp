#include "game.h"

Game::Game()
{
    window=std::make_unique<sf::RenderWindow>(sf::VideoMode(1920,1080), "Avatar game!");
    this->window->setFramerateLimit(144);

    this->mapBoarder.setSize(sf::Vector2f(95.f*mapSize,95.f*mapSize));

    this->avatar_walks.resize(5);
    this->avatar_attacks.resize(4);
    this->abilities.resize(12);
    this->enemy_tex.resize(6);
    this->altar_stages.resize(5);
    this->lands.resize(5);
    this->backgroudns.resize(5);
    this->benders.resize(4);
    this->icons.resize(4);
    this->buttons.resize(4);

    this->load_textures();

    story = std::make_unique<Story>(&altar_stages, &appa_tex, &benders);
    current_kingdom = std::make_unique<Landscape>();
    avatar = std::make_unique<Avatar>(*window, mapBoarder);
    avatar->get_textures(&avatar_walks, &avatar_attacks, &abilities,&icons,&buttons);
}

void Game::load_textures()
{
  // GUI
    if(!icons[AIR].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/air.png"))
        throw "Could not load air_ground";
    if(!icons[WATER].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/water.png"))
        throw "Could not load air_ground";
    if(!icons[EARTH].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/earth.png"))
        throw "Could not load air_ground";
    if(!icons[FIRE].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/fire.png"))
        throw "Could not load air_ground";
    if(!buttons[0].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/locked.png"))
        throw "Could not load air_ground";
    if(!buttons[1].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/mouse.png"))
        throw "Could not load air_ground";
    if(!buttons[2].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/shift.png"))
        throw "Could not load air_ground";
    if(!buttons[3].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/spacebar.png"))
        throw "Could not load air_ground";
  // AVATAR
    if(!avatar_walks[IDLE].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Avatar/Idle.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_walks[MOVING_RIGHT].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Avatar/goRight.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_walks[MOVING_UP].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Avatar/goUp.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_walks[MOVING_DOWN].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Avatar/goDown.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_walks[MOVING_LEFT].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Avatar/goLeft.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_attacks[RIGHT].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Avatar/RightAttack.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_attacks[UP].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Avatar/UpAttack.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_attacks[DOWN].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Avatar/DownAttack.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_attacks[LEFT].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Avatar/LeftAttack.png"))
        throw "Could not load avatar_sheet";
  // KINGDOMS
    if(!lands[AIR].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/AirKingdom.png"))
        throw "Could not load air_ground";
    if(!lands[WATER].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/WaterKingdom.png"))
        throw "Could not load air_ground";
    if(!lands[EARTH].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/EarthKingdom.png"))
        throw "Could not load air_ground";
    if(!lands[FIRE].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/FireKingdom.png"))
        throw "Could not load air_ground";
    if(!lands[BOSS].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/BossTemple.png"))
        throw "Could not load air_ground";
    //
    if(!backgroudns[AIR].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/air_background.png"))
        throw "Could not load air_ground";
    if(!backgroudns[WATER].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/water_background.png"))
        throw "Could not load air_ground";
    if(!backgroudns[EARTH].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/earth_background.png"))
        throw "Could not load air_ground";
    if(!backgroudns[FIRE].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/fire_background.png"))
        throw "Could not load air_ground";
    if(!backgroudns[BOSS].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/fire_background.png"))
        throw "Could not load air_ground";
  // STORY ASPECTS
    if(!benders[0].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/waterBender.png"))
        throw "Could not load default_enemy";
    if(!benders[1].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/earthBender.png"))
        throw "Could not load default_enemy";
    if(!benders[2].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/fireBender.png"))
        throw "Could not load default_enemy";
    if(!benders[3].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/lvl_up.png"))
        throw "Could not load default_enemy";

    if(!altar_stages[0].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/altar.png"))
        throw "Could not load air_ground";
    if(!altar_stages[1].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/altar1.png"))
        throw "Could not load air_ground";
    if(!altar_stages[2].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/altar2.png"))
        throw "Could not load air_ground";
    if(!altar_stages[3].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/altar3.png"))
        throw "Could not load air_ground";
    if(!altar_stages[4].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Environment/altar4.png"))
        throw "Could not load air_ground";
    if(!appa_tex.loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/appa.png"))
        throw "Could not load air_ground";
  // ABILITIES
    if(!abilities[TEMPEST].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Abilities/Tempest.png"))
        throw "Could not load IceCone";
    if(!abilities[ICECONE].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Abilities/IceCone.png"))
        throw "Could not load IceCone";
    if(!abilities[STUN].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Abilities/Stun.png"))
        throw "Could not load fireball1";
    if(!abilities[ROCK].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Abilities/rock.png"))
        throw "Could not load RockBoulder";
    if(!abilities[BOULDER].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Abilities/RockBoulder.png"))
        throw "Could not load RockBoulder";
    if(!abilities[FIREBALL].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Abilities/fire_ball1.png"))
        throw "Could not load fireball1";
    if(!abilities[CIRCLE].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Abilities/fireCircle.png"))
        throw "Could not load fireball1";
  // ENEMIES
    if(!default_enemy.loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/default_enemy.png"))
        throw "Could not load default_enemy";
    if(!enemy_tex[SOLDIER].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Enemies/fire_soldier.png"))
        throw "Could not fire_soldier";
    if(!enemy_tex[DUMMY].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Enemies/TrainingDummy.png"))
        throw "Could not fire_soldier";
    if(!enemy_tex[SLIME].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Enemies/Slime.png"))
        throw "Could not fire_soldier";
    if(!enemy_tex[GOLEM].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Enemies/Golem.png"))
        throw "Could not fire_soldier";
    if(!enemy_tex[WORM].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Enemies/Worm.png"))
        throw "Could not fire_soldier";
    if(!enemy_tex[FIRE_LORD].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Enemies/Boss.png"))
        throw "Could not fire_soldier";
}
int Game::getAvatarHP(){return avatar->getHP();}

void Game::upload_waves(){}

void Game::spawn_soldiers()
{
    if(soldiers_counter<=max_soldiers)
    {
           std::shared_ptr soldier = std::make_shared<Soldier>(&enemy_tex[SOLDIER],&abilities[FIREBALL],mapBoarder);
            enemies.push_back(soldier);
            soldiers_counter++;
    }
}
void Game::spawn_creatures(){}

void Game::enemy_hits(Enemy &arg_enemy)
{
    for(size_t s=0; s<arg_enemy.shots.size(); s++) // for all enemy shots
    {
        if(arg_enemy.shots[s]->getGlobalBounds().intersects(avatar->hit_box.getGlobalBounds())&& !arg_enemy.shots[s]->id_match(0))
        {arg_enemy.shots[s]->deal(0);
            switch(arg_enemy.enemy_type)
            {
            case SOLDIER: avatar->reduceHP(10); arg_enemy.shots.erase(arg_enemy.shots.begin()+s); break;
            case SLIME: avatar->reduceHP(15); arg_enemy.shots.erase(arg_enemy.shots.begin()+s); break;
            case GOLEM: avatar->reduceHP(40); break;
            case WORM:  avatar->reduceHP(10); arg_enemy.shots.erase(arg_enemy.shots.begin()+s); break;
            case FIRE_LORD: avatar->reduceHP(35); break;
            }
        }
    }
}

void Game::check_for_hits()
{
    for (size_t j=0; j<this->enemies.size(); j++) // all enemies
    {
        enemy_hits(*enemies[j]);  // if enemy hits avatar
        for (size_t k=0; k<avatar->shots.size(); k++) // for all avatar shots
        {
            if (enemies[j]->hit_box.getGlobalBounds().intersects(avatar->shots[k]->getGlobalBounds()) && !avatar->shots[k]->id_match(j))
            { avatar->shots[k]->deal(j);
                switch (avatar->shots[k]->type)
                {
                    case TEMPEST: enemies[j]->untrigger();
                                  enemies[j]->reduceHP(25);
                        break;
                    case ICECONE: avatar->shots.erase(avatar->shots.begin()+k);
                                  enemies[j]->reduceHP(25);
                                  enemies[j]->root();
                        break;
                    case STUN:  enemies[j]->reduceHP(75);
                                enemies[j]->root();
                        break;
                    case ROCK: avatar->shots.erase(avatar->shots.begin()+k);
                                enemies[j]->reduceHP(35);
                        break;
                    case BOULDER: enemies[j]->reduceHP(100);
                        break;
                    case FIREBALL: avatar->shots.erase(avatar->shots.begin()+k);
                                   enemies[j]->reduceHP(25);
                        break;
                    case CIRCLE:   enemies[j]->reduceHP(50);
                        break;
                }
                if (enemies[j]->getHP()<=0)
                {
                    if (enemies[j]->enemy_type!=SOLDIER)
                        story->dead_creatures++;
                    else
                        story->dead_soldiers++;
                    dead.push_back(this->enemies[j]);
                    this->enemies.erase(this->enemies.begin()+j);
                }
            }
        }
    }
}
void Game::dead_shots()
{
    for (size_t j=0; j<this->dead.size(); j++) // for all dead enemies
    {
        enemy_hits(*dead[j]);
    }
}

void Game::run()
{
    current_kingdom->initializeMap(mapSize, &lands[this->stage],backgroudns[stage]);
    story->set_stage(this->stage);

    // DELTA TIME
    sf::Clock fps_clock;
///#################################################################################///
                                // GAME LOOP //
///#################################################################################///
    while (window->isOpen())
    {
     // GETTING DELTA TIME
        sf::Time deltaTime = fps_clock.restart();

    // EVENTS
        if (story->stage_complete)
                window->close();
        else if (avatar->getHP()<=0)
                window->close();

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        window->setView(avatar->getView());

        current_kingdom->drawMap(*window,*avatar);

    // STORY
        story->updateStory(deltaTime.asSeconds(),*window,*avatar);
        upload_waves();

    // SHOTS
        for (size_t i=0; i<avatar->shots.size(); i++) // draw all avatar shots
        {
            window->draw(*avatar->shots[i]);
            if(!avatar->shots[i]->getGlobalBounds().intersects(mapBoarder.getGlobalBounds()))
                avatar->shots.erase(avatar->shots.begin()+i);
        }
        for(size_t i=0; i< enemies.size();i++)
        {
            enemies[i]->AI(deltaTime.asSeconds(),avatar->trigger_area(),*window);
            window->draw(*enemies[i]);
            for(size_t j=0; j< enemies[i]->shots.size();j++)
            {
                window->draw(*enemies[i]->shots[j]);
                if(!enemies[i]->shots[j]->getGlobalBounds().intersects(mapBoarder.getGlobalBounds()))
                    enemies[i]->shots.erase(enemies[i]->shots.begin()+j);
            }
        }
        for(size_t i=0; i< dead.size();i++)
        {
            for(size_t j=0; j< dead[i]->shots.size();j++)
            {
                dead[i]->shots[j]->update_movement(deltaTime.asSeconds());
                window->draw(*dead[i]->shots[j]);
            }
        }
        this->check_for_hits();
        this->dead_shots();

    // AVATAR STUFF
        this->avatar->animate(deltaTime.asSeconds(),*window);
        window->draw(*avatar);

    // END OF THE FRAME
        window->setView(window->getDefaultView());
        window->display();
    }
}
