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
      for( int x = 0; x < screenWidth(); x++ )
      {
        if( x >= 230 && x <= 250 && y >= 230 && y <= 250 ) { draw( x, y, fe::color( 0, 255, 255 ) ); }
      }
    }
    return true;
  }
};

int main()
{
  std::cout << "Hello World!" << std::endl;
  DemoGame game;
  if( game.construct( 480, 480, true, 60 ) ) { game.start(); }
  return 0;
}