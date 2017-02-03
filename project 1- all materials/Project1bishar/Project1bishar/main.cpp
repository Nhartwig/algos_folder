// Anthony Bisulco, Nathaniel Hartwig 
// Fundamentals of Algorithms 
// Project 1 MASTER MIND 1b

// Main Class calls the mastermind class which plays the games
// Master mind is a game where there is a code maker and code breaker
// A secret code is generated of length N and digit range 0 to m-1
// A user then tries to guess the code and two ouputs are generated
// Number of digits in right location and number of digits in incorrect location
// Mastermind is the implementation of the game mechanics.
// Code Class deals with the interface of generating codes and checking the guess against secret code
// Response Class deals with the users guess and number of correct and incorrect in response
#include <stdio.h>
#include <iostream>
#include "mastermind.h"
#include <vector>
#include <climits>

// bound check function which is used to check value of int output within bounds
int bound_check(std::string prompt, int min = INT_MAX, int max=INT_MAX);

// start of main function
int main(int argc, const char * argv[])
{
    int n=0,m=0;
    
    std::cout<<"Welcome to Master Mind Code Game"<<std::endl;

    // user prompted to enter code range within bound 0 and MAX Int
    // will reprompt if input is incorrect.
    // assigns this to the number n, code length.
    n = bound_check("Input Code Length(1-Max Int)", 0);
    
    // user prompted to enter code range within bound 0 and 10
    // will reprompt if input is incorrect
    // assigns this to the number m, code digit range
    m = bound_check("Input Digit Range{0,(1-10)}",0, 11);
    
    // creates a mastermind object which is used to create a mastermind game
    // assigns the locals values of n and m to the game
    mastermind one(n,m);
   
    // plays the game for the 10 turns specified and prints out if you win
    one.playGame();
    return 0;

}	// end of main function

// bound checking function for range of digits in code, m.
// Function bound_check takes in a prompt that
// tells the user to insert value. Additionally, minium
// and maximum range are taken in to bound a given value obtained
// returned is a integer that is within the values of min and max
// this value is ensured to be an int in this range by performing
// number checking operations and flushing the cin buffer is there
// is something incorrect occurred 
int bound_check(std::string prompt, int min , int max)
{
    int tr = 1;										  // flag used for remprompt of input
    int temp = 0;									  // holds temporary number for returning if in bound
    while (tr == 1)							          // repeat loop till correct input in bound
    {				
        std::cout << prompt << std::endl;			  // prints the prompt
        std::cin >> temp;							  // inputs from keyboard single number
        if (std::cin.fail())						  // checks if input is a failure
        {
            std::cout << "NOT A NUMBER!" << std::endl;// prints not number
            std::cin.clear();						  // clears buffer
            std::cin.ignore(INT_MAX,'\n');			  // ignores error
            fflush(stdin);							  // flushes input
            continue;								  // contiune through
        }
        else
        {
            if (temp > min && temp < max)			  // checks if temp within min and max
            {
                tr=0;								  // sets flag to 0 for sucess
            }
            else									  // else, the user is in the incorrect range
            {
                std::cout << "Number not incorrect range please renter" << std::endl;
                std::cin.clear();					  // clears buffer
                fflush(stdin);						  // flushes input
            }
        }
        
    }			 // end of the while loop
    return temp; // returns integer value checked to be within bounds
}				 // end of bound check function.
