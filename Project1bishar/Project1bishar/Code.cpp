// Anthony Bisulco and Nathaniel Hartwig Fundementals of Algorithms MASTER MIND 1a
//Implementation of the Code Class
//Code Class performs the operation of generating secret codes
//Also the class is used to hold the user guess in another code object
//Intially all codes are random, although can be set using set code
//Deceleration for checkCorrect,checkIncorrect, setCode,printCode,getCode
//Code constructor and seqInitialize
#include "Code.hpp"
#include "d_random.h"
#include <math.h>

Code::Code(int n ,int m)
//Code Class Constructor inputting n and m
//Where n is the number of digits in code(>0)
//Where m is the range of digits in code(0,m-1)s.t.m>=0
//Code object is created from constructor call and
//Code Sequenece is initialized to a random value after call
{
    seqInitialize(n, m);//Call to seqIntialize to create random vector
}



void Code::seqInitialize(int n, int m)
//Sequenec intialize inputting n and m
//Where n is the number of digits in code(>0)
//Where m is the range of digits in code(0,m-1)s.t.m>=0
//declare private member function to initialize the sequence.
//generates random numbers, which are pushed to the
//back of the sequence vector using time random class
//Post sequenece vector with random code generated
{
    randomNumber rndA(0);
    
    for (int i = 0; i < n; i = i + 1)
    {//For loop through number of digits
        seq.push_back((int(fabs(rndA.frandom()))% (m - 1)));//Generates a random code via modulus
        //Range(0,m-1) and push onto vecotor
    }
}



std::vector<int> Code::getCode() const
//"getter function" to return private data member
//returns the sequenece vector for given object
//used for guess code to get code and use in
//checkCorrect and inCorrect
//function is const since nothing should be modified
{
    return seq;
}



int Code::checkCorrect(Code *guess)
//Code checking function to see if guess vector
//and secret vector elements are the same
//takes the code guess vector as an input
//returns number of correct values in correct positions.
//Vectors are assumed to be populated and contain valid elements
{
 
    std::vector<int> guessSeq=guess->getCode();//Gets the guess objects code
    int n=seq.size();//gets the size of sequenece
    int correct = 0;//variable used for correct digits in each vector
    for (int i = 0; i < n; i = i + 1)
    {//loop going through all digits in code
        if(seq[i] == guessSeq[i])
        {//checks if code sequenece and vector element i are the same
            correct=correct + 1;//increments counter for correct pos in both vectos
        }
    }
    return correct;//returns an int of correct values in correct positions
}


void Code::setCode(std::vector<int> codeSet)
//code setting function.
//allows for easy testing of program with different test cases.
//Post condition is the sequenece is not random although determinstic
//based on the value of the input code in codeset
//vector code set is assumed to have n digits in range 0 to m-1
//also code set is assumed to have valid population
{
    seq = codeSet;//set input vector to one for code object
}

int Code::checkIncorrect(Code *guess)
//Function inputs a guess code which is another Code object
//Output is a integer of digits in wrong location but in sequenece
//Output does not double count digits in wrong location but in seq
//Check incorrect does this through the use of two flags
//One flag check if the digit is in correct pos
//Another flag check if the digit has been counted in incrorrect post before
//Therefore through these two flag these digits arent counted
//Otherwise loops are travered to find if digits are the same
{
    std::vector<int> guessSeq = guess->getCode();//gets the guess code containing guessVector
    
    int n = seq.size();//Returns number of digits
    int numIncorrect = 0;//counter for number of digits in incorrect location
    std::vector<int> posGood;//posGood is flag for digit in correct location for two seq.
    
    
    std::vector<int> hist(10);//hist is a histogram for digits with values only 0 or 1
    //Based on digits that are incorrect a flag is set for that digit in this array
    
    //first loop maps out instances of correct value and correct position in guess,
    //where 1 is correct, and 0 is incorrect. stored as vector.
    for (int i = 0; i < n; i = i + 1)
    {//loops through all digits
        if(seq[i] == guessSeq[i]){//if correct val in both seq
            posGood.push_back(1);//pushs 1 on vector
        }
        else
        {
            posGood.push_back(0);//pushs 0 on vector
        }
    }
    /*checks first to identify if at the current counter position,
     //there has already been a value that is correct and in correct position, from posGood map.
     //if so, it breaks out of the loop and skips to the next counter position.
     //else, if the values of guess and secret code are equal, a 1 is entered for that value in a histogram array.
     //histogram array has spaces for 0 to 9, maps number of times the guess has a right number, that is
     //not already in the correct position*/
    for (int j = 0; j < n; j++)
    {//first loop through one guesses digits
        
        for (int k = 0; k < n; k++)
        {//second loop through secret codes digits
            if (posGood[j] == 1 || posGood[k] == 1 || j == k) {//if already in correct position skip
                continue;//skips to next point in array
            }
            else
            {
                if (guessSeq[k] == seq[j])
                {//checks if guess and secret code are equal for given code
                    hist[guessSeq[k]] = 1;//sets given digit in histogram to one
                }
            }
            
        }
        
    }
    
    //loop used to add up histogram array incorrect digits
    for(int i = 0;i < n;i++)
    {//loop through number of digits
        numIncorrect += hist[i];//adds flagged incorrect digits to incorrect counter
    }
    
    
    return numIncorrect;//returns number of incorrect digits
}



void Code::printCode() const{
//Print function used to return code at end of game
//No users inputs just couts all the secret codes elements
//function is const since nothing should be modified
	int n = seq.size();//Get number of digits in code
	for ( int i = 0; i < n; i++)
    {//loop through digits in code
		std::cout << seq[i] << " ";//prints out each digit in code
	}
}
