#ifndef FRAZZER_ENGINE_FRAZZERENGINE_H
#define FRAZZER_ENGINE_FRAZZERENGINE_H

#include <SFML/Graphics.hpp>

namespace fe
{
  struct color
  {
    int r;
    int g;
    int b;
    int a;

    color( int red, int green, int blue, int alpha = 255 ) : r( red ), g( green ), b( blue ), a( alpha ) {}
  };

  class frazzerEngine
  {
  protected:
    std::string appTitle;

  private:
    int                WIDTH;
    int                HEIGHT;
    bool               SHOW_FPS;
    sf::RenderWindow * window;
    sf::Event          event;
    sf::Image          image;
    sf::Texture        texture;
    sf::Sprite         sprite;
    sf::Clock          clock;
    sf::Clock          fpsUpdateTimer;

    virtual bool onCreate() = 0;
    virtual bool onUpdate() = 0;
    void         onDelete() {}


  public:
    virtual ~frazzerEngine();
    bool construct( int width, int height, bool showFPS = true, int fpsLimit = 0 );
    void start();
    int  screenWidth() const { return WIDTH; }
    int  screenHeight() const { return HEIGHT; }
    void draw( int x, int y, color c );
  };
}    // namespace fe

#endif    // FRAZZER_ENGINE_FRAZZERENGINE_H
