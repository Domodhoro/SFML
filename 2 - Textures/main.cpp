#include <iostream>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

bool close(const auto&);

class Cat {
    sf::Texture texture;

public:
    Cat() {
        if (!texture.loadFromFile("cat.png")) {
            throw std::runtime_error("Falha ao carregar textura.");
        }

        texture.setSmooth(true);
    }

    void draw(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f scale) const {
        sf::Sprite cat(texture);

        cat.setPosition(position);
        cat.setScale(scale);

        window.draw(cat);
    }
};

int main() {
    try {
        sf::RenderWindow window(sf::VideoMode(500u, 300u), "SFML Texture");
        sf::Event event;

        window.setPosition(sf::Vector2i(100, 100));
        window.setFramerateLimit(60u);

        auto cat = std::make_unique<Cat>();

        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed || close(event)) {
                    window.close();
                }
            }

            window.clear();
            
            cat->draw(window, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1.5f, 1.5f));
            
            window.display();
        }

        return 0;
    } catch(const std::exception& e) {
        std::cerr << e.what();
        std::cin.get();
        return 1;
    }
}

bool close(const auto& event) {
    return(event.key.code == sf::Keyboard::Escape);
}
