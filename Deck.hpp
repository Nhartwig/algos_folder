//
//  Deck.hpp
//  Deck
//
//  Created by Anthony Bisulco on 2/6/17.
//  Copyright © 2017 Anthony Bisulco. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp
#include "Card.hpp"

#include "d_node.h"
#include <stdio.h>
#include "iostream"
class Deck{
    public:
        node<Card> *front;
        node<Card> shuffle();
        friend std::ostream& operator <<(std::ostream& ostr, Deck& a);
        Deck(void);
        void swap(int x, int y, std::string one, std::string two);
    private:
        node<Card> getFront();
    
        std::string getSuitName(int a);
    
};


#endif /* Deck_hpp */
