// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 1 MASTER MIND 1b
// Prototype of the mastermind Class
//  mastermind Class performs the playing the game
//mastermind class has the secret code, gets a guess code
//checks this value agains the secret code
//highlights if the game is solved and also prints the
//secret code

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
		Code gameCode;//Game code that contains secret code
        int n,m;//values for n and m which are used in game
        response getResponse(Code *guessCode);
        //checks to correct an incorrect bettween guessCode and secretCode
        //reuturns a responese containing this correct and incorrect
        bool isSolved(response user_response);
        //issolved checks the user respoense and sees if these values
        //are the same therefore returning a bool if solved
        void printSecretCode();//prints the secret code vector
        Code humanGuess();//gets the guess from keyboard and
        //returns this as a guess code object
    
   
	public:
		mastermind(int nA, int mA);
        //one constructor for mastermind containing values for n and m
		mastermind();
        //another constructor for mastermind using default values for n and m
        void playGame();
        //plays the game of mastermind and hihglights who wins in the end
		

};





#endif
