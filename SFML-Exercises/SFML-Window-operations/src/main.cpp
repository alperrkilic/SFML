
#include <SFML/Graphics.hpp>
#include "Game/Example.hpp"
#include <SFML\Window.hpp>



int main(void)
{
    sf::Window window(sf::VideoMode(800,600),"ilk pencere");

    //changing the size of the window.
    //window.setSize(sf::Vector2u(200,200));

    //changing the title of the window.
    //window.setTitle("Merhabalar");

    //determines the position of the window
    //window.setPosition(sf::Vector2i(0,0));



    //generating window and making running it
    //in continuous loop

    while(window.isOpen())
    {
        sf::Event olayNesnesi;

        while(window.pollEvent(olayNesnesi))
        {
            if(olayNesnesi.type==sf::Event::Closed)
            {
                window.close();
            }
        }
    }

}