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

void Story::capturing(const float &dt_, const sf::RectangleShape &player)
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
                on_appa=true;
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
        if (!player.if_unlocked(ICECONE))
        { game_window.draw(text);
            if (player.hitBy(this->bender))
                player.unlock(ICECONE);
        }
        else if (!player.if_unlocked(HEAL)&&dead_creatures>=5)
        { game_window.draw(text);
            if (player.hitBy(this->bender))
                player.unlock(HEAL);
        }
        else if (!player.if_unlocked(STUN)&&dead_creatures>=10)
        { game_window.draw(text);
            if (player.hitBy(this->bender))
                player.unlock(STUN);
        }
        break;
    case EARTH:
        if (!player.if_unlocked(ROCK))
        { game_window.draw(text);
            if (player.hitBy(this->bender))
                player.unlock(ROCK);
        }
        else if (!player.if_unlocked(ARMOR)&&dead_creatures>=2)
        { game_window.draw(text);
            if (player.hitBy(this->bender))
                player.unlock(ARMOR);
        }
        else if (!player.if_unlocked(BOULDER)&&dead_creatures>=5)
        { game_window.draw(text);
            if (player.hitBy(this->bender))
                player.unlock(BOULDER);
        }
        break;
    case FIRE:
        if (!player.if_unlocked(FIREBALL))
        { game_window.draw(text);
            if (player.hitBy(this->bender))
                player.unlock(FIREBALL);
        }
        else if (!player.if_unlocked(DMG)&&dead_creatures>=5)
        { game_window.draw(text);
            if (player.hitBy(this->bender))
                player.unlock(DMG);
        }
        else if (!player.if_unlocked(CIRCLE)&&dead_creatures>=10)
        { game_window.draw(text);
            if (player.hitBy(this->bender))
                player.unlock(CIRCLE);
        }
        break;
    case BOSS:
        if (!player.if_unlocked(CIRCLE)) // just in case this won't initiate infinite times
            for (short lck=TEMPEST; lck<12; lck++)
            {player.unlock(lck);}
        break;
    }
}

bool Story::stageComplete()
{
    return on_appa;
}

void Story::addDeadCreature()
{
    dead_creatures++;
}
void Story::addDeadSoldier()
{
    dead_soldiers++;
}

int Story::creaturesSlain()
{
    return dead_creatures;
}
int Story::soldiersKilled()
{
    return dead_soldiers;
}

void Story::updateStory(const float &game_dt, sf::RenderTarget &game_window,Avatar &player)
{
    this->updateQuests(player,game_window);
    this->capturing(game_dt, player.hitBox());
    if (this->is_captured)
    {
        game_window.draw(appa);

        if (player.hitBy(appa))
            this->on_appa=true;
    }
    game_window.draw(altar);
}


