#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <time.h> 
#include <string> 
#include <ctype.h>
#include "d_node.h"
#include "deck.h"
#include "card.h"
#include <sstream>

using namespace std;

// Type casts a number as a string
template <typename T>
string NumberToString(T num){
	ostringstream oOStrStream; 
	oOStrStream << num; 
	return oOStrStream.str();
}

// default constructor 
Deck::Deck() {
	// assign a head to the linked list
	node<Card> *head = new node<Card>(Card("spade", "King"), NULL);

	// create the deck in order
	string suit; 
	string value; 
	for (int i = 0; i < 4; i ++) {
		if (i == 0)
			suit = "club"; 
		if (i == 1) 
			suit = "heart"; 
		if (i == 2)  
			suit = "diamond"; 
		if (i == 3)
			suit = "spade"; 
		for (int k = 1; k < 14; k++){
			value = NumberToString(k); 
			if (value == "1")
				value = "Ace";
			if (value == "11")
				value = "Jack"; 
			if (value == "12")
				value = "Queen"; 
			if (value == "13")
				value = "King"; 
				
			// create a new node with the new card value, pointing to the next card
			node<Card> *temp = new node<Card>(Card(suit,value), head);
			head = temp; 
		}
	}
	// assign the first of this deck to the head of the linked list
	first = head; 
}
		
// copy constructor 
Deck::Deck(const Deck& item) {
	// create two new nodes
	// the first node is the first in this deck
	node<Card> *ptr;
	// the second is a node to traverse the given deck with
	node<Card> *temp;
	// set this first to the ptr 
	first = ptr; 
	temp = item.first; 
		
	// copy the value to the new list
	while(temp != NULL)
	{
   		ptr->nodeValue = temp->nodeValue; // copy the value
   		ptr->next = temp->next; 
   		temp = temp->next; 
   		ptr =ptr->next; 
   	}
}

// overloaded operator
void Deck::operator = (const Deck &item ) { 
	// create two new nodes
	// the first node is the first in this deck
	node<Card> *ptr;
	// the second is a node to traverse the given deck with
	node<Card> *temp;
	// set this first to the ptr 
	first = ptr; 
	temp = item.first; 
		
	// copy the value to the new list
	while(temp != NULL)
	{
   		ptr->nodeValue = temp->nodeValue; // copy the value
   		ptr->next = temp->next; 
   		temp = temp->next; 
   		ptr =ptr->next; 
   	}
}

// destructor
Deck::~Deck() {
	// deletes the linked list by deleting the first node
	delete first; 
}

// prints the cards in the deck
void Deck::printDeck() {
	node<Card> *current = first; 
	
// traverses the list and prints each card
	while(current->next != NULL) {
		current->nodeValue.printCard(); 
	    current = current->next; 
	}
}

// deal: returns the top card on the deck
Card Deck::deal() {
	// get value of the card of the first node
	Card newCard = first->nodeValue; 
	// remove the first node from the linked list
	first = first->next; 

	// if all the cards have been dealt, exit the game
	if (first->next == NULL){
		cout << "All the cards have been dealt. The game is over." << endl; 
		exit(1);
	}
	// return the value of the first node 
	return newCard; 
}

// replace: places the newCard at the end of the linked list
void Deck::replace(const Card& newCard) {
	// create new nodes, one to traverse the list with 
	node<Card> *temp;
	// set the node temp to first, to traverse the list
	temp = first; 
	node <Card> *temp_head = temp; 
	
	// and one node to place at the end of the list
	// set the value of the new node to the new card
	node<Card> *newNode = new node<Card>(newCard, NULL);

	// while temp is not the end of the list, traverse the list
	while(temp->next != NULL) {
		temp = temp->next; 
	}
	// reached the end of the list, so add the newNode to the end
	temp->next = newNode; 
	first = temp_head;
}

// shuffle: shuffles the cards by moving cards around
void Deck::shuffle() {
	// determine a random amount of time to move the cards by
	srand(time(0));
	
	// random values
	int rand_1 = rand() %5000; 
	int rand_2 = rand() %52; 
	
	// Repeat for random amount
	for (int i = 0; i < rand_1; i++){
		// Swap first 2 nodeValues
		Card tempCard = first->next->nodeValue; 
		first->next->nodeValue = first->nodeValue; 
		first->nodeValue = tempCard; 
		
		// Shift by random amount
		for (int k = 0; k < rand_2; k++){
			// Shift by 1
			replace(first->nodeValue); 
			first = first->next; 
		}
	}	
	
}

