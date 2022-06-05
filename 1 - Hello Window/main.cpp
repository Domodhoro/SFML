#include <iostream>

#include <SFML/Window.hpp>

bool close(const auto&);

int main() {
    sf::RenderWindow window(sf::VideoMode(500u, 300u), "SFML Window");
    sf::Event event;

    window.setPosition(sf::Vector2i(100, 100));
    window.setFramerateLimit(60u);

    while (window.isOpen()) {
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
