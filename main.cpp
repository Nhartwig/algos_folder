//
//  main.cpp
//  Deck
//
//  Created by Anthony Bisulco on 2/6/17.
//  Copyright © 2017 Anthony Bisulco. All rights reserved.
//

#include <iostream>
#include "Deck.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Deck r;
    std::cout<<"Before Card Shuffle"<<std::endl;
    std::cout<<r;
    r.shuffle();
    r.shuffle();
    r.shuffle();
    std::cout<<"After Card Shuffle"<<std::endl;
    std::cout<<r;
    return 0;
}
