#include <SFML/Graphics.hpp>

sf::Color field[3][4] = {
    {sf::Color(60,0,0),sf::Color(120,0,0),sf::Color(180,0,0),sf::Color(240,0,0)},
    {sf::Color(0,60,0),sf::Color(0,120,0),sf::Color(0,180,0),sf::Color(0,240,0)},
    {sf::Color(0,0,60),sf::Color(0,0,120),sf::Color(0,0,180),sf::Color(0,0,240)}
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 150), "SFML works!");
    sf::RectangleShape shape(sf::Vector2f(50.f, 50.f));
    //sf::Clock clock;
    float shift = 0;
    while (window.isOpen())
    {
    /*    if (clock.getElapsedTime().asMilliseconds() > 100)
        {
            shift += 1;
            clock.restart();
        }*/
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)
                {
                    shift -= 1;
                }

                if (event.key.code == sf::Keyboard::Right)
                {
                    shift += 1;
                }
            }
        }

        window.clear();
        for (size_t row=0;row<3;++row)
            for (size_t col = 0; col < 4; ++col)
            {
                shape.setFillColor(field[row][col]);
                shape.setPosition(col * 50.f + shift, row * 50.f);
                window.draw(shape);
            }
        
        window.display();
    }

    return 0;
}