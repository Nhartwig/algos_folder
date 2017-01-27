// Anthony Bisulco, Nathaniel Hartwig 
// Fundamentals of Algorithms 
// Project 1 MASTER MIND 1a

// Main Class for implmentation of Master Mind Game
// Master mind is a game where there is a code maker and code breaker
// A secret code is generated of length N and digit range 0 to m-1
// A user then tries to guess the code and two ouputs are generated
// Number of digits in right location and number of digits in incorrect location
// Main function runs the game playing functionality
// Code Class deals with the interface of generating codes and checking the guess against secret code
#include <stdio.h>
#include <iostream>
#include "Code.hpp"
#include <vector>




// start of main function
int main(int argc, const char * argv[])
{
    int n = 5,m = 7;	// Intialize number of digits
    std::cout << "Welecome to Master Mind Code Game" << std::endl;

	// create object of Code class, this is the secret code
    Code mastermindSeq(n, m);

    // declare vectors for user's guess code
    std::vector<int> guessCodeOne = {5, 0, 3, 2, 6};
    std::vector<int> guessCodeTwo = {2, 1, 2, 2, 2};
    std::vector<int> guessCodeThree = {1, 3, 3, 4, 5};

	// Counter variables for correct and incorrect
    int cor, inCor;				

    // create an object for the guess sequence of class Code.
    // input parameters of n, m, and the code sequence itself
    Code guessSeqinit(n, m);

    guessSeqinit.setCode(guessCodeOne);

    // take guess sequence, pass to checkCorrect function
    // then assign the output to the counter variable Cor
    cor = mastermindSeq.checkCorrect(&guessSeqinit);

    // take guess sequence, pass to checkIncorrect function
    // then assign the output to the counter variable inCor
    inCor = mastermindSeq.checkIncorrect(&guessSeqinit);
    std::cout << "CALLING FOR GUESS {5, 0, 3, 2, 6}" << std::endl;
    std::cout << "Correct: " << cor << " Incorrect: " << inCor << std::endl;
    guessSeqinit.setCode(guessCodeTwo);

    // take guess sequence, pass to checkCorrect function
    // then assign the output to the counter variable Cor
     cor = mastermindSeq.checkCorrect(&guessSeqinit);

    // take guess sequence, pass to checkIncorrect function
    // then assign the output to the counter variable inCor
    inCor = mastermindSeq.checkIncorrect(&guessSeqinit);
    std::cout << "CALLING FOR GUESS {2, 1, 2, 2, 2}" << std::endl;
    std::cout << "Correct: " << cor << " Incorrect: " << inCor << std::endl;
    guessSeqinit.setCode(guessCodeThree);

    // take guess sequence, pass to checkCorrect function
    // then assign the output to the counter variable Cor
     cor = mastermindSeq.checkCorrect(&guessSeqinit);

    // take guess sequence, pass to checkIncorrect function
    // then assign the output to the counter variable inCor
    inCor = mastermindSeq.checkIncorrect(&guessSeqinit);
    std::cout << "CALLING FOR GUESS {1, 3, 3, 4, 5}" << std::endl;
    std::cout << "Correct: " << cor << " Incorrect: " << inCor << std::endl;

    mastermindSeq.printCode();	// print the secret code at end of game

	return 0;

} // end of int main

