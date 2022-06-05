#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

bool close(const auto&);

sf::Sprite loadTexture(const std::string);

int main() {
    try {
        sf::RenderWindow window(sf::VideoMode(500u, 300u), "SFML Texture");
        sf::Event event;

        window.setPosition(sf::Vector2i(100, 100));
        window.setFramerateLimit(60u);

        sf::Sprite cat(loadTexture("cat.png"));

        cat.setPosition(sf::Vector2f(50.0f, 50.f));
        cat.setScale(sf::Vector2f(1.5f, 1.5));

        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed || close(event)) {
                    window.close();
                }
            }

            window.clear();
            window.draw(cat);
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

sf::Sprite loadTexture(const std::string texturePath) {
    static sf::Texture texture;

    if (!texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Falha ao carregar textura.");
    }

    texture.setSmooth(true);

    return sf::Sprite(texture);
}
