// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 2 MASTER MIND 2a
// Implemntation of the Deck Class
// Deck class contains linked lists of cards in a deck 52 card
// These cards have value 1-13 where 1 is an Ace, 11 is Jack, 12 is Queen, 13 is King
//class can create a card object given a void constructor
// additionally getSuitName and getValueName are used to correspond a suit(0,1,2,3) with a string
//and get value name corresponds the 1,11,12,13 to there rightful strings
//the print out operator<< has been overloaded for this calss
//a function to shuffle the cards along with a helper function to swap the cards has been created
//bellow is the prototype for these functions


#include "Deck.hpp"
#include "iostream"
#include "Card.hpp"
#include <vector>
#include <math.h>
#include <time.h>
//A to King, club-diamond-heart-spade
//1 Ace, 11 Jack, 12 Queen, 13 King
Deck::Deck()
//Deck constructor that develops a linked list of cards
//this card list has 52 cards which range from value
//1-13 where 11 is Jack,12 is Queen, 13 is King, 1 is Ace
//this is created by linking elements in a node class list togther
{
    node<Card> *prev=front;
    //gets the pointer to the object and created previous pointer as this
    for(int i=13;i>0;i=i-1){
    //value loop for card value
        for(int j=3;j>-1;j=j-1){
        //suit loop for card suit, note indcies are reverese to create list 13-1
        front=new node<Card>({i,getSuitName(j)});
        //creates a new card object with value given and suitName corresponding to j
        //where j 0 is Club, 1 is Diamond, 2 is Heart 3 is Spade
            front->next=prev;
            //links the front next card to be the previous card
            prev=front;
            //sets the new previous card to the current card
        }
    }
    
    
}
std::string Deck::getSuitName(int a)
//get suit name is a helper function
//that takes in a value a in bettween 0-3
//based off this value this corresponds to a suitname
//a value of 0 is Club, 1 is Diamond, 2 is Heart and 3 Spade
//if none are found then DNE is returned, the return is one
//of the strings described above
{
    //if statement to find case for suit type
    if(a==0){
        return "Club";//returns clubs
    }else if(a==1){
        return "Diamond";//return diamond
    }else if(a==2){
        return "Heart";//return heart
    }else if(a==3){
        return "Spade";//return spade
    }else{
        return "DNE";//retunr not found
    }
}
std::string getValueName(int a)
//get value name is a helper function
//that takes in a value a in bettween 1-13
//1-13 where 11 is Jack,12 is Queen, 13 is King, 1 is Ace
//based off this value this corresponds to a string value
//if none are found then DNE is returned, the return is one
//of the strings described above
{
    if(a<11&&a!=1){//finds if the value
        return std::to_string(a);//if numbers are 2-10 returns regluar number
    }else{
        if(a==11){//if the value is 11 this corresponds to Jack
            return "Jack";
        }else if(a==12){//if the value is 12 this corresponds to queen
            return "Queen";
        }else if(a==13){//if the value is 13 this corresponds to king
            return "King";
        }else if(a==1){//if the value is 1 this corresponds to Ace
            return "Ace";
        }else{//if not this will return with nothing found
            return "DNE";
        }
    }
}
std::ostream& operator <<(std::ostream& ostr, Deck& a)
//this is the function that overloads the printing operator for the deck class
//ostr is the stream object which is for the input
//a is a deck object which contains the whole deck in a linked list
//returns a printed format of the whole deck with format Card : Suit Value
//then returns an ostream object
{
    node<Card> *frontW=a.front;//gets the front of the linked list in the deck object
    int i=1;//counter for the card number
    while(frontW!=NULL){//waits until there is no card object seen
        ostr<<"Card "<< i<<": "<<frontW->nodeValue.getSuit()<< " "<<getValueName(frontW->nodeValue.getValue())<<std::endl;
        //creates the ostream with the format Card : Suit Value
        frontW=frontW->next;
        //goes to to the next point in the linked list
        i=i+1;//increments the counter variable
    }
    return ostr;//return out stream object
}


