// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 2 MASTER MIND 2a
// Prototype of the Deck Class
// Deck class contains linked lists of cards in a deck 52 card
// These cards have value 1-13 where 1 is an Ace, 11 is Jack, 12 is Queen, 13 is King
//class can create a card object given a void constructor
// additionally getSuitName and getValueName are used to correspond a suit(0,1,2,3) with a string
//and get value name corresponds the 1,11,12,13 to there rightful strings
//the print out operator<< has been overloaded for this calss
//a function to shuffle the cards along with a helper function to swap the cards has been created
//bellow is the prototype for these functions

#ifndef Deck_hpp
#define Deck_hpp
#include "Card.hpp"

#include "d_node.h"
#include <stdio.h>
#include "iostream"
class Deck{
    public:
        node<Card> *front;//pointer to initial linked list which contains deck, node object
        void shuffle();//shuffles cards in the linked list to a random order
        friend std::ostream& operator <<(std::ostream& ostr, Deck& a);//overloaded print operator to print linked list
        Deck(void);//default constructor to create the deck
    
    private:
        void swap(int x, int y, std::string one, std::string two);//swap function to switch two elements in the linked list
        std::string getSuitName(int a);//gets the suit name for a given value 0 Club,1 Diamond,2 Heart,3 Spade
        std::string getValueName(int a);//gets the value name for the Ace,King, Jack, Queen
};

#endif /* Deck_hpp */
