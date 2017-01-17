//
//  Code.cpp
//  Project1bishar
//
//  Created by Anthony Bisulco on 1/17/17.
//  Copyright © 2017 Anthony Bisulco. All rights reserved.
//

#include "Code.hpp"
#include "d_random.h"
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


Code::Code(int n , int m){
    
    seqInitialize(n, m);
}

void Code::seqInitialize(int n, int m){
    randomNumber rndA(1);
    srand( time(0));
    for(int i=0; i<n;i=i+1){
        seq.push_back((rand()%(m-1)));
    }
}

std::vector<int> Code::getCode(){
    return seq;
}

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
void Code::setCode(std::vector<int> codeSet){
    seq=codeSet;
}
int Code::checkIncorrect(Code *guess){
    std::vector<int> guessSeq=guess->getCode();
    int n=seq.size();
    int incorrect=0;
    int hist[10]={0,0,0,0,0,0,0,0,0,0};
    for( int i=0; i<n;i=i+1){
        if(seq[i]!=guessSeq[i]){
            incorrect=incorrect+1;
        }
    }
    
    return incorrect;
}
