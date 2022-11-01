#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>

enum class YON
{
  SOL,
  SAG,
  YUKARI,
  ASAGI
};

//Global variables:
int x=100;
int y=100;
sf::CircleShape *aktifSekil=nullptr;
bool hareketBaslasinmi = false;
sf::Texture kaplama;
YON sekilYonu = YON::SAG;
sf::Event event;
float cap{50};

void KeyboardControl(sf::Event &event)
{
      if(event.type==sf::Event::KeyPressed)
        {
          if(event.key.code==sf::Keyboard::A)
          {
            sekilYonu=YON::SOL;
          }
          if(event.key.code==sf::Keyboard::D)
          {
            sekilYonu=YON::SAG;
          }
          if(event.key.code==sf::Keyboard::W)
          {
            sekilYonu=YON::YUKARI;
          }
          if(event.key.code==sf::Keyboard::S)
          {
            sekilYonu=YON::ASAGI;
          }
          if(event.key.code==sf::Keyboard::Space)
          {
            //or alternatively
            //hareketBaslasinmi=!hareketBaslasinmi;
            if(hareketBaslasinmi==false)
            {
              hareketBaslasinmi=true;
            }
            else
            {
              hareketBaslasinmi=false;
            }
          }
        }

        if(event.type==sf::Event::KeyReleased)
        {
          
        }
}


void MouseControl(sf::Event &event)
{
  
        if(event.type==sf::Event::MouseButtonPressed)
        {
          if(event.mouseButton.button==sf::Mouse::Left)
          {
            
          }
        }

        if(event.type==sf::Event::MouseButtonReleased)
        {
          if(event.mouseButton.button==sf::Mouse::Left)
          {

          }
        }

        if(event.type==sf::Event::MouseMoved)
        {

        }
}


int main(void)
{
    sf::ContextSettings settings;

    settings.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(800,600),"ilk pencerem",sf::Style::Default,settings);


    if(kaplama.loadFromFile("resim.png")==false)
    {
        std::cout<<"PNG file couldn't be opened";
    }



    x=event.mouseButton.x;
    y=event.mouseButton.y;
    aktifSekil=new sf::CircleShape(1,90);
            
    aktifSekil->setTexture(&kaplama); 
    aktifSekil->setOutlineThickness(5.0);

    aktifSekil->setOutlineColor(sf::Color(255,0,0));

    //aktifSekil->setPosition(100,100);
    aktifSekil->setRadius(cap);


    window.setFramerateLimit(60);


    while(window.isOpen())
    {

      while(window.pollEvent(event))
      {
        if(event.type==sf::Event::Closed)
        {
          window.close();
        }

        KeyboardControl(event);
        MouseControl(event);

      }

      window.clear(sf::Color::Blue);

      if(aktifSekil)
      {
        aktifSekil->setPosition(x,y);
        window.draw(*aktifSekil);

        if(hareketBaslasinmi)
        {

          if(x+cap>=window.getSize().x)
          {
            sekilYonu=YON::SOL;
          }

          if(x<=0)
          {
            sekilYonu=YON::SAG;
          }

          if(y+cap>=window.getSize().y)
          {
            sekilYonu=YON::YUKARI;
          }

          if(y<=0)
          {
            sekilYonu=YON::ASAGI;
          }

          switch (sekilYonu)
          {
          case YON::SAG:
            x+=10;
            break;
          case YON::SOL:
            x-=10;
            break;
          case YON::YUKARI:
            y-=10;
            break;
          case YON::ASAGI:
            y+=10;
            break;
          default:
            break;
          }
        }
      }


      window.display();
      


    }

  free(aktifSekil);

  return 0;

}