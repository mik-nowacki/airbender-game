#include "game.h"

Game::Game()
{
    window=new sf::RenderWindow(sf::VideoMode(1920,1080), "Avatar game!");
    this->window->setFramerateLimit(144);
}

void Game::shooting(Projectile &bullet, std::vector<Enemy> &enemies)
{
    playerCenter = sf::Vector2f(landscape.avatar.rectangle.getPosition().x+(0.5*landscape.avatar.rectangle.getGlobalBounds().width),landscape.avatar.rectangle.getPosition().y+0.5*landscape.avatar.rectangle.getGlobalBounds().height);
    mousePos = sf::Vector2f(mousePosView);
    aimDirection = mousePos-playerCenter;
    aimDirNorm = aimDirection / sqrt(powf(aimDirection.x,2)+powf(aimDirection.y,2));


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        bullet.shape.setPosition(playerCenter);
        bullet.speedVector=aimDirNorm*bullet.maxSpeed;

        shots.emplace_back(bullet);
    }
    for(size_t i =0; i<shots.size(); i++)
    {
        shots[i].shape.move(shots[i].speedVector);
    }
    for(size_t i =0; i<shots.size();i++)
    {
        for(size_t k =0; k<enemies.size();k++)
        if(shots[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
        {
            shots.erase(shots.begin()+i);
            enemies.erase(enemies.begin()+k);

        }
    }
}

void Game::run()
{

    landscape.avatar.rectangle.setPosition(landscape.avatar.view.getCenter());

    unsigned gridSizeu=static_cast<unsigned>(gridSizef);

    Projectile *bullet= new Projectile;

    //VIEW

    landscape.avatar.view.setSize(window->getSize().x,window->getSize().y);
    landscape.avatar.view.setCenter(window->getSize().x/2.f,window->getSize().y/2.f);

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
///#################################################################################///
                                // GAME LOOP //
///#################################################################################///

    while (window->isOpen())
    {

    // MOUSE POSITION
        mousePosScreen=sf::Mouse::getPosition();
        mousePosWindow=sf::Mouse::getPosition(*window);
        window->setView(landscape.avatar.view);
        mousePosView=window->mapPixelToCoords(mousePosWindow);
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
        window->setView(landscape.avatar.view);

        landscape.renderMap();

        for (int x=landscape.fromX;x<landscape.toX;x++)
        {
            for (int y=landscape.fromY; y<landscape.toY;y++)
            {
                window->draw(landscape.tileMap[x][y]);
            }

        }

    // NEEDS CLEARENCE
        window->setView(landscape.avatar.view);

        window->draw(tileSelector);

    // SPAWN ENEMIES

        if(spawnCounter<20)
            spawnCounter++;
        if(spawnCounter>=20 && enemies.size() < 100)
        {
            Enemy enemy;
            enemies.emplace_back(enemy);
            spawnCounter=0;
        }

        for (auto &i : enemies)
        {
           window->draw(i.sprite);
        }

        shooting(*bullet, enemies);
        landscape.avatar.steering();
        for(auto &i : shots)
        {
            window->draw(i.shape);
        }
        window->draw(landscape.avatar.rectangle);

        window->setView(window->getDefaultView());
        window->display();
    }
}
