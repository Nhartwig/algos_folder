// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 2 MASTER MIND 2a
// Implemnetation of the Card Class
// Card class is an object the can contain a value and a suit
// These cards have value 1-13 where 1 is an Ace, 11 is Jack, 12 is Queen, 13 is King
//class can create a card object given a void constructor
// additionally getSuitName and getValueName are used to correspond a suit(0,1,2,3) with a string
//and get value name corresponds the 1,11,12,13 to there rightful strings
//the print out operator<< has been overloaded for this calss
//a function to shuffle the cards along with a helper function to swap the cards has been created


#include "Card.hpp"
#include <string>
#include <iostream>


Card::Card(int v, std::string s)
//constructor to create a card object
//takes in value v which should be in range 1,13
//also the string should be limited to the set
//{Heart,Spade,Club,Diamond} after this constructor
//is completed card object with above given parameters
//is created
{
    setValue(v);//sets the value for the card object
    setSuit(s);//sets the suit for the card object
}

void Card::setValue(int v)
//setter function that takes in a value
//this function then resets the cards value
//to the inputted value v this value should
//be within the range of (1,13)
{
    value = v;
}

void Card::setSuit(std::string s)
//setter function that takes in a string
//this function then resets the cards suit
//to the inputted value s this value should
//be within set {Heart,Spade,Club,Diamond}
{
     suit = s;
}

int Card::getValue() const
//getter function that takes in nothing
//returns the value of the given card object
//this value should be in range 1,13
{
    return value;
}

std::string Card::getSuit() const
//getter function that takes in nothing
//returns the suit of the given card object
//be within set {Heart,Spade,Club,Diamond}
{
    return suit;
}
std::string Card::getValueName(int a) const
//get value name is a helper function
//that takes in a value a in bettween 1-13
//1-13 where 11 is Jack,12 is Queen, 13 is King, 1 is Ace
//based off this value this corresponds to a string value
//if none are found then DNE is returned, the return is one
//of the strings described above
{
    if (a < 11 && a != 1)
    {
        return std::to_string(a);//if numbers are 2-10 returns regluar number
    }
    else
    {
        if (a == 11)
        {//if the value is 11 this corresponds to Jack
            return "Jack";
        }
        else if (a == 12)
        {//if the value is 12 this corresponds to queen
            return "Queen";
        }
        else if (a == 13)
        {//if the value is 13 this corresponds to king
            return "King";
        }
        else if (a == 1)
        {//if the value is 1 this corresponds to Ace
            return "Ace";
        }
        else
        {//if not this will return with nothing found
            return "DNE";
        }
    }
}

std::ostream& operator<< (std::ostream& ostr, const Card& C)
//overloaded printing operator takes in an ostr which is
//the stream at which the output is to be printed to
//additionally takes in a card object creates a new
//ostream object that is returned to be printed to the screen
{
    ostr << C.suit << " " << C.getValueName(C.value);
    //formats a ostr object with the format Value _ Suite for a card object
    return ostr;//returns the ostream to be  printed to screen
}
