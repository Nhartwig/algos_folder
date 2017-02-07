//
//  Card.hpp
//  Deck
//
//  Created by Anthony Bisulco on 2/6/17.
//  Copyright © 2017 Anthony Bisulco. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
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


#endif /* Card_hpp */
