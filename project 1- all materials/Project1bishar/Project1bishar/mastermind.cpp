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

mastermind::mastermind(int n,int m){
    n=n;
    m=m;
    
}
mastermind::mastermind(){
    n=5;
    m=10;
    
  
    
}
void mastermind::printSecretCode(){
    nate.printCode();
    
}
Code mastermind::humanGuess(){
    int n=this->getN();
    int m=this->getM();
    std::vector<int> code;
    std::cout << "Please enter numbers for the code sequence between 0 and" << (m)-1 << std::endl;
    int j;
    int wrong=1;
    while (wrong >0){
        code.clear();
        wrong = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> j;
            if(j<m){
                code.push_back(j);
            }
            else {
                wrong = 1;
            }
        }
    }
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
}
