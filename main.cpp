// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 2 MASTER MIND 2a
// Implementation of the Main Function
// Main Function Creates a Deck Object for the Game of Flip
// In this part of the project a Deck is created and shuffled 3x
// the unshuffled and shuffled card seequnece are printed to the screen
// for the user to see the output

#include <iostream>
#include "Deck.hpp"

int main(int argc, const char * argv[]) {
    Deck r;//Creates a Deck Object
    
    std::cout<<"Before Card Shuffle"<<std::endl;
    std::cout<<r;
    //prints the deck object using overloaded operator
    r.shuffle();
    r.shuffle();
    r.shuffle();
    //shuffles the deck object 3 different times
    std::cout<<"After Card Shuffle"<<std::endl;
    std::cout<<r;
    //prints the deck object using overloaded operator
    
    return 0;
}
