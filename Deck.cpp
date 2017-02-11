//
//  Deck.cpp
//  Deck
//
//  Created by Anthony Bisulco on 2/6/17.
//  Copyright © 2017 Anthony Bisulco. All rights reserved.
//

#include "Deck.hpp"
#include "iostream"
#include "Card.hpp"
#include <vector>
#include "d_random.h"
#include <math.h>
#include <time.h>
//A to King, club-diamond-heart-spade
//1 Ace, 11 Jack, 12 Queen, 13 King
Deck::Deck(){
    node<Card> *prev=front;
    for(int i=13;i>0;i=i-1){
        for(int j=3;j>-1;j=j-1){
        front=new node<Card>({i,getSuitName(j)});

            front->next=prev;
            prev=front;
        }
    }
    
    
}
std::string Deck::getSuitName(int a){
    if(a==0){
        return "Club";
    }else if(a==1){
        return "Diamond";
    }else if(a==2){
        return "Heart";
    }else if(a==3){
        return "Spade";
    }else{
        return "DNE";
    }
}
std::ostream& operator <<(std::ostream& ostr, Deck& a){
    node<Card> *frontW=a.front;
    int i=1;
    while(frontW!=NULL){
        ostr<<"Card "<< i<<": "<<frontW->nodeValue.getSuit()<< " "<<frontW->nodeValue.getValue()<<std::endl;
        frontW=frontW->next;
        i=i+1;
    }
    return ostr;
}

node<Card> Deck::getFront(){
    return *front;
}
node<Card> Deck::shuffle(){
    srand (time(NULL));
    
    for(int j=0;j<100;j=j+1){
        int un=std::abs((int)rand())%13+1;
        int du=std::abs((int)rand())%13+1;
        int te=std::abs((int)rand())%3+1;
        int fo=std::abs((int)rand())%3+1;
        swap(un, du, getSuitName(te), getSuitName(fo));
    }
    return *front;

}
void Deck::swap(int x, int y, std::string one, std::string two){
    node<Card> *prevOne = NULL,*currOne = NULL;
    node<Card> *prevTwo = NULL,*currTwo= NULL;
    node<Card> *iter;
    iter=front;
    if(x==y&&one==two){
        return;
    }
    
    if(x==iter->nodeValue.getValue()&&one==iter->nodeValue.getSuit()){
        currOne=front;
    }else{
        while(iter->next!=NULL){
           
           prevOne=iter;
           iter=iter->next;
           if(iter->nodeValue.getValue()==x && iter->nodeValue.getSuit()==one){
               
                currOne=iter;
                break;
            }
        }
    }
    iter=front;
    if(y==iter->nodeValue.getValue()&&two==iter->nodeValue.getSuit()){
        currTwo=front;
    }else{
        while(iter->next!=NULL){
            
            prevTwo=iter;
            iter=iter->next;
            if(iter->nodeValue.getValue()==y && iter->nodeValue.getSuit()==two){
                
                currTwo=iter;
                break;
            }
        }
    }
    node<Card> *temp;
    if(prevOne==NULL){
        if(currOne->next==currTwo){
            currOne->next=currTwo->next;
            currTwo->next=currOne;
            front=currTwo;
        }else{
        temp=currTwo->next;
        currTwo->next=currOne->next;
        currOne->next=temp;
        prevTwo->next=currOne;
        front=currTwo;
        }
        
    }else if(prevTwo==NULL){
        if(currTwo->next==currOne){
            currTwo->next=currOne->next;
            currOne->next=currTwo;
            front=currOne;
        }else{
            
        temp=currOne->next;
        currOne->next=currTwo->next;
        currTwo->next=temp;
        prevOne->next=currTwo;
        front=currOne;
            }
    }
    else if(currOne->next==currTwo){

    prevOne->next=currTwo;
    currOne->next=currTwo->next;
    currTwo->next=currOne;
        
    }else if(currTwo->next==currOne){

    prevTwo->next=currOne;
    currTwo->next=currOne->next;
    currOne->next=currTwo;
    }else{
        temp=currTwo->next;
        prevOne->next=currTwo;
        currTwo->next=currOne->next;
        currOne->next=temp;
        prevTwo->next=currOne;
    }
    
}

