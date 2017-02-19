// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 2 MASTER MIND 2a
// Prototype of the Deck Class
// Deck class contains linked lists of cards in a deck 52 card
// These cards have value 1-13 where 1 is an Ace, 11 is Jack, 12 is Queen, 13 is King
//class can create a card object given a void constructor
// additionally getSuitName  are used to correspond a suit(0,1,2,3) with a string
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
    
        void shuffle();//shuffles cards in the linked list to a random order
        friend std::ostream& operator <<(std::ostream& ostr, Deck& a);//overloaded print operator to print linked list
        Deck(void);//default constructor to create the deck
        ~Deck(void);
        void playFlip();
    private:
        Card& getCard(int carNum);
        void setCard(int carNum);
        void carVal(Card &x, int &score);
        int bound_check(std::string prompt, int min , int max);
        Card deal(void);
        void replace(Card c);
        node<Card> *front;//pointer to initial linked list which contains deck, node object
        node<Card> *frontDeal;
        void swap(int x, int y, std::string one, std::string two);//swap function to switch two elements in the linked list

        std::string getSuitName(int a) const;//gets the suit name for a given value 0 Club,1 Diamond,2 Heart,3 Spade
};

#endif /* Deck_hpp */
