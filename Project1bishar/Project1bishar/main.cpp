// Anthony Bisulco and Nathaniel Hartwig Fundementals of Algorithms MASTER MIND 1a
//Main Class for implmentation of Master Mind Game
//Master mind is a game where there is a code maker and code breaker
//A secret code is generated of length N and digit range 0 to m-1
//A user then tries to guess the code and two ouputs are generated
//Number of digits in right location and number of digits in incorrect location
//Main function runs the game playing functionality
//Code Class deals with the interface of generating codes and checking the guess against secret code
#include <stdio.h>
#include <iostream>
#include "Code.hpp"
#include <vector>

//user input function to set code or user vector using user input
//see further comments bellow
void user_input(int n, int m, std::vector<int> &code, std::string prompt);

//bound checking function. used to prompt used for input bettween two vals
//see further comments bellow
int bound_check(std::string prompt, int min = INT_MAX, int max=INT_MAX);

//start of main function
int main(int argc, const char * argv[])
{
    const int GAME_MAX_TURNS = 10;//Max of ten turns for game
    int n = 0,m = 0;//Intialize number of digits
    std::cout << "Welecome to Master Mind Code Game" << std::endl;

	//user prompted to enter code length within bound 0 and max int
    //will reprompt if incorrect input
    n = bound_check("Input Code Length(0-Max Int)", 0);

    //user prompted to enter code range within bound 0 and 10
    //will reprompt if incorrect input
    m = bound_check("Input Digit Range(0-10)", -1, 11);

	//create object of the Code class, this is the secret code.
    Code mastermindSeq(n, m);

	//declaring and initializing a variable to use as a flag for winning. 
    int win = 0 ;
    
	//secret code setting function. allows user to set secret code. 
	//designed for easy testing of the program. 
	//takes as input a vector of numbers, assigns codeSet input vector to 
	//private data member seq. 
	std::vector<int> codeSet;
	std::cout << "Please Input Secret Code Seperated by Spaces " << n <<" Numbers"<< std::endl;
	user_input(n, m, codeSet,"Secret");
	mastermindSeq.setCode(codeSet);
    
    
    //declare a vector for the guess code
	std::vector<int> guessCode;
    
    
    //create an object for the guess sequence of class Code.
    //input parameters of n and m, and then the code sequence itself
    Code guessSeqinit(n, m);
    
	//this loop gives the user 10 attempts to guess the correct code.
    for (int i = 0; i < GAME_MAX_TURNS; i = i + 1)
    {
	
    
    guessCode.clear();//clear code to start from new guessCode vector
    //check to see if user input code elements are valid and put these in guessCode
   	user_input(n, m, guessCode,"Guess");

    //the guess sequence object gets initialized with user
	//is set with the user's guess
    guessSeqinit.setCode(guessCode);

		//take guess sequence and pass it to the checkCorrect function
		//then assign the output to the counter variable Cor
        int Cor=mastermindSeq.checkCorrect(&guessSeqinit);
		//take guess sequence and pass it to the checkIncorrect function
		//then assign the output to the counter variable inCor
        int inCor=mastermindSeq.checkIncorrect(&guessSeqinit);
    
		//if number of correct valued elements in the correct position equals
		//the number of elements in the code, the user has won
        if (Cor == n)
        {
            win = 1;
            break;
        }
		/*USER FEEDBACK*/
        //print number of user attempts
        std::cout << "Trial Number:" << i+1 <<std::endl;
		//print number correct and in correct position, print number correct and in incorrect position
        std::cout << "Correct: " << Cor << " Incorrect: " << inCor << std::endl;
        
    }//end for loop
    
    //if the win flag variable has been set to one, the user wins
    if (win == 1)
    {
        std::cout << "YOU WON!!!"<< std::endl;
		std::cout << "The secret code was: ";
		mastermindSeq.printCode();//Prints code sequence
		std::cout << std::endl;

    }
	else
    {
        std::cout << "YOU LOST!!!" << std::endl;
		std::cout << "The secret code was: ";
		mastermindSeq.printCode();//Prints code sequence
		std::cout << std::endl;
    }
    
    return 0;
}


void user_input(int n, int m, std::vector<int> &code, std::string prompt)
//this function checks the user input parameters of code
//length (n) and code range (m) to make sure the input elements
//of the guess sequence are valid, i.e, number of elements entered
//does not exceed n, and each element is not greater than the
//maximum range of the code m additionally user is prompted with prompt
//also code is an input to push the numbers from the cin onto
//format assumed for input is # # # # # in a row
//although just N digits need to be in
//function performs bound checking and string checking
//so all user input is sanitized
{
	
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
}


//Bound checking function for single integer
//Input are prompt to give user
//Input are a min and max range for this integer to be in
//Return is a integer within the given min and max range
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

