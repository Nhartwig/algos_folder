// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 2 MASTER MIND 2a
// Prototype of the Card Class
// Card class is an object the can contain a value and a suit
// These cards have value 1-13 where 1 is an Ace, 11 is Jack, 12 is Queen, 13 is King
//getters and setters have been developed to change these string suit propert and int value propety
// a constructor that takes in a value and suit string has been developed to initialize card object
//finally an overloaded printing operator has been developed to print out the cards

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>

// Implementing the card class
class Card
{
    private:
        int value;//value is the value for the card 1 is an Ace, 11 is Jack, 12 is Queen, 13 is King
        std::string suit;//suit is the suit for the class a string value
        std::string getValueName(int a) const;//gets the specfic string name for a given value 
    public:
        Card(int v, std::string s);//constructor for card object taking in suit name and value
        void setValue(int v);//set value to set the value of a card object
        void setSuit(std::string s);//set suit to set the suit of a card object
        int getValue() const;//get value to get the value of a card object
        std::string getSuit() const;//get suit to get the suit of a card object
        friend std::ostream& operator << (std::ostream& ostr, const Card& C);
        //overloaded printing operator for the printing of a card
        Card& operator = (const Card &rhs);
        Card(const Card & rhs);
};


#endif /* Card_hpp */
