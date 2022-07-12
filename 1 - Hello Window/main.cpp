#include <iostream>

#include <SFML/Window.hpp>

using sf::Window;
using sf::VideoMode;
using sf::Event;
using sf::Keyboard;
using sf::Vector2i;

bool close(const auto&);

int main() {
    Window window(VideoMode(500, 300), "SFML Window");

    window.setPosition(Vector2i(100, 100));
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed || close(event)) {
                window.close();
            }
        }

        window.display();
    }

    return 0;
}

bool close(const auto& event) {
    return(event.key.code == Keyboard::Escape || event.key.code == Keyboard::Enter);
}
