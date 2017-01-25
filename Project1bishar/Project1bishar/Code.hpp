//
//  Code.hpp
//  Project1bishar
//
//  Created by Anthony Bisulco on 1/17/17.
//  Copyright © 2017 Anthony Bisulco. All rights reserved.
//

#ifndef Code_hpp
#define Code_hpp

#include <stdio.h>
#include <vector>
#include <iostream>


// declaring the code class to be used throughout the project
class Code{
	private:
        std::vector<int> seq;
        void seqInitialize(int n = 0, int m = 0); 
    public:
        Code(int n = 0,int m = 0);
        int checkCorrect(Code *guess);
        int checkIncorrect(Code *guess);
        std::vector<int> getCode();
        void setCode(std::vector<int> codeSet);
		void printCode();
};





#endif /* Code_hpp */
