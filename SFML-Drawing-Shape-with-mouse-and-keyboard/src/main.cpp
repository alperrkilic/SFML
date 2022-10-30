#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>

//Global variables:
int x=100;
int y=100;
sf::CircleShape daire(30.0f,180);
bool cizimBasladimi = false;

void KeyboardControl(sf::Event &event)
{
      if(event.type==sf::Event::KeyPressed)
        {
          if(event.key.code==sf::Keyboard::D)
          {
            x++;
          }
          if(event.key.code==sf::Keyboard::A)
          {
            x--;
          }
        }

        if(event.type==sf::Event::KeyReleased)
        {
          x=0;
        }
}


void MouseControl(sf::Event &event)
{
  
        if(event.type==sf::Event::MouseButtonPressed)
        {
          if(event.mouseButton.button==sf::Mouse::Left)
          {
            x=event.mouseButton.x;
            y=event.mouseButton.y;

            daire.setRadius(1);
            cizimBasladimi=true;
          }
        }

        if(event.type==sf::Event::MouseButtonReleased)
        {
          if(event.mouseButton.button==sf::Mouse::Left)
          {
            cizimBasladimi=false;
          }
        }

        if(event.type==sf::Event::MouseMoved)
        {
          //std::cout<<event.mouseMove.x<<","<<event.mouseMove.y<<std::endl;
          //test line that shows the coordinates of the mouse when it is moved

          float yeniX=event.mouseMove.x;
          float yeniY=event.mouseMove.y;

          float yariCap = abs(x-yeniX)/2;

          if(cizimBasladimi)
          {
            daire.setRadius(yariCap);
          }
        }
}


int main(void)
{
    sf::ContextSettings settings;

    settings.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(800,600),"ilk pencerem",sf::Style::Default,settings);

    window.setFramerateLimit(60);



    //setting the color of the circle
    daire.setFillColor(sf::Color(55,100,0));

    //setting the thickness of outline of the circle
    daire.setOutlineThickness(5.0);

    //outline color of the circle
    daire.setOutlineColor(sf::Color(255,0,0));

    //circle position relative to the left top
    daire.setPosition(100,100);



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

        KeyboardControl(event);
        MouseControl(event);

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

    }


  return 0;

}