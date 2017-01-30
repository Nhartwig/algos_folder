/*
 class mastermind {
private:
    Code nate;
public:
    mastermind(int n, int m);
    mastermind();
    void printSecretCode();
    Code humanGuess();
    response getResponse(Code guessCode, Code secretCode);
    bool isSolved(response user_response);
    void playGame();
    
};
*/
#include "Code.hpp"
#include "response.h"
#include "mastermind.h"
#include <iostream>
#include <vector>
int mastermind::getM(){
    return m;
}
int mastermind::getN(){
    return n;
}

mastermind::mastermind(int nA,int mA){
    n=nA;
    m=mA;
    
}
mastermind::mastermind(){
    n=5;
    m=10;
    
  
    
}
void mastermind::printSecretCode(){
    nate.printCode();
    
}
Code mastermind::humanGuess(){
    std::string prompt="Guess";
    std::vector<int> code;
    int n=this->getN();
    int m=this->getM();
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
    int cor=nate.checkCorrect(guessCode);
    int inCor=nate.checkIncorrect(guessCode);
    response retCode(inCor,cor);
    return retCode;
}


bool mastermind::isSolved(response user_response){
    int n=this->getN();
    if(n==user_response.getCorrect()){
        return true;
    }else{
        return false;
    }
}

void mastermind::playGame(){
    Code secretCode(this->getN(),this->getM());
    std::vector<int> sec=secretCode.getCode();
    nate.setCode(sec);
    this->printSecretCode();
    const int MAX_TURNS=10;
    int win=0;
    while(win==0){
        Code guessCode=this->humanGuess();
        response one=this->getResponse(&guessCode);
        std::cout<<one;
        if(this->isSolved(one)){
            win=1;
        }
        
    }
    std::cout<<"YOU WIN NIGGA"<<std::endl;
}
