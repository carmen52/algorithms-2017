#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <time.h> 
#include <string> 
#include <ctype.h>
#include "card.h"

using namespace std;

// Constructor for Card
Card::Card(string givenSuit, string givenValue) {
	suit = givenSuit; 
	value = givenValue; 
}
	
// copy constructor
Card::Card(const Card& item) {
	suit = item.suit; 
	value = item.value; 
}
	
// overloaded operator constructor
void Card::operator = (const Card &item ) {
	suit = item.suit; 
	value = item.value; 
}
	
// overloaded operator print
void Card::operator << (const Card &item) {
	cout << value << " of " << suit << "s" << endl; 
}
	
// get functions 
string Card::getSuit() { 
	return suit; 
}
string Card::getValue() { 
		return value; 
}
// set functions 
void Card::getSuit(string givenSuit) { 
	suit = givenSuit;  
}
void Card::getValue(string givenValue) { 
	value = givenValue;  
}
// print 
void Card::printCard() {
	cout << value << " of " << suit << "s" << endl; 
}
