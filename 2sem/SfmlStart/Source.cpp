#include <SFML/Graphics.hpp>

size_t const kRows = 3;
size_t const kCols = 4;

sf::Color field[kRows][kCols] = {
    { sf::Color(60,0,0), sf::Color(120,0,0), sf::Color(180,0,0), sf::Color(240,0,0) },
    { sf::Color(0,60,0), sf::Color(0,120,0), sf::Color(0,180,0), sf::Color(0, 240, 0) },
    { sf::Color(0,0,60), sf::Color(0,0,120), sf::Color(0,0,180), sf::Color(0, 0, 240) }
};

size_t player_x = 0;
size_t player_y = 0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 150), "SFML works!");
    //sf::CircleShape shape(100.f);
    sf::RectangleShape rect(sf::Vector2f(50, 50));
    //sf::Clock clock;

    while (window.isOpen())
    {
        //if (clock.getElapsedTime().asMilliseconds() > 100)
        //{
        //    shift += 1;
        //    clock.restart();
        //}

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)
                    player_x -= 1;
                if (event.key.code == sf::Keyboard::Right)
                    player_x += 1;
                if (player_x < 0)
                    player_x = 0;
                if (player_x > 3)
                    player_x = 3;

                if (event.key.code == sf::Keyboard::Up)
                    player_y -= 1;
                if (event.key.code == sf::Keyboard::Down)
                    player_y += 1;
                if (player_y < 0)
                    player_y = 0;
                if (player_y > 2)
                    player_y = 2;
            }
        }

        window.clear();
        for (size_t row =0;row<kRows;++row)
            for (size_t col = 0; col < kCols; ++col)
            {
                rect.setFillColor(field[row][col]);
                rect.setPosition(sf::Vector2f(col * 50, row * 50));
                window.draw(rect);
            }

        rect.setFillColor(sf::Color::White);
        rect.setPosition(player_x * 50, player_y*50);
        window.draw(rect);

        window.display();
    }

    return 0;
}