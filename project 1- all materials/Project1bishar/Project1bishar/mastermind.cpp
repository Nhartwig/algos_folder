
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
    std::string prompt="Guess";
    std::vector<int> code;
    int temp;//Temporary variable used to hold user input
    int sucess = 0;//sucess is a flag for all input good
    while (!sucess){//repeat this until sucessful input
        code.clear();
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
                continue;//repeats prompt sequence
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
    
    Code ret(n,m);
    ret.setCode(code);
    return ret;
    
}


response mastermind::getResponse(Code *guessCode){
    int cor=gameCode.checkCorrect(guessCode);
    int inCor=gameCode.checkIncorrect(guessCode);
    response retCode(inCor,cor);
    return retCode;
}


bool mastermind::isSolved(response user_response){
    if(n==user_response.getCorrect()){
        return true;
    }else{
        return false;
    }
}

void mastermind::playGame(){
    Code secretCode(n,m);
    std::vector<int> sec=secretCode.getCode();
    const int MAX_TURNS=10;
    int turns=0;
    gameCode.setCode(sec);
    printSecretCode();
    int win=0;
    while(win==0||MAX_TURNS==turns){
        Code guessCode=humanGuess();
        response one=getResponse(&guessCode);
        std::cout<<one;
        if(isSolved(one)){
            win=1;
        }
        turns=turns+1;
    }
    if(win==1){
    std::cout<<"YOU WIN"<<std::endl;
    }else{
    std::cout<<"YOU LOSE"<<std::endl;    
    }
}
