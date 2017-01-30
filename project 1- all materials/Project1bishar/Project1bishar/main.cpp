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
#include "mastermind.h"
#include <vector>


int bound_check(std::string prompt, int min = INT_MAX, int max=INT_MAX);
// start of main function
int main(int argc, const char * argv[])
{
    int n=0,m=0;
    std::cout<<"Welecome to Master Mind Code Game"<<std::endl;
    
    n = bound_check("Input Code Length(0-Max Int)", 0);
    
    //user prompted to enter code range within bound 0 and 10
    //will reprompt if incorrect input
    m = bound_check("Input Digit Range(0-10)", -1, 11);
    
    mastermind one(n,m);
    one.playGame();
    return 0;

} // end of int main

// bound checking function for code number range m //
int bound_check(std::string prompt, int min , int max)
{
    int tr = 1;//flag used for remprompt of input
    int temp = 0;//holds temporary number for returning if in bound
    while (tr == 1)
    {//repeat loop till correct input in bound
        std::cout << prompt << std::endl;//prints the prompt
        
        std::cin >> temp;//inputs from keyboard single number
        if (std::cin.fail())
        {//checks if input is a failure
            std::cout << "NOT A NUMBER!" << std::endl;//prints not number
            std::cin.clear();//clears buffer
            std::cin.ignore(INT_MAX,'\n');//ignores error
            fflush(stdin);//flushes input
            continue;//contiune through
        }
        else
        {
            if (temp > min && temp < max)
            {//checks if temp within min and max
                tr=0;//sets flag to 0 for sucess
                
            }
            else
            {// user is incorrect range
                std::cout << "Number not incorrect range please renter" << std::endl;
                std::cin.clear();//clears buffer
                fflush(stdin);//flushes input
            }
        }
        
    }//end while loop
    return temp;//returns integer value in bounds
}
