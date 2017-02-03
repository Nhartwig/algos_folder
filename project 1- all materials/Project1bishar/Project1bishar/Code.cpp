// Anthony Bisulco, Nathaniel Hartwig 
// Fundamentals of Algorithms 
// Project 1 MASTER MIND 1a
// Implementation of the Code Class
// Code Class performs the operation of generating secret codes.
// Also the class is used to hold the user guess in another code object.
// Intially all codes are random, although can be set using set code.
// Declaration for checkCorrect,checkIncorrect, setCode,printCode,getCode,
// Code constructor and seqInitialize.

#include "Code.hpp"
#include "d_random.h"
#include <math.h>

// Code Class Constructor inputting n and m
// Where n is the number of digits in code(>0)
// Where m is the range of digits in code(0,m-1)s.t.m>=0
// Code object is created from constructor call and
// Code Sequence is initialized to a random value after call
Code::Code(int n ,int m)
{
    seqInitialize(n, m);// Call to seqIntialize to create random vector
    
}


// Sequence intialize inputting n and m
// n is the number of digits in code(>0)
// m is the range of digits in code(0,m-1)s.t.m>=0
// Declare private member function to initialize the sequence.
// Generates random numbers, which are pushed to the back of the sequence 
// vector using time random class.
// Post sequence vector with random code generated
void Code::seqInitialize(int n, int m)
{
    randomNumber rndA(0);
    
    for (int i = 0; i < n; i = i + 1)	// For loop through number of digits
    {
		// Generates random code via modulus
		// Range(0,m-1) and push onto vector
        if(m == 1){
            seq.push_back(0);
        }else{
            
            seq.push_back((std::abs(int(rndA.random())))% (m));
        }
    }
}



std::vector<int> Code::getCode() const
// "getter function" to return private data member
// returns the sequenece vector for given object
// used for guess code to get code and use in
// checkCorrect and inCorrect
// function is const since nothing should be modified
{
    return seq;
}




// Code checking function to see if guess vector
// and secret vector elements are the same
// takes the code guess vector as an input
// returns number of correct values in correct positions.
// Vectors are assumed to be populated and contain valid elements
int Code::checkCorrect(Code *guess)
{
    std::vector<int> guessSeq=guess->getCode();	// Gets guess objects code
    int n=(int)seq.size();						// Gets size of sequenece
    int correct = 0;							// variable for correct digits in each vector

	// loop going through all digits in code
    for (int i = 0; i < n; i = i + 1)
    {
		// checks if code sequenece and vector element i are the same
        if(seq[i] == guessSeq[i])
        {
            correct=correct + 1;	// increments counter for correct pos in both vectors
        }
    }
    return correct;	// returns an int of correct values in correct positions
} // end Code checking function




// code setting function.
// allows for easy testing of program with different test cases.
// Post condition is the sequenece is not random although determinstic
// based on the value of the input code in codeset
// vector code set is assumed to have n digits in range 0 to m-1
// also code set is assumed to have valid population
void Code::setCode(std::vector<int> codeSet)
{
    seq = codeSet;	// set input vector to one for code object
}


// Function inputs a guess code which is another Code object
// Output is a integer of digits in wrong location but in sequence
// Output does not double count digits in wrong location but in seq
// Check incorrect does this through the use of two flags
// One flag checks if the digit is in correct pos
// Another flag checks if the digit has been counted in incorrect post before
// Therefore through these two flag these digits aren't counted
// Otherwise loops are traversed to find if digits are the same
int Code::checkIncorrect(Code *guess)
{
    std::vector<int> guessSeq = guess->getCode();	// gets the guess code containing guessVector
    int n = (int)seq.size();						// Returns number of digits
    int numIncorrect = 0;							// counter for number of digits in incorrect location
    std::vector<int> posGood;						// posGood is flag for digit in correct location for two seq.
	std::vector<int> tempSeq(seq);					// temporary vector containing same elements as secret code
    

    
    // first loop maps out instances of correct value and correct position in guess,
    // where 1 is correct, and 0 is incorrect. stored as vector.
    for (int i = 0; i < n; i = i + 1)			// loops through all digits
    {
        if(seq[i] == guessSeq[i]){				// if correct val in both seq
            posGood.push_back(1);				// pushes 1 on vector
        }
        else
        {
            posGood.push_back(0);				//pushs 0 on vector
        }
    } // end first for loop

	 // checks first to identify if at the current counter position,
     // there has already been a value that is correct and in correct position, from posGood map.
     // if so, it breaks out of the loop and skips to the next counter position.
     // else, if the values of guess and secret code are equal, -1 is entered for that position in temp seq
    for(int j = 0; j < n; j++)					// first loop through one guesses digits
    {
        for (int k = 0; k < n; k++)				// second loop through secret codes digits
        {
            if (posGood[j] == 1 || posGood[k] == 1) // if already in correct position skip
			{
                continue;							// skips to next point in array
            }
            else
            {
                if (guessSeq[j] == tempSeq[k])		// checks if guess and secret code are equal for given code
                {
					numIncorrect = numIncorrect + 1;// add up last counter value in numIncorrect
					tempSeq[k] = -1;				// sets given digit in temp seq to -1, so cannot be counted again
					break;
                }
            }
            
        } // end inner for loop
        
    }	// end outer for loop
        
    return numIncorrect;		 // returns number of incorrect digits
} // end check inCorrect function



// Print function used to return code at end of game
// No users inputs just couts all the secret codes elements
// function is const since nothing should be modified
void Code::printCode() const{

	int n = (int)seq.size();			// Get number of digits in code
    std::cout<<"Secret Code"<<std::endl;
    std::cout<<"{";
	for ( int i = 0; i < n; i++)		// loop through digits in code
    {
		std::cout << seq[i] << ",";		// prints out each digit in code
	}
    std::cout<<"}"<<std::endl;
} // end printCode function
