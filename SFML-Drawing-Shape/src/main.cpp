#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>



int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800,600),"ilk pencerem");

    window.setFramerateLimit(60);

    sf::CircleShape daire(30.0f);

    //setting the color of the circle
    daire.setFillColor(sf::Color(55,100,0));

    //setting the thickness of outline of the circle
    daire.setOutlineThickness(5.0);

    //outline color of the circle
    daire.setOutlineColor(sf::Color(255,0,0));

    //circle position relative to the left top
    daire.setPosition(100,100);

    int x=100;
    int y=100;

    auto position = daire.getPosition();

    while(window.isOpen())
    {
      sf::Event event;

      while(window.pollEvent(event))
      {
        if(event.type==sf::Event::Closed)
        {
          window.close();
        }
      }

      daire.setPosition(x,y);


      //clearing the page and then giving it a random blue color.
      window.clear(sf::Color::Blue);
      //after clearing the page I am now drawing my shape
      window.draw(daire);
      //and after drawing I am displaying it.
      window.display();
      
      //important
      //since increment is done too fast
      //in order to slow our circle's motion
      //window.setFramerateLimit(60);
      x++;

    }


  return 0;

}