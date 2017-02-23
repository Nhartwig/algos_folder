#pragma once
#include <string>

// Implementing the card class
class Card
{
	private:
		int value;
		std::string suit;
	public: 
		Card(int v, std::string s);
		void setValue(int v);
		void setSuit( std::string s);
		int getValue();
		std::string getSuit();
		friend std::ostream& operator<< (std::ostream& ostr, const Card& C);

};


