// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 1 MASTER MIND 1b
// Prototype of the Code Class
// Code Class performs the operation of generating secret codes
// Also the class is used to hold the user guess in another code object.
// Initially all codes are random, although can be set using set code.
// Prototype contains the inital definitions and whether public or private.

#ifndef Code_hpp
#define Code_hpp

#include <stdio.h>
#include <vector>
#include <iostream>



// declaring the code class to be used throughout the project
// For full comments please see CPP file for full definition
class Code{

	// Private data hidden from user is sequence vector and 
	// ability to intialize random vector.
	private:
        std::vector<int> seq;	// Code or Guess sequence
        int n, m;
		// Intialize sequence vector.
		// Intial values are 1 since 0 would be no game at all
        void seqInitialize(int n = 1, int m = 4);
    public:
		// constructor to make object, intialize vector
        Code(int n = 1, int m = 4);

		// check right digits in right location
        int checkCorrect(Code *guess);

		// check right digits but not in same 
		// location no double counts.
        int checkIncorrect(Code *guess);

		// returns intialized sequence vector
        std::vector<int> getCode() const;

		// sets the sequence vector for testing
        void setCode(std::vector<int> codeSet);

		void printCode() const;		// prints secret code
}; // end Code class





#endif /* Code_hpp */
