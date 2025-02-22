
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/window.hpp>
#include "Bat.h"


int main(){


    sf::VideoMode vm({ 1920, 1080 });


    sf::RenderWindow window(vm, "pong");


    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 900);

    sf::Font font;
    font.openFromFile("./fonts/DS-DIGI.ttf");
    sf::Text HUD(font, "what up bitch??");
    HUD.setFont(font);
    HUD.setCharacterSize(75);
    HUD.setPosition({ 20,20 });

    sf::Clock clock;

    while (window.isOpen()) {
        //handle player input
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                //close window
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                bat.moveLeft();
            }
            else {
                bat.stopLeft();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                bat.moveRight();
            }else {
                bat.stopRight();
            }
        }


        //update the bat the ball and hud
        //update the delta time
        sf::Time dt = clock.restart();
        bat.update(dt);
        //hud text
        std::stringstream ss;
        ss << "score: " << score << "  Lives: " << lives;
        HUD.setString(ss.str());

        //draw bat ball and hud
        window.clear();
        window.draw(HUD);
        window.draw(bat.getShape());
        window.display();

    }



    std::cout << "yo what the fuck is up??";

    return 0;
}

