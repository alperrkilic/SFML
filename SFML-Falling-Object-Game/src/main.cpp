#include <iostream>
#include "Game.h"


int main(void){

  //Init srand

  //for generating random numbers
  std::srand(static_cast<unsigned>(time(NULL)));

  //init Game engine

  Game game;

  //Game Loop
  while(game.running())
  {
    //update
    game.update();

    //render
    game.render();
   
  }

  //end of application
  return 0;

}