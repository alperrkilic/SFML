#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>

//Global variables:
int x=100;
int y=100;
sf::CircleShape *aktifSekil=nullptr;
bool cizimBasladimi = false;

std::vector<sf::CircleShape*> sekiller;


sf::Font font;



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
            aktifSekil=new sf::CircleShape(1,90);
                //setting the color of the circle
                aktifSekil->setFillColor(sf::Color(55,100,0));

                //setting the thickness of outline of the circle
                aktifSekil->setOutlineThickness(5.0);

                //outline color of the circle
                aktifSekil->setOutlineColor(sf::Color(255,0,0));

                //circle position relative to the left top
                aktifSekil->setPosition(100,100);
            cizimBasladimi=true;
          }
        }

        if(event.type==sf::Event::MouseButtonReleased)
        {
          if(event.mouseButton.button==sf::Mouse::Left)
          {
            sekiller.push_back(aktifSekil);
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
            aktifSekil->setRadius(yariCap);
          }
        }
}


int main(void)
{
    sf::ContextSettings settings;

    settings.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(800,600),"ilk pencerem",sf::Style::Default,settings);

    if(font.loadFromFile("Standout.ttf")==false)
    {
      
    }
    sf::Text text;

    text.setFont(font);
    text.setString("Merhaba");
    text.setFillColor(sf::Color::Black);
    text.setOutlineColor(sf::Color::Red);
    text.setCharacterSize(120);

    window.setFramerateLimit(60);

  

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

      //drawing has started
      window.clear(sf::Color::Blue);

      for(auto siradaki:sekiller)
      {
        window.draw(*siradaki);
      }

      if(aktifSekil)
      {
        aktifSekil->setPosition(x,y);
        window.draw(*aktifSekil);
      }

      window.draw(text);

      window.display();

      //drawing has endet.

    }


  return 0;

}