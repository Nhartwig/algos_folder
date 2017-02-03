
// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 1 MASTER MIND 1b
// Prototype of the mastermind Class
// mastermind class handles the playing of the game
// mastermind class contains the secret code, and receives a guess code.
// It checks received guess code against the initialized secret code. 
// Then, it highlights if the game is solved at the end, and prints the
// secret code at end. 

#pragma once

#ifndef mastermind_h
#define mastermind_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <ostream>
#include "Code.hpp"
#include "response.h"


// definition for mastermind class.
// handles the playing of the game.
class mastermind {
	private:
		// Game code that contains secret code
		Code gameCode; 

		// Declaring code length (n) and integer range (m) variables
        int n,m;

		// Checks for number correct and incorrect between guessCode and secretCode
		// Function returns an object getResponse containing number correct and number incorrect
		// This is of the class response.
        response getResponse(Code *guessCode,Code *secretCode);

		// isSolved function checks the user response and sees if these values
		// are the same, therefore returning a bool if completely solved
        bool isSolved(response user_response);
		
		// This function prints the secret code vector. No input args.
		// Return type is void as it only cout's the secret code. 
        void printSecretCode();

		// humanGuess gets the user's guess from the keyboard,
		// then returns this as a guess code object.
        Code humanGuess();
   
	public:
		// one constructor for mastermind, in case user inputs values for n and m.
		mastermind(int nA, int mA);
		// default constructor for mastermind, using default values for n and m.
		mastermind();
		// This function plays the game of mastermind and tells if user wins or loses at end.
        void playGame();

}; // end mastermind class





#endif
