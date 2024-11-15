#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>  
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

float linearPositionIncrement(float deltaTime, float speed) {
    return speed * deltaTime;
}

int windowWidth = 592;
int windowHeight = 272;

int main() {

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML Snake", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);



    sf::Texture backgroundTexture1;
    if (!backgroundTexture1.loadFromFile("./resources/background_1.png")) {
        std::cerr << "Error loading background image" << std::endl;
        return -1;
    }
    sf::Sprite backGround1;
    backGround1.setTexture(backgroundTexture1);





    sf::Texture backgroundTexture2;
    if (!backgroundTexture2.loadFromFile("./resources/background_2.png")) {
        std::cerr << "Error loading background image" << std::endl;
        return -1;
    }
    backgroundTexture2.setRepeated(true);
    sf::Sprite backGround2;
    backGround2.setTexture(backgroundTexture2);
    backGround2.setTextureRect(sf::IntRect(0, 0, windowWidth * 2, windowHeight));
    float speed2 = 50.f;
    float traveledDistance2 = 0;






    sf::Texture backgroundTexture3;
    if (!backgroundTexture3.loadFromFile("./resources/background_3.png")) {
        std::cerr << "Error loading background image" << std::endl;
        return -1;
    }
    backgroundTexture3.setRepeated(true);
    sf::Sprite backGround3;
    backGround3.setTexture(backgroundTexture3);
    backGround3.setTextureRect(sf::IntRect(0, 0, windowWidth * 2, windowHeight));
    float speed3 = 75.f;
    float traveledDistance3 = 0;






    sf::Texture backgroundTexture4;
    if (!backgroundTexture4.loadFromFile("./resources/background_4.png")) {
        std::cerr << "Error loading background image" << std::endl;
        return -1;
    }
    backgroundTexture4.setRepeated(true);
    sf::Sprite backGround4;
    backGround4.setTexture(backgroundTexture4);
    backGround4.setTextureRect(sf::IntRect(0, 0, windowWidth * 2, windowHeight));
    float speed4 = 100.f;
    float traveledDistance4 = 0;




    // this is the only game clock
    sf::Clock gameClock;



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

            float timeInSeconds = gameClock.getElapsedTime().asSeconds();



            float addedDistance2 = linearPositionIncrement(timeInSeconds, speed2);
            traveledDistance2 += addedDistance2;
            if (traveledDistance2 >= windowWidth) {
                traveledDistance2 = 0;
                backGround2.setPosition(0, 0);
            }
            else {
                backGround2.setPosition(backGround2.getPosition().x - addedDistance2, backGround4.getPosition().y);
            }



            float addedDistance3 = linearPositionIncrement(timeInSeconds, speed3);
            traveledDistance3 += addedDistance3;
            if (traveledDistance3 >= windowWidth) {
                traveledDistance3 = 0;
                backGround3.setPosition(0, 0);
            }
            else {
                backGround3.setPosition(backGround3.getPosition().x - addedDistance3, backGround3.getPosition().y);
            }



            float addedDistance4 = linearPositionIncrement(timeInSeconds, speed4);
            traveledDistance4 += addedDistance4;
            if (traveledDistance4 >= windowWidth) {
                traveledDistance4 = 0;
                backGround4.setPosition(0, 0);
            }
            else {
                backGround4.setPosition(backGround4.getPosition().x - addedDistance4, backGround4.getPosition().y);
            }


            gameClock.restart();


        window.clear();

        window.draw(backGround1);
        window.draw(backGround2);
        window.draw(backGround3);
        window.draw(backGround4);

        window.display();
    }

    return 0;
}
