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
		Code gameCode;
        int n,m;
        response getResponse(Code *guessCode);
        bool isSolved(response user_response);
        void printSecretCode();
        Code humanGuess();
    
    void playGame();
	public:
		mastermind(int nA, int mA);
		mastermind();
		

};











#endif
