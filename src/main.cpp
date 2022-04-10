#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  sf::RenderWindow window( sf::VideoMode( 640, 480 ), "SFML Tutorial" );

  sf::Event event;
  while( window.isOpen() )
  {
    while( window.pollEvent( event ) )
    {
      switch( event.type )
      {
        case sf::Event::Closed:
          {
            window.close();
            break;
          }
      }
    }

    window.clear();
    window.display();
  }

  return 0;
}