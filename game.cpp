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
    if(!icons[AIR].loadFromFile("Textures/air.png"))
        throw "Could not load air_ground";
    if(!icons[WATER].loadFromFile("Textures/water.png"))
        throw "Could not load air_ground";
    if(!icons[EARTH].loadFromFile("Textures/earth.png"))
        throw "Could not load air_ground";
    if(!icons[FIRE].loadFromFile("Textures/fire.png"))
        throw "Could not load air_ground";
    if(!buttons[0].loadFromFile("Textures/locked.png"))
        throw "Could not load air_ground";
    if(!buttons[1].loadFromFile("Textures/mouse.png"))
        throw "Could not load air_ground";
    if(!buttons[2].loadFromFile("Textures/shift.png"))
        throw "Could not load air_ground";
    if(!buttons[3].loadFromFile("Textures/spacebar.png"))
        throw "Could not load air_ground";
  // AVATAR
    if(!avatar_walks[IDLE].loadFromFile("Textures/Avatar/Idle.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_walks[MOVING_RIGHT].loadFromFile("Textures/Avatar/goRight.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_walks[MOVING_UP].loadFromFile("Textures/Avatar/goUp.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_walks[MOVING_DOWN].loadFromFile("Textures/Avatar/goDown.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_walks[MOVING_LEFT].loadFromFile("Textures/Avatar/goLeft.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_attacks[RIGHT].loadFromFile("Textures/Avatar/RightAttack.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_attacks[UP].loadFromFile("Textures/Avatar/UpAttack.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_attacks[DOWN].loadFromFile("Textures/Avatar/DownAttack.png"))
        throw "Could not load avatar_sheet";
    if(!avatar_attacks[LEFT].loadFromFile("Textures/Avatar/LeftAttack.png"))
        throw "Could not load avatar_sheet";
  // KINGDOMS
    if(!lands[AIR].loadFromFile("Textures/Environment/AirKingdom.png"))
        throw "Could not load air_ground";
    if(!lands[WATER].loadFromFile("Textures/Environment/WaterKingdom.png"))
        throw "Could not load air_ground";
    if(!lands[EARTH].loadFromFile("Textures/Environment/EarthKingdom.png"))
        throw "Could not load air_ground";
    if(!lands[FIRE].loadFromFile("Textures/Environment/FireKingdom.png"))
        throw "Could not load air_ground";
    if(!lands[BOSS].loadFromFile("Textures/Environment/BossTemple.png"))
        throw "Could not load air_ground";
    //
    if(!backgroudns[AIR].loadFromFile("Textures/Environment/air_background.png"))
        throw "Could not load air_ground";
    if(!backgroudns[WATER].loadFromFile("Textures/Environment/water_background.png"))
        throw "Could not load air_ground";
    if(!backgroudns[EARTH].loadFromFile("Textures/Environment/earth_background.png"))
        throw "Could not load air_ground";
    if(!backgroudns[FIRE].loadFromFile("Textures/Environment/fire_background.png"))
        throw "Could not load air_ground";
    if(!backgroudns[BOSS].loadFromFile("Textures/Environment/fire_background.png"))
        throw "Could not load air_ground";
  // STORY ASPECTS
    if(!benders[0].loadFromFile("Textures/waterBender.png"))
        throw "Could not load default_enemy";
    if(!benders[1].loadFromFile("Textures/earthBender.png"))
        throw "Could not load default_enemy";
    if(!benders[2].loadFromFile("Textures/fireBender.png"))
        throw "Could not load default_enemy";
    if(!benders[3].loadFromFile("Textures/lvl_up.png"))
        throw "Could not load default_enemy";

    if(!altar_stages[0].loadFromFile("Textures/Environment/altar.png"))
        throw "Could not load air_ground";
    if(!altar_stages[1].loadFromFile("Textures/Environment/altar1.png"))
        throw "Could not load air_ground";
    if(!altar_stages[2].loadFromFile("Textures/Environment/altar2.png"))
        throw "Could not load air_ground";
    if(!altar_stages[3].loadFromFile("Textures/Environment/altar3.png"))
        throw "Could not load air_ground";
    if(!altar_stages[4].loadFromFile("Textures/Environment/altar4.png"))
        throw "Could not load air_ground";
    if(!appa_tex.loadFromFile("Textures/appa.png"))
        throw "Could not load air_ground";
  // ABILITIES
    if(!abilities[TEMPEST].loadFromFile("Textures/Abilities/Tempest.png"))
        throw "Could not load IceCone";
    if(!abilities[ICECONE].loadFromFile("Textures/Abilities/IceCone.png"))
        throw "Could not load IceCone";
    if(!abilities[STUN].loadFromFile("Textures/Abilities/Stun.png"))
        throw "Could not load fireball1";
    if(!abilities[ROCK].loadFromFile("Textures/Abilities/rock.png"))
        throw "Could not load RockBoulder";
    if(!abilities[BOULDER].loadFromFile("Textures/Abilities/RockBoulder.png"))
        throw "Could not load RockBoulder";
    if(!abilities[FIREBALL].loadFromFile("Textures/Abilities/fire_ball1.png"))
        throw "Could not load fireball1";
    if(!abilities[CIRCLE].loadFromFile("Textures/Abilities/fireCircle.png"))
        throw "Could not load fireball1";
  // ENEMIES
    if(!enemy_tex[SOLDIER].loadFromFile("Textures/Enemies/fire_soldier.png"))
        throw "Could not fire_soldier";
    if(!enemy_tex[DUMMY].loadFromFile("Textures/Enemies/TrainingDummy.png"))
        throw "Could not fire_soldier";
    if(!enemy_tex[SLIME].loadFromFile("Textures/Enemies/Slime.png"))
        throw "Could not fire_soldier";
    if(!enemy_tex[GOLEM].loadFromFile("Textures/Enemies/Golem.png"))
        throw "Could not fire_soldier";
    if(!enemy_tex[WORM].loadFromFile("Textures/Enemies/Worm.png"))
        throw "Could not fire_soldier";
    if(!enemy_tex[FIRE_LORD].loadFromFile("Textures/Enemies/Boss.png"))
        throw "Could not fire_soldier";
}
int Game::getAvatarHP(){return avatar->getHP();}

void Game::upload_waves(){}

void Game::spawn_soldiers()
{
    if(soldiers_counter<=max_soldiers)
    {
           std::shared_ptr soldier = std::make_shared<Soldier>(enemy_id,&enemy_tex[SOLDIER],&abilities[FIREBALL],mapBoarder);
            enemies.push_back(soldier);
            soldiers_counter++;
            enemy_id++;
    }
}
void Game::spawn_creatures(){}

void Game::enemy_hits(Enemy &arg_enemy)
{
    for(size_t s=0; s<arg_enemy.shotsSize(); s++) // for all enemy shots
    {
        if(avatar->hitBy(arg_enemy.bullet(s)) && !arg_enemy.matchID(s,0))
        {arg_enemy.applyDMG(s,0);
            switch(arg_enemy.enemyType())
            {
            case SOLDIER: avatar->reduceHP(5); arg_enemy.eraseShot(s); break;
            case SLIME: avatar->reduceHP(10); arg_enemy.eraseShot(s); break;
            case GOLEM: avatar->reduceHP(40); break;
            case WORM:  avatar->reduceHP(10); arg_enemy.eraseShot(s); break;
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
        for (size_t k=0; k<avatar->shotsSize(); k++) // for all avatar shots
        {
            if (enemies[j]->hitBy(avatar->bullet(k)) && !avatar->matchID(k, enemies[j]->getID()))
            { avatar->applyDMG(k,enemies[j]->getID());
                switch (avatar->shotType(k))
                {
                    case TEMPEST: enemies[j]->untrigger();
                                  enemies[j]->reduceHP(50);
                        break;
                    case ICECONE: avatar->eraseShot(k);
                                  enemies[j]->reduceHP(30);
                                  enemies[j]->root();
                        break;
                    case STUN:  enemies[j]->reduceHP(75);
                                enemies[j]->root();
                        break;
                    case ROCK: avatar->eraseShot(k);
                                enemies[j]->reduceHP(50);
                        break;
                    case BOULDER: enemies[j]->reduceHP(100);
                        break;
                    case FIREBALL: avatar->eraseShot(k);
                                   enemies[j]->reduceHP(40);
                        break;
                    case CIRCLE:   enemies[j]->reduceHP(70);
                                    if (avatar->projectileScale(k))
                                        avatar->eraseShot(k);
                        break;
                }
                if (enemies[j]->getHP()<=0)
                {
                    if (enemies[j]->enemyType()!=SOLDIER)
                        story->addDeadCreature();
                    else
                        story->addDeadSoldier();
                    dead.push_back(this->enemies[j]);
                    this->enemies.erase(this->enemies.begin()+j);
                }
            }
        }
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
        if (story->stageComplete())
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

        avatar->drawShots(*window);
        for(size_t i=0; i< enemies.size();i++)
        {
            enemies[i]->AI(deltaTime.asSeconds(),avatar->trigger_area(),*window);
            enemies[i]->drawShots(*window);
            window->draw(*enemies[i]);
        }
        for(size_t i=0; i< dead.size();i++)
        {
                enemy_hits(*dead[i]);
                dead[i]->deadShots(deltaTime.asSeconds());
                dead[i]->drawShots(*window);
                if (dead[i]->shotsLeft())
                    dead.erase(dead.begin()+i);
        }
        this->check_for_hits();

    // AVATAR STUFF
        this->avatar->animate(deltaTime.asSeconds(),*window);
        window->draw(*avatar);

    // END OF THE FRAME
        window->setView(window->getDefaultView());
        window->display();
    }
}
