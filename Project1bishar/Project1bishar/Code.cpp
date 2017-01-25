//
//  Code.cpp
//  Project1bishar
//
//  Created by Anthony Bisulco on 1/17/17.
//  Copyright © 2017 Anthony Bisulco. All rights reserved.
//

#include "Code.hpp"
#include <ctime>
/*class Code{
private:
    std::vector<int> seq;
    void seqInitialize(int n = 0, int m = 0);
public:
    Code(int n = 0,int m = 0);
    int checkCorrect(Code guess);
    int checkIncorrect(Code guess);
    std::vector<int> getCode();
};*/



//code constructor to automatically instantiate 
//in class declaration, n and m are defaulted to zero.
//values passed to sequence initializing function. 
Code::Code(int n ,int m){
    seqInitialize(n, m);
}


//declare private member function to initialize the sequence.
//sequence initialize takes input values n and m as parameters to generate 
//random numbers, which are pushed to the back of the sequence vector
void Code::seqInitialize(int n, int m){
    //randomNumber rndA(1);
    srand( time(0));
    for(int i=0; i<n;i=i+1){
        seq.push_back((rand()%(m-1)));
    }
}


//"getting function" to return private data member 
//seq (the secret code sequence to be guessed)
std::vector<int> Code::getCode(){
    return seq;
}


//code checking function. takes the code guess vector as an input. 
//returns number of correct values in correct positions.
int Code::checkCorrect(Code *guess){
 
    std::vector<int> guessSeq=guess->getCode();
    int n=seq.size();
    int correct=0;
    for( int i=0; i<n;i=i+1){
        if(seq[i]==guessSeq[i]){
            correct=correct+1;
        }
    }
    return correct;
}

//code setting function. NOT part of the project
//allows for easy testing of program with different test cases.
void Code::setCode(std::vector<int> codeSet){
    seq=codeSet;
}


/*other code checking function. takes vector containing the guess 
sequence as input. returns number of correct values in incorrect 
position. does NOT check elements flagged as having correct value and being in the correct position*/
int Code::checkIncorrect(Code *guess){
    std::vector<int> guessSeq=guess->getCode();

    int n=seq.size();
	int numIncorrect = 0;
	std::vector<int> posGood;

	//temporary vector for flagging duplicates when checking for correct element in incorrect position
	std::vector<int> tempSeq(seq);

	//first loop maps out instances of correct value and correct position in guess, 
	//where 1 is correct, and 0 is incorrect. stored as array. 
    for( int i=0; i<n;i=i+1){
        if(seq[i]==guessSeq[i]){
			posGood.push_back(1);	
        }
		else {
			posGood.push_back(0);
		}
    }
	/*checks first to identify if at the current counter position,
	//there has already been a value that is correct and in correct position, from posGood map.
	//if so, it breaks out of the loop and skips to the next counter position.
	//else, if the values of guess and seq are equal, a 1 is entered for that value in a histogram array.
	//histogram array has spaces for 0 to 9, maps number of times the guess has a right number, that is
	//not already in the correct position*/
	for (int j = 0; j < n; j++) {
		
		for (int k = 0; k < n; k++) {
			if (posGood[j] == 1 || posGood[k]==1) {
				continue;
			}
			else
            {
				if (guessSeq[k]==tempSeq[j]){
					numIncorrect += 1;
					tempSeq[k] = -1;
					break;
				}
			}
				
		}	
	}
	//third loop adds up the elements in the histogram array to 
	//return the number of correct values, but in the incorrect position.
    
	return numIncorrect;
}

//this is the code printing function to display the secret code
void Code::printCode() {
	int n = seq.size();
	for (int i = 0; i < n; i++) {
		std::cout << seq[i] << " ";
	}
}
