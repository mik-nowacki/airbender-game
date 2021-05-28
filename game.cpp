#include "game.h"

Game::Game()
{
    window=new sf::RenderWindow(sf::VideoMode(1920,1080), "Avatar game!");
    this->window->setFramerateLimit(144);
}

void Game::run()
{
    Avatar avatar;
//    avatar.animate();
    Landscape landscape(gridSizef);

    avatar.shape.setPosition(avatar.view.getCenter());
//    landscape.gridSizef_=gridSizef;

    unsigned gridSizeu=static_cast<unsigned>(gridSizef);

    Projectile *bullet= new Projectile;

    //VIEW

    avatar.view.setSize(window->getSize().x,window->getSize().y);
    avatar.view.setCenter(window->getSize().x/2.f,window->getSize().y/2.f);

    // TILE SELECTOR

    sf::RectangleShape tileSelector(sf::Vector2f(gridSizef,gridSizef));
    tileSelector.setFillColor(sf::Color::Transparent);
    tileSelector.setOutlineThickness(1.f);
    tileSelector.setOutlineColor(sf::Color::Green);

    // RECTANGLES TO GRID MAP

    landscape.initializeMap();

    // ENEMIES

//    std::vector<sf::RectangleShape> enemies;
//    enemy->setSize(sf::Vector2f(gridSizef,gridSizef));
//    enemy->setPosition(500.f,100.f);
//    enemy->setFillColor(sf::Color::Red);

    int spawnCounter = 20;

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

        avatar.mousePosScreen=sf::Mouse::getPosition();
        avatar.mousePosWindow=sf::Mouse::getPosition(*window);

        window->setView(avatar.view);

        mousePosView=window->mapPixelToCoords(mousePosWindow);
        avatar.mousePosView=window->mapPixelToCoords(mousePosWindow);
        if(mousePosView.x>=0.f)
        mousePosGrid.x = mousePosView.x / gridSizeu;
        if(mousePosView.y>=0.f)
        mousePosGrid.y = mousePosView.y / gridSizeu;

//        window->setView(window->getDefaultView());

    // TILE SELECTOR

        tileSelector.setPosition(mousePosGrid.x*gridSizef,mousePosGrid.y*gridSizef);

          std::cout << "Screen: " << mousePosScreen.x<<" "<<mousePosScreen.y<<std::endl
                    << "Window: " << mousePosWindow.x<<" "<<mousePosWindow.y<<std::endl
                    << "View: " << mousePosView.x<<" "<<mousePosView.y<<std::endl
                    << "Grid: " << mousePosGrid.x<<" "<<mousePosGrid.y<<std::endl;
    // EVENTS

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        window->setView(avatar.view);

    // DRAW MAP

        landscape.renderMap(avatar);

        for (int x=landscape.fromX;x<landscape.toX;x++)
        {
            for (int y=landscape.fromY; y<landscape.toY;y++)
            {
                window->draw(landscape.tileMap[x][y]);
            }
        }

        window->draw(tileSelector);

    // SPAWN & DRAW ENEMIES

        if(spawnCounter<20)
            spawnCounter++;
        if(spawnCounter>=20 && enemies.size() < 100)
        {
            enemies.emplace_back(enemy);
            spawnCounter=0;
        }

        for (auto &i : enemies)
        {
           window->draw(i.shape);
        }

    // DRAW AVATAR

        avatar.shooting(*bullet, enemies, deltaTime.asSeconds());
        avatar.animate(deltaTime.asSeconds());
        for(auto &i : avatar.shots)
        {
            window->draw(i.shape);
        }
        window->draw(avatar.sprite);

        window->setView(window->getDefaultView());
        window->display();
    }
}
