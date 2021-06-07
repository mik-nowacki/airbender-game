#include "game.h"

Game::Game()
{
    window=new sf::RenderWindow(sf::VideoMode(1920,1080), "Avatar game!");
    this->window->setFramerateLimit(144);

    this->mapBoarder.setSize(sf::Vector2f(85.f*mapSize,85.f*mapSize));
    this->mapBoarder.setPosition(gridSizef,gridSizef);

    //    this->mapBoarder.setOutlineColor(sf::Color::Green); // TEMPORARY!
    //    this->mapBoarder.setOutlineThickness(5.f);          // TEMPORARY!

    this->avatar_walks.resize(5);
    this->avatar_attacks.resize(4);
    this->abilities.resize(12);
    this->enemy_tex.resize(5);
    this->altar_stages.resize(5);
    this->lands.resize(5);

    this->load_textures();

    story = new Story(&altar_stages, &appa_tex, &lands);

    current_kingdom = new Landscape();
//    altar = new Altar(&altar_stages);

    avatar = new Avatar(mapBoarder);
    avatar->get_textures(&avatar_walks, &avatar_attacks, &abilities);

}

void Game::load_textures()
{
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
  // STORY ASPECTS
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
    if(!abilities[BOULDER].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Abilities/RockBoulder.png"))
        throw "Could not load RockBoulder";
    if(!abilities[FIREBALL].loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/Abilities/fire_ball1.png"))
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
}

void Game::spawn_environment()
{

}

void Game::spawn_soldiers()
{
    if(soldiers_counter<=max_soldiers)
    {
            Soldier *soldier = new Soldier(&enemy_tex[SOLDIER],&abilities[FIREBALL],mapBoarder);
            enemies.push_back(soldier);
            soldiers_counter++;
    }

}

void Game::spawn_creatures()
{

}


void Game::enemy_hits(Enemy &arg_enemy)
{
    for(size_t s=0; s<arg_enemy.shots.size(); s++) // for all enemy shots
    {
        if((arg_enemy.shots[s]->getGlobalBounds().intersects(avatar->hit_box.getGlobalBounds()))
            ||(!arg_enemy.shots[s]->getGlobalBounds().intersects(mapBoarder.getGlobalBounds())))
            arg_enemy.shots.erase(arg_enemy.shots.begin()+s);
    }
}

void Game::check_for_hits()
{
    for (size_t j=0; j<this->enemies.size(); j++) // all enemies
    {
        enemy_hits(*enemies[j]);
        for (size_t k=0; k<avatar->shots.size(); k++) // for all avatar shots
        {
            if (this->enemies[j]->getGlobalBounds().intersects(avatar->shots[k]->getGlobalBounds()))
            {
                switch (this->enemies[j]->enemy_type)
                {
                case DUMMY: dead_creatures++; break;
                case SLIME: dead_creatures++; break;
                }
//                switch (avatar->shots[k]->type)
//                {
////                    case MELEE: shots.erase
//                }
                delete(avatar->shots[k]);
                avatar->shots.erase(avatar->shots.begin()+k);
                dead.push_back(this->enemies[j]);               // goes to shadow realm
                this->enemies.erase(this->enemies.begin()+j);
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
    current_kingdom->initializeMap(mapSize, &lands[this->stage]);

    unsigned gridSizeu=static_cast<unsigned>(gridSizef);

    //VIEW
    avatar->view.setSize(window->getSize().x,window->getSize().y);
    avatar->view.setCenter(window->getSize().x/2.f,window->getSize().y/2.f);

    // TILE SELECTOR
    sf::RectangleShape tileSelector(sf::Vector2f(gridSizef,gridSizef));
    tileSelector.setFillColor(sf::Color::Transparent);
    tileSelector.setOutlineThickness(1.f);
    tileSelector.setOutlineColor(sf::Color::Green);

    // DELTA TIME
    sf::Clock fps_clock;
///#################################################################################///
                                // GAME LOOP //
///#################################################################################///

    while (window->isOpen())
    {
     // GETTING DELTA TIME
        sf::Time deltaTime = fps_clock.restart();

    // MOUSE POSITION
        mousePosScreen=sf::Mouse::getPosition();
        mousePosWindow=sf::Mouse::getPosition(*window);

//        avatar->mousePosScreen=sf::Mouse::getPosition();
//        avatar->mousePosWindow=sf::Mouse::getPosition(*window);

        window->setView(avatar->view);

        mousePosView=window->mapPixelToCoords(mousePosWindow);
        avatar->mousePosView=window->mapPixelToCoords(mousePosWindow);

    // TILE SELECTOR
        if(mousePosView.x>=0.f)
        mousePosGrid.x = mousePosView.x / gridSizeu;
        if(mousePosView.y>=0.f)
        mousePosGrid.y = mousePosView.y / gridSizeu;

        tileSelector.setPosition(mousePosGrid.x*gridSizef,mousePosGrid.y*gridSizef);

//          std::cout << "Screen: " << mousePosScreen.x<<" "<<mousePosScreen.y<<std::endl
//                    << "Window: " << mousePosWindow.x<<" "<<mousePosWindow.y<<std::endl
//                    << "View: " << mousePosView.x<<" "<<mousePosView.y<<std::endl
//                    << "Grid: " << mousePosGrid.x<<" "<<mousePosGrid.y<<std::endl;
    // EVENTS
        if (story->stage_complete)
                window->close();

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        window->setView(avatar->view);

    // DRAW MAP
//        window->draw(mapBoarder);  // TEMPORARY!

        window->draw(tileSelector);
        current_kingdom->renderMap(*avatar);

        for (int x=current_kingdom->fromX;x<current_kingdom->toX;x++)
        {
            for (int y=current_kingdom->fromY; y<current_kingdom->toY;y++)
            {
                window->draw(current_kingdom->tileMap[x][y]);
            }
        }

    // STORY
        story->updateStory(deltaTime.asSeconds(),*window,avatar->hit_box);

    // DRAW ENEMIES
        spawn_creatures();
        spawn_soldiers();
        switch (stage)
        {
        case AIR: if(dead_creatures>max_creatures)
                    spawn_soldiers();
            break;
        case WATER: if(dead_creatures>10)
                    spawn_soldiers();
            break;
        case EARTH: if(dead_creatures>5)
                    spawn_soldiers();
            break;
        case FIRE: if(dead_creatures>7)
                    spawn_soldiers();
            break;
        }

    // SHOTS
        for (size_t i=0; i<avatar->shots.size(); i++) // draw all avatar shots
        {
            if(!avatar->shots[i]->getGlobalBounds().intersects(mapBoarder.getGlobalBounds()))
                avatar->shots.erase(avatar->shots.begin()+i);
            window->draw(*avatar->shots[i]);
        }
        for(size_t i=0; i< enemies.size();i++)
        {
            enemies[i]->AI(deltaTime.asSeconds(),avatar->trigger_area);
            window->draw(*enemies[i]);
            for(size_t j=0; j< enemies[i]->shots.size();j++)
            {
                window->draw(*enemies[i]->shots[j]);
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
        this->avatar->animate(deltaTime.asSeconds());
//        window->draw(avatar->trigger_area);
        window->draw(*avatar);

    // END OF THE FRAME
        window->setView(window->getDefaultView());
        window->display();
    }
}
