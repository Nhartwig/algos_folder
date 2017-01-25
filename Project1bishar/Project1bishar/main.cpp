//
//  main.cpp
//  Project1bishar
//
//  Created by Anthony Bisulco on 1/17/17.
//  Copyright © 2017 Anthony Bisulco. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include "Code.hpp"
#include <vector>

//function header for checking if user inputs valid parameters for code
void user_input(int n, int m, std::vector<int> &code, std::string prompt);

//bound checking function. not necessary, but may implement in the future.
int bound_check(std::string prompt,int min = INT_MAX, int max=INT_MAX);


//start of main function
int main(int argc, const char * argv[]) {
    const int GAME_MAX_TURNS=10;
    int n=0,m=0;
    std::cout<<"Welecome to Master Mind Code Game"<<std::endl;

	//user prompted to enter code length
    n=bound_check("Input Code Length(0-Max Int)",0);

	// user prompted to enter integer range for input numbers
    m=bound_check("Input Digit Range(0-10)",-1,11);

	//create object of the Code class, this is the secret code.
    Code mastermindSeq(n,m);

	//declaring and initializing a variable to use as a flag for winning. 
    int win=0;
    
	
	
	//secret code setting function. allows user to set secret code. 
	//designed for easy testing of the program. 
	//takes as input a vector of numbers, assigns codeSet input vector to 
	//private data member seq. 
	std::vector<int> codeSet;
	std::cout << "Please Input Secret Code Seperated by Spaces " <<n<<" Numbers"<< std::endl;
	user_input(n, m, codeSet,"Secret");
	mastermindSeq.setCode(codeSet);
	

	//this loop gives the user 10 attempts to guess the correct code.
    for(int i=0;i<GAME_MAX_TURNS;i=i+1){
	//declare a vector named guessCode
    std::vector<int> guessCode;
	//check to see if user input code elements are valid
   	user_input(n, m, guessCode,"Guess");


	//create an object for the guess sequence of class Code.
	//the guess sequence object gets initialized with user 
	//input parameters of n and m, and then the code sequence itself
	//is set with the user's guess
    Code guessSeqinit(n,m);
    guessSeqinit.setCode(guessCode);

		//take guess sequence and pass it to the checkCorrect function
		//then assign the output to the counter variable Cor
        int Cor=mastermindSeq.checkCorrect(&guessSeqinit);
		//take guess sequence and pass it to the checkIncorrect function
		//then assign the output to the counter variable inCor
        int inCor=mastermindSeq.checkIncorrect(&guessSeqinit);
    
		//if number of correct valued elements in the correct position equals
		//the number of elements in the code, the user has won
        if(Cor==n){
            win=1;
            break;
        }
		/*USER FEEDBACK*/
        //print number of user attempts
        std::cout << "Trial Number:" << i+1 <<std::endl;
		//print number correct and in correct position, print number correct and in incorrect position
        std::cout << "Correct: " << Cor << " Incorrect: " << inCor << std::endl;
        
    }
    
    //if the win flag variable has been set to one, the user wins
    if (win==1){
        std::cout << "YOU WON!!!"<< std::endl;
		std::cout << "The secret code was: ";
		mastermindSeq.printCode();
		std::cout << std::endl;

    }
	else{
        std::cout << "YOU LOST!!!" << std::endl;
		std::cout << "The secret code was: ";
		mastermindSeq.printCode();
		std::cout << std::endl;
    }
    
    return 0;
}

//this function checks the user input parameters of code 
//length (n) and code range (m) to make sure the input elements
//of the guess sequence are valid, i.e, number of elements entered 
//does not exceed n, and each element is not greater than the
//maximum range of the code m
void user_input(int n, int m, std::vector<int> &code, std::string prompt) {
	
    int temp;
    int sucess=0;
    while(!sucess){
    code.clear();
    std::cout << "Enter numbers for the "<< prompt<<" sequence between 0 and " << m-1 <<" seperated by spaces" <<std::endl;
    for( int i=0; i<n;i++){
        std::cin>>temp;
        if(temp<m){
            code.push_back(temp);
            sucess=1;
        }else{
            std::cout<<"Input Range of Numbers Invalid Please Start Again"<<std::endl;
            sucess=0;
            break;
        }
    }
    }
}


// bound checking function for code number range m //
int bound_check(std::string prompt,int min , int max) {
    int tr=1;
    int temp=0;
    while(tr==1){
        std::cout<<prompt<<std::endl;
        std::cin>>temp;
        if(temp>min&&temp<max){
            tr=0;
            
        }else{
            std::cout<<"Number not incorrect range please renter"<<std::endl;
        }
        
    }
    return temp;
}

