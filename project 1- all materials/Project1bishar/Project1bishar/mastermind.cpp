
// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 1 MASTER MIND 1a
// Implementation of the Code Class
// Mastermind class performs the action fo playing the game and allowing IO
// contains funtction to play game for ten turns then tell the user who won
// additionally the game will print the secret code at the end to highlight
// how close you were to the guess, contains implemntations for
//Constructor no arguments, constructor arguments code length and digits
//humanGuess, getResponese,isSolved and playGame
#include "Code.hpp"
#include "response.h"
#include "mastermind.h"
#include <iostream>
#include <vector>
#include <climits>


mastermind::mastermind(int nA,int mA)
//One of two constructors for the mastermind class
//Creates the mastermind object and intializes the
//code length and digit length to their values n and m
//they values are assumed to be within range above 0 and
//are supposed to be integers ensured using bound check fn
{
    n=nA;
    m=mA;
    
}
mastermind::mastermind()
//One of two constructors for the mastermind class
//Creates the mastermind object and intializes the
//code length and digit length to their default values n=5 and m=10
//they values are assumed to be within range above 0 and
//are supposed to be integers ensured using bound check fn
{
    n=5;
    m=10;
    
}

void mastermind::printSecretCode()
//print secret code uses the functionality
//developed in the last code class to print
//the secret code which prints out the
//secret code using a cout fucntion
//no user input and no return
{
    gameCode.printCode();
    
}

Code mastermind::humanGuess()
//Human Guess is a function that takes in no parameters
//as a return this function returns an object which is
//a code object containig the guess code with what should
//be initialized parmeters with values(n,m and secret code)
//function ensures correct user io through 
{
    std::string prompt="Guess";//prompt for users about that this is for a guess
    std::vector<int> code;//vector to hold the guess code
    int temp;//Temporary variable used to hold user input
    int sucess = 0;//sucess is a flag for all input good
    while (!sucess){//repeat this until sucessful input
        code.clear();//clears the guess code if incorrect from past iterations
        int numLen = 0;//counter for number of digits
        std::cout << "Enter numbers for the "<< prompt<<" sequence between 0 and " << m-1 << " seperated by spaces" << std::endl;
        //Prompt for user input
        for ( int i = 0; i < n;i++)
        {//for loop through the input digits
            std::cin >> temp;//gets the digit in cin buffer
            if (std::cin.fail())
            {//checks if this is not an integer
                std::cout << "NOT A NUMBER!" << std::endl;//if so print not an number
                std::cin.ignore(INT_MAX,'\n');//ignores error
                std::cin.clear();//clears the buffer for cin
                fflush(stdin);//flushes buffer for cin
                continue;//repeats prompt sequence used for inccorect input
            }
            else
            {
                if (temp < m && temp > -1)
                {//Checks if digits are less than m and greater than -1
                    code.push_back(temp);//pushes element onto vector
                    sucess = 1;//sets sucess vector to 1
                    numLen += 1;//increases length vector
                }
                else
                {
                    std::cout << "Input Range of Numbers Invalid Please Start Again" << std::endl;
                    //output the prompt for incorrect number range
                    std::cin.ignore(INT_MAX,'\n');//ignores error
                    std::cin.clear();//clears the buffer for cin
                    fflush(stdin);//flushes buffer for cin
                    sucess = 0;//unsucessful input
                    break;//breaks and restarts
                }
            }
        }//end for loop
        if (numLen != n)
        {//number of length and n are not same error
            sucess = 0;//sets sucess to 0
            std::cin.clear();//clears the buffer for cin
            std::cin.ignore(INT_MAX,'\n');//ignores error
            fflush(stdin);//flushes buffer for cin
            std::cout << "Input length  of numbers start again" << std::endl;//restart number input
        }
    }//end while loop
    
    Code ret(n,m);//Creates a Code object to be returned with n m value
    ret.setCode(code);//Sets the code to the code that is contained in vector
    return ret;//returns this code object to user
    
}


response mastermind::getResponse(Code *guessCode)
//getResponese is a function that gets a guessCode as
//an input and is called on a gameCode which compares
//the guessCode and gameCode to see if correct or not
//returns a responese object which contains the values
//of incorrect and correct which is then returned using
//this function, guess code is assumed to be initialized with
//a sequenece vector along with the gameCode
{
    //gets the correct values for gameCode compared to guesCode
    int cor=gameCode.checkCorrect(guessCode);
    //gets the incorrect values for gameCode compared to guesCode
    int inCor=gameCode.checkIncorrect(guessCode);
    //creates responese object with parameters correct and incorrect
    response retCode(inCor,cor);
    //returns the respones object containg the responese for this code
    return retCode;
}


bool mastermind::isSolved(response user_response)
//is solved is a function that compares the user respones object
//that contains the correct and incorrect value for a guessCode
//gameCode pair and then sees if the correct value is equal to
//the number of total digits therefore the  code is solved otherwise
//the code is not solved
{
    if(n==user_response.getCorrect()){//check is code num digits is equal to correct digits
        return true;//true if above is true
    }else{
        return false;//false if nonequal number of digits and correct digits
    }
}

void mastermind::playGame()
//Play game is an object that takes in no user input
//it is assumed that the mastermind object calling has a
//value of n and m and this function also returns nothing
//this function then plays the game which creates a secret code
//prints a secret code has the user enter a guess
//checks this guess against secret code
//sees if the puzzle was solved if not iterates until
//turn limit is reached and then win and lose is displayed
{
    Code secretCode(n,m);//Creates a secret code object with values
    
    std::vector<int> sec=secretCode.getCode();//gets the current secret cdode
    const int MAX_TURNS=10;//defines max turns in the game
    int turns=0;//defines number of turns in game
    gameCode.setCode(sec);//sers secretCode to the game code
    printSecretCode();//pritns the secret code for users to see
    int win=0;//winner flag used to determin if the user has won the game
    while(win==0||MAX_TURNS==turns)
    //win flag is checked and if the maxturns has passed
    {
        Code guessCode=humanGuess();//gets the user guess code from keyboard
        response one=getResponse(&guessCode);//checks this secretcode and guess code
        std::cout<<one;//prints out correct and incorrect responses
        if(isSolved(one)){//checks if the puzzle has been solved
            win=1;//sets the winning flag to win
        }
        turns=turns+1;//increments turns counter
    }
    if(win==1){//win flag
    std::cout<<"YOU WIN"<<std::endl;//highlights the user has won
    }else{
    std::cout<<"YOU LOSE"<<std::endl;  //highlights the user has lost
    }
}
