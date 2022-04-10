#include "frazzerEngine.h"

bool fe::frazzerEngine::construct( int width, int height )
{
  WIDTH  = width;
  HEIGHT = height;

  window = new sf::RenderWindow( sf::VideoMode( WIDTH, HEIGHT ), appTitle, sf::Style::Close | sf::Style::Titlebar );
  image.create( WIDTH, HEIGHT, sf::Color::Black );
  texture.loadFromImage( image );
  sprite.setTexture( texture );

  if( !onCreate() ) { return false; }
  return true;
}

void fe::frazzerEngine::start()
{
  while( window->isOpen() )
  {
    while( window->pollEvent( event ) )
    {
      switch( event.type )
      {
        case sf::Event::Closed:
          {
            window->close();
            break;
          }
      }
    }

    if( !onUpdate() ) { window->close(); }

    texture.loadFromImage( image );
    sprite.setTexture( texture );

    window->clear();
    window->draw( sprite );
    window->display();
  }
}

fe::frazzerEngine::~frazzerEngine() { delete window; }

void fe::frazzerEngine::draw( int x, int y, color c ) { image.setPixel( x, y, sf::Color( c.r, c.g, c.b, c.a ) ); }
