#ifndef DECK_H
#define DECK_H
#include "card.h"
#include "d_node.h"
#include <string> 

// Deck: Represents a deck of cards
class Deck {
	public: 
	node<Card> *first; 
	
	// default constructor 
	Deck();
			
	// copy constructor 
	Deck(const Deck& item);
	
	// overloaded operator
	void operator = (const Deck &item );
	
	// destructor
	~Deck();
	
	// prints the cards in the deck
	void printDeck();
	
	// deal: returns the top card on the deck
	Card deal();
	
	// replace: places the newCard at the end of the linked list
	void replace(const Card& newCard);
	
	// shuffle: shuffles the cards by moving cards around
	void shuffle();
};

#endif
