#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <sstream>
#include "defs.hpp"
#include <vector>

using namespace std;

int canswer1, canswer2;

string createAnswerList(string *listOfAnswers) { 
	stringstream answerBox;
	answerBox << "A: " << listOfAnswers[0] << endl;
	answerBox << "B: " << listOfAnswers[1] << endl;
	answerBox << "C: " << listOfAnswers[2] << endl;
	answerBox << "D: " << listOfAnswers[3] << endl;
	return answerBox.str();
}

string* createRandomList()
{
	string* arrayPointer = new string[4];
	int waPair = rand() % 24; //The array index of the word/answer pair
	int listPos = rand() % 4; //The position in the list to put the answer
	vector<int> chosenAnswers;
	vector<int> usedPos;
	int doneAnswers = 0;

	string word = words[waPair]; //Word
	chosenAnswers.push_back(waPair);
	string cAnswer = answers[waPair]; //Correct answer

	arrayPointer[listPos] = cAnswer;
	usedPos.push_back(listPos);

	while(doneAnswers<3)
	{
		int randomAnswer = rand() % 24;
		int randomPos = rand() % 4;
		if((find(chosenAnswers.begin(),chosenAnswers.end(),randomAnswer) == chosenAnswers.end()) &&
		   (find(usedPos.begin(),usedPos.end(),randomPos) == usedPos.end()))
		{
			arrayPointer[randomPos] = answers[randomAnswer];
			chosenAnswers.push_back(randomAnswer);
			usedPos.push_back(randomPos);
			doneAnswers++;
		}
	}
	return arrayPointer;
}
string intToStr(int number) {
	stringstream num;
	num << number;
	return num.str();
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

	sf::Text tascore,tbscore;
	tascore.setFont(font);tbscore.setFont(font);
	tascore.setCharacterSize(16);tbscore.setCharacterSize(16);
	tascore.setPosition(100,40);tbscore.setPosition(600,40);
	tascore.setString("0");tbscore.setString("0");

	int answer1 = 0,answer2 = 0;
	canswer1 = 5; canswer2 = 5;
	string *aAnswerList;
	string *bAnswerList;
	int ascore = 0,bscore = 0; 

	bool madeListA = false, madeListB = false;

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
			if (answer1 == canswer1) {
				ascore+=10;
			} else ascore-=10;
			madeListA = false;
			answer1 = 0;
			tascore.setString(intToStr(ascore));
		}
		if(answer2 > 0){
			if (answer2 == canswer2) {
				bscore+=10;
			}else bscore-=10;
			madeListB = false;
			answer2 = 0;
			tbscore.setString(intToStr(bscore));
		}
		if(!madeListA) {
			aAnswerList = createRandomList();
			adef.setString(createAnswerList(aAnswerList));
			madeListA = true;
		}
		if(!madeListB) {
			bAnswerList = createRandomList();
			bdef.setString(createAnswerList(bAnswerList));
			madeListB = true;
		}

		/* DRAW LOOP */
		window.clear();
		window.draw(Word1);
		window.draw(Word2);
		window.draw(adef);
		window.draw(bdef);
		window.draw(tascore);
		window.draw(tbscore);
		window.display();
	}
}
