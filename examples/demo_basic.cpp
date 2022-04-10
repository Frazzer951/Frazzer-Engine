#include <iostream>

#include "frazzerEngine.h"

class DemoGame : public fe::frazzerEngine
{
public:
  DemoGame() { appTitle = "Demo Game"; }

private:
  bool onCreate() override { return true; }

  bool onUpdate() override
  {
    for( int y = 0; y < screenHeight(); y++ )
    {
      for( int x = 0; x < screenWidth(); x++ ) { draw( x, y, fe::color( rand() % 255, rand() % 255, rand() % 255 ) ); }
    }
    return true;
  }
};

int main()
{
  std::cout << "Hello World!" << std::endl;
  DemoGame game;
  if( game.construct( 480, 480 ) ) { game.start(); }
  return 0;
}