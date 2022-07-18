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

bool keyboardCallback(const auto& event) {
    return (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Enter);
}

struct Creeper {
    Creeper() {
        if (!texture.loadFromFile("creeper.png")) {
            throw runtime_error("Falha ao carregar textura.");
        }

        texture.setSmooth(true);
    }

    void draw(RenderWindow& window, Vector2f position, Vector2f scale) const {
        Sprite Creeper(texture);
        Creeper.setPosition(position);
        Creeper.setScale(scale);

        window.draw(Creeper);
    }

private:
    Texture texture;
};

int main(int argc, const char** argv) {
    try {
        RenderWindow window(VideoMode(500u, 300u), "SFML Texture");
        Event event;

        window.setPosition(Vector2i(100, 100));
        window.setFramerateLimit(60u);

        auto creeper = make_unique<Creeper>();
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed || keyboardCallback(event)) {
                    window.close();
                }
            }

            window.clear();
            creeper->draw(window, Vector2f(100.0f, 50.0f), Vector2f(0.25f, 0.25f));

            window.display();
        }

        return 0;
    } catch (const exception& e) {
        cerr << e.what();
        cin.get();

        return 1;
    }
}
