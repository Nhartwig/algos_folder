//
//  main.cpp
//  Project1bishar
//
//  Created by Anthony Bisulco on 1/17/17.
//  Copyright © 2017 Anthony Bisulco. All rights reserved.
//

#include <iostream>
#include "Code.hpp"
#include<vector>
int main(int argc, const char * argv[]) {
    // insert code here...
    int n=0,m=0;
    std::cout<<"Welecome to Master Mind Code Game"<<std::endl;
    std::cout<<"Input Code Length"<<std::endl;
    std::cin>>n;
    std::cout<<"Code Range"<<std::endl;
    std::cin>>m;
    Code mastermindSeq(n,m);
    int win=0;
    std::vector<int> seqCode=mastermindSeq.getCode();
     for(int i=0;i<10;i=i+1){
    std::vector<int> guessCode;
    int temp[5];
    std::cout<<"Input Number Bettween 0-"<<m<<std::endl;
    std::cin>>temp[0]>>temp[1]>>temp[2]>>temp[3]>>temp[4];
    guessCode={temp[0],temp[1],temp[2],temp[3],temp[4]};
    Code guessSeqinit(n,m);
    guessSeqinit.setCode(guessCode);
        int Cor=mastermindSeq.checkCorrect(&guessSeqinit);
        int inCor=mastermindSeq.checkIncorrect(&guessSeqinit);
    
        if(Cor==n){
            win=1;
            break;
        }
        
        std::cout<<"Trial Number:"<<i<<std::endl;
        std::cout<<"Correct: "<<Cor<<" Incorrect: "<<inCor<<std::endl;
        
    }
    
    
    if (win==1){
        std::cout<<"YOU WON!!!"<<std::endl;
    }else{
        std::cout<<"YOU LOST!!!"<<std::endl;
    }
    
    return 0;
}
