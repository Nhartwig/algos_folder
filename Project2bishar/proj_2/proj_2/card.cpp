#include "card.h"
#include <string>
#include <iostream>
/*
class Card
{
private:
	int value;
	std::string suit;
public:
	Card(int v, std::string s);
	void setValue(int v);
	void setSuit(std::string s);
	int getValue();
	std::string getSuit();
	friend std::ostream& operator<< (std::ostream& ostr, const Card& C);
};
*/

Card::Card(int v, std::string s) {
	setValue(v);
	setSuit(s);
}

void Card::setValue(int v) {
	int value = v;
}

void Card::setSuit(std::string s) {
	std::string suit = s;
}

int Card::getValue() {
	return value;
}

std::string Card::getSuit() {
	return suit;
}

std::ostream& operator<< (std::ostream& ostr, const Card& C) {
	ostr << C.value << " " << C.suit << std::endl;
}