void Deck::shuffle()
//shuffle methods that takes a linked list
//randombly swaps elements 100 times in the array
//creates a random number for this swap each of these
//values are then passed to swap function to do swapping
//
{
    srand (time(NULL));
    //random variable for time
    for(int j=0;j<100;j=j+1){
    //does the swapping function
        int un=std::abs((int)rand())%13+1;
        int du=std::abs((int)rand())%13+1;
        //random numbers for the function for the value pairs
        //each of these random number variables are in range 1,13
        int te=std::abs((int)rand())%4;
        int fo=std::abs((int)rand())%4;
        //random numbers for the function for the value pairs
        //each of these random number variables are in range 1,
        swap(un, du, getSuitName(te), getSuitName(fo));
        //function performs swapping in linked lists of values designated un and du
        //and they need to have the suits name te and fo for them to be found
        //these values are then swapped in the linked list to create a random value
    }

}
void Deck::swap(int x, int y, std::string one, std::string two)
//swap function takes in two node values which are x and y with suits one and two
//performs the swapping of these two elements based on the conidition for it in the array
//first the function search for the two cards in the linked list and also has the variable
//which contains the previous values to each of the elemnts in the node list
{
    node<Card> *prevOne = NULL,*currOne = NULL;
    //variables for the previous and curr first node found with value x and suit one
    node<Card> *prevTwo = NULL,*currTwo= NULL;
    //variables for the previous and curr second node found with value y and suit two
    node<Card> *iter;
    //iter is a variable used to go through all the elments in the linked list
    iter=front;
    //set iter to front to start going through the elements
    if(x==y&&one==two){//checks to see if these values are the same
        return;//returns since cannot swap if they are the same element
    }
   //checks to see if the elemnt found is the first value if so sets currOne to this value
    if(x==iter->nodeValue.getValue()&&one==iter->nodeValue.getSuit()){
        currOne=front;
    }else{
        
        while(iter->next!=NULL){
           //goes through the elements in the list and checks if the last element is null
           prevOne=iter;
           //prevOne is set to the current iteration
           iter=iter->next;
           //set the linked list to next element in the linked list
           if(iter->nodeValue.getValue()==x && iter->nodeValue.getSuit()==one){
           //checks if the current value in the linked list has value and correct suit
                currOne=iter;
            //set the current linked list value the given current value
                break;
            //breaks through the function
            }
        }
    }
    
    iter=front;
    //set iter to front to start going through the elements
    
    //checks to see if the elemnt found is the first value if so sets currTwo to this value
    if(y==iter->nodeValue.getValue()&&two==iter->nodeValue.getSuit()){
        
        currTwo=front;
    }else{
        while(iter->next!=NULL){
            //goes through the elements in the list and checks if the last element is null
            prevTwo=iter;
            //prevOne is set to the current iteration
            iter=iter->next;
            //set the linked list to next element in the linked list
            if(iter->nodeValue.getValue()==y && iter->nodeValue.getSuit()==two){
            //checks if the current value in the linked list has value and correct suit
                currTwo=iter;
            //set the current linked list value the given current value
                break;
            //breaks through the function
            }
        }
    }
    //temporary variable for the storing node when neeeding to swap
    node<Card> *temp;
    if(prevOne==NULL){
        //checks to see if trying to swap first element, special case
        if(currOne->next==currTwo){
            currOne->next=currTwo->next;
            //set the next element for the first elemnt to the second elemnts next
            currTwo->next=currOne;
            //sets current element of the second one to the current element of the first
            front=currTwo;
            //and set the fronts element to the current second now
        }else{
        temp=currTwo->next;
         //creates a temporary variables for the next second element
        currTwo->next=currOne->next;
        //set the next element for the first elemnt to the temporary element
        currOne->next=temp;
        //sets previous element of the second one to the current element of the first
        prevTwo->next=currOne;
            //and set the fronts element to the current second now
        front=currTwo;
        }
        
    }else if(prevTwo==NULL){
        //checks to see if trying to swap first element, special case
        if(currTwo->next==currOne){
            currTwo->next=currOne->next;
            currOne->next=currTwo;
            front=currOne;
        }else{
            
        temp=currOne->next;
        //creates a temporary variables for the next primary element
        currOne->next=currTwo->next;
        //set the next element for the first elemnt to the second element
        currTwo->next=temp;
        //sets  second one to the temporary element
        prevOne->next=currTwo;
        //and set previous first object to the current second
        front=currOne;
            //sets new front element to the first one
            }
    }
    else if(currOne->next==currTwo){
    //checks to see if trying to swapping sequential element, special case
    prevOne->next=currTwo;
    //sets the previous of first element to current second element
    currOne->next=currTwo->next;
    //sets current one next to the current two next
    currTwo->next=currOne;
    //curr two next is now current one
        
    }else if(currTwo->next==currOne){
    //checks to see if trying to swapping sequential element, special case
    prevTwo->next=currOne;
    //sets the previous of second element to current first element

    currTwo->next=currOne->next;
    //sets current two next to the current one next
    currOne->next=currTwo;
    //curr one next is now current two
    }else{
        //case for swapping element in an location within the array
        temp=currTwo->next;
        //sets a temporary variable for the current next element
        prevOne->next=currTwo;
        //sets the previous one to the current second
        currTwo->next=currOne->next;
        //sets the current second to the current first
        currOne->next=temp;
        //sets current one next to the temporary
        prevTwo->next=currOne;
        //finally sets the previous second to the current one
    }
    
}

