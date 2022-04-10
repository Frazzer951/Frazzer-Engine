#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  const int WIDTH  = 640;
  const int HEIGHT = 480;

  sf::RenderWindow window( sf::VideoMode( WIDTH, HEIGHT ), "SFML Tutorial", sf::Style::Close | sf::Style::Titlebar );

  sf::Event event;

  sf::Image image;
  image.create( WIDTH, HEIGHT, sf::Color::Cyan );


  sf::Texture texture;
  texture.loadFromImage( image );
  sf::Sprite sprite( texture );

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

    for( int y = 0; y < HEIGHT; y++ )
    {
      for( int x = 0; x < WIDTH; x++ )
      {
        image.setPixel( x, y, sf::Color( rand() % 255, rand() % 255, rand() % 255 ) );
      }
    }

    texture.loadFromImage( image );
    sprite.setTexture( texture );

    window.clear();
    window.draw( sprite );
    window.display();
  }

  return 0;
}