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

/*
class Deck{
public:
    node<int> *front;
    node<int> shuffle();
    friend void operator <<(std::ostream& ostr, int a);
    Deck(void);
private:
    node<int> getFront();
    
    
};
 node() : next(NULL)
 {}
 
 // constructor. initialize nodeValue and next
 node(const T& item, node<T> *nextNode = NULL) :
 nodeValue(item), next(nextNode)
*/
//A to King, club-diamond-heart-spade
//1 Ace, 11 Jack, 12 Queen, 13 King
Deck::Deck(){

    node<Card> *prev=front;
    //prev->next=front;
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
    while(frontW->next!=NULL){
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
    std::vector<int> ta(1);
    ta.clear();
    ta.back()=1;
    for(int i=1;i<53;i=i+1){
        ta.push_back(i);
    }
    node<Card> *prevA;
    prevA=front;
    int len=1;
    randomNumber rndA(0);
    int index=0;
    int numTemp=0;
    int endA;
    while(prevA->next!=NULL&&len!=0){
        index=std::abs((int)rndA.random())%len;
        numTemp=ta[index];
        endA=ta[len];
        ta[index]=endA;
        ta.pop_back();
      // std::cout<<numTemp<<std::endl;
        prevA->nodeValue.setSuit(getSuitName(numTemp%4));
        prevA->nodeValue.setValue((numTemp%13)+1);
        prevA=prevA->next;
        len=ta.size();
    }
    return *front;
}
