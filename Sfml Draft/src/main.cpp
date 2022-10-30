
#include <SFML/Graphics.hpp>
#include "Game/Example.hpp"


void moveItem(float*, int*);

int main()
{
  Example e = Example();


  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
  sf::CircleShape shape(100.f);
  sf::CircleShape shape1(100.f);

  window.setFramerateLimit(120);
  shape.setFillColor(sf::Color::Yellow);
  shape1.setFillColor(sf::Color::Green);
  sf::Vector2f move(100, 100);
  sf::Vector2f move1(100, 400);


  int flag = 1, flag1 = 1;

  while (window.isOpen())
  {

    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();

    shape.setPosition(sf::Vector2f(move));
    shape1.setPosition(sf::Vector2f(move1));

    window.draw(shape);
    window.draw(shape1);

    moveItem(&move.x, &flag);
    moveItem(&move1.y, &flag1);

    window.display();


  }


  return 0;
}

void moveItem(float* vec, int* flag)
{
  if (*flag)
  {
    if (*vec > 600)
    {
      *flag = 0;
    }
    *vec += 3;
  }
  else
  {
    if (*vec < 0)
    {
      *flag = 1;
    }
    *vec -= 3;
  }

}