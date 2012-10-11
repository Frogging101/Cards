#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(800,600), "Card Game");
	sf::Event event;

	sf::Font font;
	font.loadFromFile("PetMe128.ttf");

	sf::Text Word1,Word2;
	Word1.setFont(font);Word2.setFont(font);
	Word1.setCharacterSize(10);Word2.setCharacterSize(10);
	Word1.setPosition(200,80);
	Word2.setPosition(450,80);
	Word1.setString("ajhSf");
	Word2.setString("INSETR");

	sf::Text adef;	
	sf::Text bdef;
	adef.setFont(font);bdef.setFont(font);
	adef.setCharacterSize(10);bdef.setCharacterSize(10);
	adef.setPosition(50,300);
	bdef.setPosition(450,300);
	adef.setString("AKSJFDHASFUDYASUGFASYU");
	bdef.setString("ASHJFASUIGFYUIASGFYAFAUISH");

	char answer1 = 0,answer2 = 0;
	char canswer1 = 5, canswer2 = 5;


	while(window.isOpen()){
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed) {
				window.close();
			}
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Q) {
					answer1 = 1;
				}
				else if(event.key.code == sf::Keyboard::W) {
					answer1 = 2;
				}
				else if(event.key.code == sf::Keyboard::E) {
					answer1 = 3;
				}
				else if(event.key.code == sf::Keyboard::R) {
					answer1 = 4;
				}

				if(event.key.code == sf::Keyboard::U) {
					answer2 = 1;
				}
				else if(event.key.code == sf::Keyboard::I){
					answer2 = 2;
				}
				else if(event.key.code == sf::Keyboard::O){
					answer2 = 3;
				}
				else if(event.key.code == sf::Keyboard::P){
					answer2 = 4;
				}
			}
		}

		if(answer1 > 0){
			//TODO answer check
		}
		if(answer2 > 0){
			//TODO answer check
		}

		window.clear();
		window.draw(Word1);
		window.draw(Word2);
		window.draw(adef);
		window.draw(bdef);
		window.display();
	}
}
