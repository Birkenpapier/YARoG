#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <list>

#include "config.hpp"
#include "display_manager.hpp"

int main()
{
    std::cout << "YARoG.exe started \n" << std::endl;

    // load textures as defined in config
    Conf::loadTextures();

    // setting up window with anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(Conf::WIN_WIDTH, Conf::WIN_HEIGHT), "YARoG", sf::Style::Default, settings);
    window.setFramerateLimit(120);

    World world(Conf::WIN_WIDTH, Conf::WIN_HEIGHT);
    
    DisplayManager display_manager(window, window, world);

    sf::Vector2f last_clic;

    // main loop
    while (window.isOpen())
    {
        display_manager.processEvents();

        // handle mouse click
        if (display_manager.clic) {
            const sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
            const sf::Vector2f world_position = display_manager.displayCoordToWorldCoord(sf::Vector2f(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y)));
            
            const float clic_min_dist = 1.0f;

            if (getLength(world_position - last_clic) > clic_min_dist) {
                world.addFoodAt(world_position.x, world_position.y, 5.0f);
                last_clic = world_position;
            }
        }

        const float dt = 0.016f;

        if (!display_manager.pause) {
            world.update(dt);
        }

        window.clear(sf::Color(94, 87, 87));
        
        display_manager.draw();

        window.display();
    }

    // free up loaded textures
    Conf::freeTextures();

    return 0;
}

#if defined(_WIN32)
#include <windows.h>
// entry point for Windows application
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
  return main();
}
#endif
