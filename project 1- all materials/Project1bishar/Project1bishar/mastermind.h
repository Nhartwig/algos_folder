#pragma once

#ifndef response_h
#define response_h

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
	public:	
		mastermind(int n, int m);
		mastermind();
		void printSecretCode();
		Code humanGuess();
		response getResponse(Code guessCode, Code secretCode);
		bool isSolved(response user_response);
		void playGame();

};











#endif