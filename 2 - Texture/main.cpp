#include <iostream>
#include <stdexcept>
#include <memory>

using std::make_unique;
using std::cerr;
using std::cin;
using std::exception;
using std::runtime_error;

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Keyboard;
using sf::Vector2i;
using sf::Vector2f;
using sf::Sprite;
using sf::Texture;

bool close(const auto&);

class Cat {
public:
    Cat() {
        if (!texture.loadFromFile("cat.png")) {
            throw runtime_error("Falha ao carregar textura.");
        }
        texture.setSmooth(true);
    }

    void draw(RenderWindow& window, Vector2f position, Vector2f scale) const {
        Sprite cat(texture);
        cat.setPosition(position);
        cat.setScale(scale);

        window.draw(cat);
    }

private:
    Texture texture;
};

int main() {
    try {
        RenderWindow window(VideoMode(500u, 300u), "SFML Texture");
        Event event;

        window.setPosition(Vector2i(100, 100));
        window.setFramerateLimit(60u);

        auto cat = make_unique<Cat>();
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed || close(event)) {
                    window.close();
                }
            }
            window.clear();
            cat->draw(window, Vector2f(50.0f, 50.0f), Vector2f(1.5f, 1.5f));

            window.display();
        }

        return 0;
    } catch(const exception& e) {
        cerr << e.what();
        cin.get();

        return 1;
    }
}

bool close(const auto& event) {
    return(event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Enter);
}
