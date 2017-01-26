// Anthony Bisulco and Nathaniel Hartwig Fundementals of Algorithms MASTER MIND 1a
//Prototype of the Code Class
//Code Class performs the operation of generating secret codes
//Also the class is used to hold the user guess in another code object
//Intially all codes are random, although can be set using set code
//Prototype containts the inital definitions and whether public or private
#ifndef Code_hpp
#define Code_hpp

#include <stdio.h>
#include <vector>
#include <iostream>


// declaring the code class to be used throughout the project
//For full comments please see CPP file for full defnitinon
class Code{
	private://Private data hidden from user is seqeunece vector and
            //ability to intialize random vector
        std::vector<int> seq;//Code or Guess sequence
        void seqInitialize(int n = 1, int m = 1); //Intialize sequence vector
        //Intial values are 1 since 0 would be no game at all
    public:
        Code(int n = 1, int m = 1);//constror used to make object and intialize vector
        int checkCorrect(Code *guess);//check right digits in each location
        int checkIncorrect(Code *guess);//check digits not in same location no double counts
        std::vector<int> getCode() const;//returns intialized sequence vector
        void setCode(std::vector<int> codeSet);//sets the seqeunece vector for testing
		void printCode() const;//prints out given sequence code in terminal
};





#endif /* Code_hpp */
