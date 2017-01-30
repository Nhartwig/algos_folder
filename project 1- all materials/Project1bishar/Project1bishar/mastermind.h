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
		Code nate;
        int n,m;
	public:
		mastermind(int nA, int mA);
		mastermind();
		void printSecretCode();
		Code humanGuess();
		response getResponse(Code *guessCode);
		bool isSolved(response user_response);
		void playGame();
        int getN();
        int getM();

};











#endif
