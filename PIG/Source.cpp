#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);
int diceRoll();
//****************************************
//		MAIN 
//****************************************
int main() 
{
	bool playing = true;
	int computerTotalScore = 0;
	int humanTotalScore = 0;

	
	cout << "It's your turn! Enter 'r' to roll. " << endl;

		//while keeps the program looping until win conditions are met
	do 
	{
		//If statements checks the Total scores for both human and computer to determine if the game should continue
		if ((humanTotalScore < 100) && (computerTotalScore < 100))
		{
			//If win condition is not met loop stays true and enters while loop
			playing = true;
		}
		else
		{
			//If win condition is met loop is set to false and does not execute while loop
			playing = false;
		}
				
		humanTotalScore = humanTurn(humanTotalScore);
		humanTurn(humanTotalScore);

		//Win conditions
		//human win condition
		if (humanTotalScore >= 100)
		{
			cout << "Human Wins! " << endl;
			cout << "Game over" << endl;
			break;
		}			
		computerTotalScore = computerTurn(computerTotalScore);
		computerTurn(computerTotalScore);
		//computer win conditon
		if (computerTotalScore >= 100)
		{
			cout << "Computer Wins!" << endl;
			cout << "Game over" << endl;
			break;
		}

	} while (playing);
	
}
//****************************************
//		HUMAN TURN FUNCTION
//****************************************
int humanTurn(int humanTotalScore) 
{
	int tempHumanScore = 0;
	int humanRoll;
	char userInput='r';

	while (userInput == 'r' || userInput == 'R')
	{
		//Seeds the random function
		srand(time(NULL));
		humanRoll = diceRoll();

		cin >> userInput;

		if (humanRoll == 1)
		{
			cout << "You rolled a 1 " << endl;
			cout << "You lose your turn " << endl;
			cout << "Its the comptuers turn! " << endl;
			break;
		}
		else
		{
			cout << "You rolled " << humanRoll << endl;
			tempHumanScore += humanRoll;
			cout << "Your score this round is: " << tempHumanScore << endl;
			cout << "If you hold, your total score would be " << humanTotalScore + tempHumanScore << endl;
			cout << "Press 'h' to hold or 'r' to roll " << endl;
			
		}		
	}
	while (userInput == 'h' || userInput == 'H')
	{
		humanTotalScore += tempHumanScore;
		break;
	}
	//Returning the calculted human value
	return humanTotalScore;
}
//****************************************
//		COMPUTER TURN FUNCTION
//****************************************
int computerTurn(int computerTotalScore) 
{
	int tempCompScore = 0;
	int computerRoll=3;
	
	while (computerTotalScore < 100)
	{
		//Seeds the random function
		srand(time(NULL));
		computerRoll = diceRoll();

		if (computerRoll == 1)
		{
			cout << "The computer rolled a 1 " << endl;
			cout << "It loses its turn " << endl;
			break;
		}
		else if (computerRoll % 2 == 0)
		{
			cout << "The computer rolled " << computerRoll << endl;
			tempCompScore += computerRoll;
			cout << "Your computers score this round is: " << tempCompScore << endl;
			cout << "The computers total score is " << computerTotalScore + tempCompScore << endl;
			cout << "The computer holds!" << endl;
			cout << "Your turn!" << endl;			
		}
		else
		{
			computerTotalScore += tempCompScore;
			break;
		}
	}	
	
	//Returning the calculated computer value
	return computerTotalScore;
}
//****************************************
//		DICE ROLL FUNCTION
//****************************************
int diceRoll()
{
	int diceRoll = rand() % 6 + 1;
	return diceRoll;
}
//****************************************