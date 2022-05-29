#include <iostream>

#include <SFML/Window.hpp>

bool close(const auto&);

int main() {
    sf::Window window(sf::VideoMode(500, 300), "SFML Window");

    window.setPosition(sf::Vector2i(100, 100));
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || close(event)) {
                window.close();
            }
        }
        
        window.display();
    }

    return 0;
}

bool close(const auto& event) {
    return(event.key.code == sf::Keyboard::Escape);
}
