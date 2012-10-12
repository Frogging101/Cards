#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <sstream>
#include "defs.hpp"
#include <vector>

using namespace std;
vector<int> usedWordsA;
vector<int> usedWordsB;
int doneWordsA;
int doneWordsB;
sf::Text Word1,Word2;
int ascore ,bscore;
bool madeListA, madeListB;
bool isFinish;

void endgame()
{
	madeListA = true;
	madeListB = true;
	isFinish = true;
	
	if (ascore > bscore) {
		Word1.setString("WIN!");
		Word2.setString("LOSE!");
	} else {
		Word1.setString("LOSE!");
		Word2.setString("WIN!");
	}
}

string createAnswerList(string *listOfAnswers) { 
	stringstream answerBox;
	answerBox << "A: " << listOfAnswers[0] << endl << endl;
	answerBox << "B: " << listOfAnswers[1] << endl << endl;
	answerBox << "C: " << listOfAnswers[2] << endl << endl;
	answerBox << "D: " << listOfAnswers[3] << endl << endl;
	return answerBox.str();
}
//Player 1 = a, player 2 = b
string* createRandomList(int &canswerptr,string &theword, int player)
{
	string* arrayPointer = new string[4];
	int waPair;
	if(player == 1)
	{
		while(true)
		{
			waPair = rand() % 24; //The array index of the word/answer pair
			if(find(usedWordsA.begin(),usedWordsA.end(),waPair) == usedWordsA.end())
			{
				break;
			}
		}
	}else
	{
		while(true)
		{
			waPair = rand() % 24; //The array index of the word/answer pair
			if(find(usedWordsB.begin(),usedWordsB.end(),waPair) == usedWordsB.end())
			{
				break;
			}
		}
	}

	
	int listPos = rand() % 4; //The position in the list to put the answer
	vector<int> chosenAnswers;
	vector<int> usedPos;
	int doneAnswers = 0;
	canswerptr = listPos;

	string word = words[waPair]; //Word
	theword = word;
	chosenAnswers.push_back(waPair);

	if(player == 1)
		usedWordsA.push_back(waPair);
	else
		usedWordsB.push_back(waPair);

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
	if(player == 1)
		doneWordsA++;
	else
		doneWordsB++;
	cout << "A: " << doneWordsA << endl << "B: " << doneWordsB << endl; //Debug code
	/*
	if(doneWordsA == 24 || doneWordsB == 24)
	{
		endgame();
	}*/
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

	//sf::Text Word1,Word2;
	Word1.setFont(font);Word2.setFont(font);
	Word1.setCharacterSize(10);Word2.setCharacterSize(10);

	sf::Text adef,bdef;
	adef.setFont(font);bdef.setFont(font);
	adef.setCharacterSize(10);bdef.setCharacterSize(10);
	adef.setPosition(50,300);
	bdef.setPosition(450,300);

	sf::Text tascore,tbscore;
	tascore.setFont(font);tbscore.setFont(font);
	tascore.setCharacterSize(16);tbscore.setCharacterSize(16);
	tascore.setString("0");tbscore.setString("0");

	tascore.setOrigin(tascore.getLocalBounds().width/2,tascore.getLocalBounds().height/2);
	tascore.setPosition(window.getSize().x/4,40);
	tbscore.setOrigin(tbscore.getLocalBounds().width/2,tbscore.getLocalBounds().height/2);
	tbscore.setPosition(window.getSize().x/4*3,40);

	//Down line
	sf::RectangleShape rectangle(sf::Vector2f(1, window.getSize().y/1.3));
	rectangle.setPosition(window.getSize().x/2, 0);
	//Right side line
	sf::RectangleShape horrect(sf::Vector2f(window.getSize().x,1));
	horrect.setPosition(0,window.getSize().y/1.3);

	//Rules text
	sf::Text trules;
	trules.setFont(font);
	trules.setCharacterSize(10);
	trules.setString(rules);
	trules.setPosition(50,window.getSize().y/1.2);


	int answer1 = -1,answer2 = -1;
	int canswer1, canswer2;
	string aWord;
	string bWord;
	string *aAnswerList;
	string *bAnswerList;
	ascore = 0; bscore = 0;
	//int ascore = 0,bscore = 0; 

	madeListA = false, madeListB = false;
	isFinish = false;

	while(window.isOpen()){
		/* EVENT LOOP */
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed) {
				window.close();
			}
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Q) {
					answer1 = 0;
				}
				else if(event.key.code == sf::Keyboard::W) {
					answer1 = 1;
				}
				else if(event.key.code == sf::Keyboard::E) {
					answer1 = 2;
				}
				else if(event.key.code == sf::Keyboard::R) {
					answer1 = 3;
				}

				if(event.key.code == sf::Keyboard::U) {
					answer2 = 0;
				}
				else if(event.key.code == sf::Keyboard::I){
					answer2 = 1;
				}
				else if(event.key.code == sf::Keyboard::O){
					answer2 = 2;
				}
				else if(event.key.code == sf::Keyboard::P){
					answer2 = 3;
				}
				if (event.key.code == sf::Keyboard::Return && isFinish) {
					isFinish = false;
					doneWordsA = 0;doneWordsB = 0;
					usedWordsA.clear();usedWordsB.clear();
					ascore = 0;bscore = 0;
					tascore.setString("0");tbscore.setString("0");
					madeListA = false;madeListB = false;
					answer1=-1;answer2=-1;

				}
			}
		}

		/* UPDATE AREA */
		if (!isFinish) {
			if(answer1 > -1){
				if (answer1 == canswer1) {
					ascore+=10;
				} else ascore-=10;
				madeListA = false;
				answer1 = -1;
				tascore.setString(intToStr(ascore));

				tascore.setOrigin(tascore.getLocalBounds().width/2,tascore.getLocalBounds().height/2);
				tascore.setPosition(window.getSize().x/4,40);
			}
			if(answer2 > -1){
				if (answer2 == canswer2) {
					bscore+=10;
				}else bscore-=10;
				madeListB = false;
				answer2 = -1;
				tbscore.setString(intToStr(bscore));

				tbscore.setOrigin(tbscore.getLocalBounds().width/2,tbscore.getLocalBounds().height/2);
				tbscore.setPosition(window.getSize().x/4*3,40);
			}
			if(!madeListA) {
				aAnswerList = createRandomList(canswer1,aWord,1);
				adef.setString(createAnswerList(aAnswerList));
				Word1.setString(aWord);
				madeListA = true;

				Word1.setOrigin(Word1.getLocalBounds().width/2,Word1.getLocalBounds().height/2);
				Word1.setPosition(window.getSize().x/4,80);
			}
			if(!madeListB) {
				bAnswerList = createRandomList(canswer2,bWord,2);
				bdef.setString(createAnswerList(bAnswerList));
				Word2.setString(bWord);
				madeListB = true;

				Word2.setOrigin(Word2.getLocalBounds().width/2,Word2.getLocalBounds().height/2);
				Word2.setPosition(window.getSize().x/4*3,80);
			}
			if(doneWordsA == 24 || doneWordsB == 24){
				endgame();
				adef.setString("Press Enter to Restart!");
				bdef.setString("Press Enter to Restart!");
			}	
		}

		/* DRAW LOOP */
		window.clear();
		window.draw(Word1);
		window.draw(Word2);
		window.draw(adef);
		window.draw(bdef);
		window.draw(tascore);
		window.draw(tbscore);
		window.draw(rectangle);
		window.draw(horrect);
		window.draw(trules);
		window.display();
	}
}
