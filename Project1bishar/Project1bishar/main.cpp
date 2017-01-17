//
//  main.cpp
//  Project1bishar
//
//  Created by Anthony Bisulco on 1/17/17.
//  Copyright © 2017 Anthony Bisulco. All rights reserved.
//

#include <iostream>
#include "Code.hpp"
#include<
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
    for(int i=0;i<10;i=i+1){
       Code guessSeqinit(n,m);
        int Cor=mastermindSeq.checkCorrect(&guessSeqinit);
        int inCor=mastermindSeq.checkIncorrect(&guessSeqinit);
        if(Cor==n){
            win=1;
            break;
        }
        
        std::cout<<"Incorrect "<<
        std::cout<<"Correct: "<<Cor<<" Incorrect: "<<inCor<<std::endl;
        
        //DEBUG GAME CODE
        v
    }
    if (win==1){
        std::cout<<"YOU WON!!!"<<std::endl;
    }else{
        std::cout<<"YOU LOST!!!"<<std::endl;
    }
    
    return 0;
}
