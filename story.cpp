#include "story.h"

Story::Story(std::vector<sf::Texture> *tex, sf::Texture *appa_game, std::vector<sf::Texture> *land_tex)
{
    this->altar.setPosition(sf::Vector2f(1000.f,1000.f));
    this->texture = *tex;
    this->altar.setTexture(texture[0]);
    this->altar.setScale(2.f,2.f);
    this->altar_hb.setRadius(200.f);
    this->altar_hb.setPosition(this->altar.getPosition());

    this->appa.setTexture(*appa_game);
    this->appa.setScale(3.f,3.f);
    this->appa.setPosition(1500.f,100.f);

    new_kingdom = *land_tex;
}

void Story::capturing(const float &dt_, sf::RectangleShape &player)
{
    if (unlocked&&!is_captured)
    {
        if (this->altar_hb.getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            capture_time+=dt_;
            std::cout<<capture_time<<std::endl;

            if (capture_time>=5&&capture_time<10)
                this->altar.setTexture(texture[1]);
            else if (capture_time>=10&&capture_time<15)
                this->altar.setTexture(texture[2]);
            else if (capture_time>=15&&capture_time<19.8)
                this->altar.setTexture(texture[3]);
            else if (capture_time >=19.8)
                this->altar.setTexture(texture[4]);
        }
        else
        {
            this->capture_time=0;
            this->altar.setTexture(texture[0]);
        }

        if (capture_time>=20)
            is_captured = true;
    }
}

void Story::updateStory(const float &game_dt, sf::RenderTarget &game_window,sf::RectangleShape &game_player)
{
    this->capturing(game_dt, game_player);
    if (this->is_captured)
    {
        game_window.draw(appa);

        if (game_player.getGlobalBounds().intersects(appa.getGlobalBounds()))
            this->stage_complete=true;
    }
    game_window.draw(altar);
//    game_window.draw(altar_hb);
}

void Story::updateQuests()
{

}
