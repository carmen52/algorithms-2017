#ifndef CARD_H
#define CARD_H
#include <string> 

// class Card: stores a single card
class Card {
	private: 
	// The suit of the card - heart, diamond, spade or club
	std::string suit; 
	// The value of the card - numbers 2-10, Ace, Jack, Queen or King
	std::string value; 
	
	public: 
	// constructor
	Card(std::string givenSuit, std::string givenValue);
	
	// copy constructor
	Card(const Card& item);
	
	// overloaded operator constructor
	void operator = (const Card &item );
	
	// overloaded operator print
	void operator << (const Card &item);
	
	// get functions 
	std::string getSuit();
	std::string getValue();
	// set functions 
	void getSuit(std::string givenSuit);
	void getValue(std::string givenValue);
	// print 
	void printCard();
}; 

#endif
