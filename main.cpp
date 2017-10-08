#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <time.h> 
#include<limits>
#include <string> 
#include <ctype.h>
#include "d_node.h"
#include "deck.h"

using namespace std;

/*
	EECE2560
	Project 2
	Louisa Beckwith
	beckwith.l
	
	DESCRIPTION: 
	This is the game "Flip". Flip is a game played by one player with a Standard deck of 52 cards. 
		First the deck is shuffled 3 times. 
		Then, the player takes cards until they decide to stop. 
	Card values: 
		Ace - 10 Points
		Facecard - 5 Points
		8, 9 , or 10 - 0 Points
		7 - Lose half of points
		2, 3, 4, 5, 6 - Lose all points
		Heart - 1 point extra
	The goal is to end the game with the most points. 
	
	If the user enters an out of range int or a non-int, an exception is thrown and the game exits. 
	If the user enters a 1, a card is dealt. 
	If the user enters a 2, the game ends. 
	If the deck runs out of cards, the game ends. 
*/

// computes the current score of the player by adding the new card to the current score
int returnScore(int currentScore, Card newCard) {
		// gets the value and suit from the new card
		string value = newCard.getValue(); 
		string suit = newCard.getSuit(); 
		
		// determine how score should be altered based off of what value the card has
		if (value == "Ace") {
			currentScore = currentScore + 10; 
		}
		else if (value == "King" || value == "Queen" || value == "Jack") {
			currentScore = currentScore + 5; 
		}
		else if (value == "8" || value == "9" || value == "10") {
			currentScore = currentScore + 0; 
		}
		else if (value == "7") {
			currentScore = currentScore/2; 
		}
		else  {
			currentScore = 0; 
		}
		
		// add one to score if the suit is a heart
		if (suit == "heart") {
			currentScore = currentScore + 1; 
		}
		
		// return this score as the users new current score
		return currentScore; 
}

// playGame: global function that plays the game by reading instructions from the keyboard
//and printing the results to the screen
void playGame() {
	cout << "This is the game Flip. " << endl; 
	cout << "Flip is a game played by one player with a Standard deck of 52 cards." << endl;  
	cout << "First the deck is shuffled 3 times." << endl; 
	cout << "Then, the player takes cards until they decide to stop." << endl; 
	cout << "Please wait while the cards are shuffled..." << endl; 
	
	// create a new deck 
	Deck newDeck; 
	
	// shuffle the deck 3 times
	for (int i = 0; i < 3; i++) {
		newDeck.shuffle(); 
		newDeck.shuffle(); 
		newDeck.shuffle(); 
	}
	
	// while cin != 2, keep playing 
	int userInput = 1; 
	// set default score to 0
	int currentScore = 0; 
	
	// try and catch for throwing and catching exceptions
	try {
		 while (true){
			// the value is checked that it is an int, meaning cin operation was successful
			cout << "Press 1 to take a card, or 2 to end the game" << endl; 
			while(!(cin >> userInput)){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw(userInput);
			}
			if (userInput > 3 || userInput < 1){
				throw(userInput);
			}
			// if the user inputs 2, exit the game. 
			if (userInput == 2){
				cout << "Thank you for playing Flip. Your final score was: " << currentScore; 
				exit(1);
			}
			// pull card from top of deck
			Card currentCard = newDeck.deal(); 
			// compute current score
			currentScore = returnScore(currentScore, currentCard); 
			// print information to screen
			cout << "Selected card: "; 
			currentCard.printCard();
			cout << "Your current score is: " << currentScore << endl; 
		} 
	}
	// catches the thrown exceptions, displays message and exits game
	catch(int param) {
		cout << "Integer is not within valid range." << endl; 
		cout << "Game will now Exit." << endl; 
		exit(1);
	}
}

int main() {
	// calls function to play the game "Flip" 
	playGame();  	
	return 0; 
}
