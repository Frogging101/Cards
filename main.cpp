#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <sstream>
#include "defs.hpp"
using namespace std;

int canswer1, canswer2;

string createAnswerList(string listOfAnswers[]) {
	stringstream answerBox;
	answerBox << "A: " << listOfAnswers[0] << endl;
	answerBox << "B: " << listOfAnswers[1] << endl;
	answerBox << "C: " << listOfAnswers[2] << endl;
	answerBox << "D: " << listOfAnswers[3] << endl;
	return answerBox.str();
}

int main() {
	sf::RenderWindow window(sf::VideoMode(800,600), "Card Game");
	sf::Event event;

	srand(time(NULL));

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

	int answer1 = 0,answer2 = 0;
	canswer1 = 5; canswer2 = 5;
	string aanswerlist[4];
	string banswerlist[4];

	bool madeListA = false, madeListB = false;

	/* NOTE This is justing testing code */
	string blaha[] = {answers[0],answers[1],answers[2],answers[3]};
	string blah = createAnswerList(blaha);
	adef.setString(blah);
	/* TESTING CODE */


	while(window.isOpen()){
		/* EVENT LOOP */
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

		/* UPDATE AREA */
		if(answer1 > 0){
			//TODO answer check
			cout << answer1 << endl;
			answer1 = 0;
		}
		if(answer2 > 0){
			//TODO answer check
			cout << answer2 << endl;
			answer2 = 0;
		}
		if(!madeListA) {
			//TODO John this is where this list changing would be called
			//for list A

			/* Pseudo code for list generation:
			    aAnswerList = createRandomList(); //BTW canswer1 (Correct answer 1)
			  									// is a global now so just edit it 
												//any way you want
				adef.setString(createAnswerList(aAnswerList));
			   */

		}
		if(!madeListB) {
			//TODO Like wise for this
		}

		/* DRAW LOOP */
		window.clear();
		window.draw(Word1);
		window.draw(Word2);
		window.draw(adef);
		window.draw(bdef);
		window.display();
	}
}
