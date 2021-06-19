#include "story.h"

Story::Story(std::vector<sf::Texture> *tex, sf::Texture *appa_game, std::vector<sf::Texture> *bend_tex)
{
    this->bender.setPosition(sf::Vector2f(800.f,10.f));
    this->benders=*bend_tex;
    this->text.setPosition(sf::Vector2f(700.f,-50));
    this->text.setTexture(benders.back());

    this->altar.setPosition(sf::Vector2f(1000.f,1000.f));
    this->texture = *tex;
    this->altar.setTexture(texture[0]);
    this->altar.setScale(2.f,2.f);
    this->altar_hb.setRadius(200.f);
    this->altar_hb.setPosition(this->altar.getPosition());

    this->appa.setTexture(*appa_game);
    this->appa.setScale(3.f,3.f);
    this->appa.setPosition(1500.f,100.f);

}

void Story::set_stage(short &stage)
{
    current_stage=stage;  // used in other methods
    switch (current_stage)
    {
        case WATER: this->bender.setTexture(benders[0]);
                    this->bender.setScale(0.25f,0.25f); break;
        case EARTH: this->bender.setTexture(benders[1]);
                    this->bender.setScale(0.35f,0.35f); break;
        case FIRE:  this->bender.setTexture(benders[2]);
                    this->bender.setScale(1.1f,1.1f);break;
    }
}

void Story::capturing(const float &dt_, sf::RectangleShape &player)
{
    if (dead_soldiers>=7)
        unlocked=true;
    else if (current_stage==BOSS&&dead_creatures>=1)
        unlocked=true;
    if (unlocked&&!is_captured)
    {
        if (this->altar_hb.getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            capture_time+=dt_;
            std::cout<<capture_time<<std::endl;

            if (capture_time>=2.5&&capture_time<5)
                this->altar.setTexture(texture[1]);
            else if (capture_time>=5&&capture_time<7.5)
                this->altar.setTexture(texture[2]);
            else if (capture_time>=7.5&&capture_time<9.8)
                this->altar.setTexture(texture[3]);
            else if (capture_time >=9.8)
                this->altar.setTexture(texture[4]);
            if (current_stage==BOSS)
                stage_complete=true;
        }
        else
        {
            this->capture_time=0;
            this->altar.setTexture(texture[0]);
        }
        if (capture_time>=10)
            is_captured = true;
    }
}

void Story::updateQuests(Avatar &player,sf::RenderTarget &game_window)
{
        game_window.draw(bender);

        switch (current_stage)
        {
        case WATER:
            if (!player.permission[ICECONE])
            { game_window.draw(text);
                if (player.hit_box.getGlobalBounds().intersects(this->bender.getGlobalBounds()))
                    player.permission[ICECONE]=true;
            }
            else if (!player.permission[HEAL]&&dead_creatures>=5)
            { game_window.draw(text);
                if (player.hit_box.getGlobalBounds().intersects(this->bender.getGlobalBounds()))
                    player.permission[HEAL]=true;
            }
            else if (!player.permission[STUN]&&dead_creatures>=10)
            { game_window.draw(text);
                if (player.hit_box.getGlobalBounds().intersects(this->bender.getGlobalBounds()))
                    player.permission[STUN]=true;
            }
            break;
        case EARTH:
            if (!player.permission[ROCK])
            { game_window.draw(text);
                if (player.hit_box.getGlobalBounds().intersects(this->bender.getGlobalBounds()))
                    player.permission[ROCK]=true;
            }
            else if (!player.permission[ARMOR]&&dead_creatures>=2)
            { game_window.draw(text);
                if (player.hit_box.getGlobalBounds().intersects(this->bender.getGlobalBounds()))
                    player.permission[ARMOR]=true;
            }
            else if (!player.permission[BOULDER]&&dead_creatures>=5)
            { game_window.draw(text);
                if (player.hit_box.getGlobalBounds().intersects(this->bender.getGlobalBounds()))
                    player.permission[BOULDER]=true;
            }
            break;
        case FIRE:
            if (!player.permission[FIREBALL])
            { game_window.draw(text);
                if (player.hit_box.getGlobalBounds().intersects(this->bender.getGlobalBounds()))
                    player.permission[FIREBALL]=true;
            }
            else if (!player.permission[DMG]&&dead_creatures>=5)
            { game_window.draw(text);
                if (player.hit_box.getGlobalBounds().intersects(this->bender.getGlobalBounds()))
                    player.permission[DMG]=true;
            }
            else if (!player.permission[CIRCLE]&&dead_creatures>=10)
            { game_window.draw(text);
                if (player.hit_box.getGlobalBounds().intersects(this->bender.getGlobalBounds()))
                    player.permission[CIRCLE]=true;
            }
            break;
        case BOSS:
            if (!player.permission[CIRCLE]) // just in case this won't initiate infinite times
            for (auto unlock : player.permission)
            {unlock=true;}
            break;
    }
}

void Story::updateStory(const float &game_dt, sf::RenderTarget &game_window,Avatar &player)
{
    this->updateQuests(player,game_window);
    this->capturing(game_dt, player.hit_box);
    if (this->is_captured)
    {
        game_window.draw(appa);

        if (player.hit_box.getGlobalBounds().intersects(appa.getGlobalBounds()))
            this->stage_complete=true;
    }
    game_window.draw(altar);
}


