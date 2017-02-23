// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 2 MASTER MIND 2b
// Implementation of the Deck Class
// Deck class contains linked lists of cards in a deck of 52 cards
// These cards have value 1-13 where 1 is an Ace, 11 is Jack, 12 is Queen, 13 is King
// class can create a card object given a void constructor
// additionally getSuitName is used to correspond a suit( 0, 1, 2, 3) with a string
// and getValueName is used to correspond integers ( 1, 11, 12, 13) to their rightful strings
// the print out operator<< has been overloaded for this calss
// a function to shuffle the cards along with a helper function to swap the cards has been created
// below is the prototype for these functions

#include "Deck.hpp"
#include "iostream"
#include "Card.hpp"
#include <vector>
#include <math.h>
#include "d_random.h"
#include <vector>
#include <climits>
// A to King, club-diamond-heart-spade
// 1 Ace, 11 Jack, 12 Queen, 13 King
Deck::Deck()
// Deck constructor that develops a linked list of cards
// this card list has 52 cards which range from value
// 1-13 where 11 is Jack,12 is Queen, 13 is King, 1 is Ace
// this is created by linking elements in a node class list togther
{
    front=NULL;
    node<Card> *prev = front;
    
    // gets the pointer to the object and created previous pointer as this
    for (int i = 13; i > 0; i = i - 1)
    {
    // value loop for card value
        for (int j = 3; j > -1; j = j - 1)
        {
            // suit loop for card suit, note indices are reverese to create list 13-1
            Card x(i,getSuitName(j),1);
            front = new node<Card>(x);
            // creates a new card object with value given and suitName corresponding to j
            // where j 0 is Club, 1 is Diamond, 2 is Heart 3 is Spade
            front -> next = prev;
            // links the front next card to be the previous card
            prev = front;
            // sets the new previous card to the current card
        }// end suit loop
    }// end value for loop
    frontDeal=prev;    
}

// destructor for Deck class. This deallocates the deck (implemented as a linked list) of cards. 
Deck::~Deck(){
    node<Card> *iter = front;
    node<Card> *prev = front;
    while (iter!=NULL)
    {
        prev=iter;
        iter=iter->next;
        delete prev;
    }    
}

// Function that returns the top card in the deck.
// Pointer variable iter assigned value of pointer to front card of deck.
// New card object "ret" created, gets assigned the data stored in the front card's node. 
// iter pointer assigned value of pointer to next card in deck, then front card assigned
// value of iter, so that the front card is updated and the old card is not at the front.
// Object of type Card, ret, is returned. 
Card Deck::deal(){
   node<Card> *iter = front;
    Card ret=front->nodeValue;
    iter=iter->next;
    front=iter;
    return ret;
}

// This function handles the playing of the game. 
void Deck::playFlip(){
    for(int i=0;i<24;i=i+1){
        deal();
    }
    int act=1;
    int score = 0;
    int carNum=0;
    act=bound_check("Would you like to play 0 for no,1 for yes", -1 , 2);
    while(act==1){
        std::cout<<"Receieve 10pts Ace, 5 pts King Queen Jack"<<std::endl;
        std::cout<<"0pts for 8,9,10, lose half for 7"<<std::endl;
        std::cout<<"lost all points 2,3,4,5,6 and +1 for heart"<<std::endl;
        std::cout<<"Would you like to apply another round"<<std::endl;
        carNum=bound_check("Choose a Card 1 to 24", 0 , 25);
        Card x =getCard(carNum);
        cout<<"Your Card"<<x<<endl;
        carVal(x, score);
        std::cout<<"Score"<<score<<std::endl;
        setCard(carNum);
        act=bound_check("Would you like to play 0 for no,1 for yes", -1 , 2);
    }
   
}

Card& Deck::getCard(int carNum){
    node<Card> *iter;
    iter=frontDeal;
    int num=0;
    while(num!=carNum){
        num=num+1;
        iter=iter->next;
    }

    return iter->nodeValue;
}
void Deck::setCard(int carNum){
    node<Card> *iter;
    iter=frontDeal;
    int num=0;
    while(num!=carNum){
        num=num+1;
        iter=iter->next;
    }
    
    iter->nodeValue.setActive(0);
}

void Deck::carVal(Card &x, int &score){
    if(x.getActive()==1){
    if(x.getValue()==1){
        score = score + 10;
    }else if(x.getValue()==11||x.getValue()==12||x.getValue()==13){
        score = score+5;
    }else if(x.getValue()==8||x.getValue()==9||x.getValue()==10){
        score = score+0;
    }else if(x.getValue()==7){
        score=(int)score/2;
    }else if(x.getValue()==2||x.getValue()==3||x.getValue()==4||x.getValue()==5||x.getValue()==6){
        score =0;
    }
    if(x.getSuit()=="Heart"){
        score=score+1;
    }
    }else{
        std::cout<<"card already flipped"<<std::endl;
    }    
}
void Deck::replace(Card c){
     node<Card> *prevOne = NULL, *currOne = NULL;
    node<Card> *iter;
    // iter is a variable used to go through all the elements in the linked list
    iter = front;
    if (c.getValue() == iter -> nodeValue.getValue() && c.getSuit() == iter -> nodeValue.getSuit())
    {
        currOne = front;
    }
    else
    {        
        while (iter -> next != NULL)
        {
            // goes through the elements in the list and checks if the last element is null
            prevOne = iter;
            // prevOne is set to the current iteration
            iter = iter -> next;
            // set the linked list to next element in the linked list
            if (iter -> nodeValue.getValue() == c.getValue() && iter -> nodeValue.getSuit() == c.getSuit() )
            {
                // checks if the current value in the linked list has value and correct suit
                currOne = iter;
                // set the current linked list value the given current value
                break;
                // breaks through the function
            }// end if
        }// end while
    }// end else
    iter=front;
    if(prevOne==NULL){
        front=currOne->next;
        currOne->next=NULL;
        while(iter->next!=NULL){
            iter=iter->next;
        }
        iter->next=currOne;
    }else{
        prevOne->next=currOne->next;
        currOne->next=NULL;
        while(iter->next!=NULL){
            iter=iter->next;
            }
        iter->next=currOne;
    }
}
std::string Deck::getSuitName(int a) const
// get suit name is a helper function
// that takes in a value a in bettween 0-3
// based off this value this corresponds to a suitname
// a value of 0 is Club, 1 is Diamond, 2 is Heart and 3 Spade
// if none are found then DNE is returned, the return is one
// of the strings described above
{
    // if statement to find case for suit type
    if (a == 0)
    {
        return "Club";// returns clubs
    }
    else if (a == 1)
    {
        return "Diamond";// return diamond
    }
    else if (a == 2)
    {
        return "Heart";// return heart
    }
    else if (a == 3)
    {
        return "Spade";// return spade
    }
    else
    {
        return "DNE";// return not found
    }
}
std::ostream& operator << (std::ostream& ostr, Deck& a)
// this is the function that overloads the printing operator for the deck class
// ostr is the stream object which is for the input
// a is a deck object which contains the whole deck in a linked list
// returns a printed format of the whole deck with format Card : Suit Value
// then returns an ostream object
{
    node<Card> *frontW = a.frontDeal;// gets the front of the linked list in the deck object
    int i = 1;// counter for the card number
    while (frontW != NULL)
    {// waits until there is no card object seen
        ostr << "Card " << i << ":" << frontW->nodeValue  << std::endl;
        // creates the ostream with the format Card : Suit Value
        frontW = frontW -> next;
        // goes to to the next point in the linked list
      
        i = i + 1;// increments the counter variable
    }
    return ostr;// return out stream object
}


void Deck::shuffle()
// shuffle methods that takes a linked list
// randomly swaps elements 100 times in the array
// creates a random number for this swap each of these
// values are then passed to swap function to do swapping
//
{
    randomNumber rndP(0);
    // random variable for time
    for (int j = 0; j < 100; j = j + 1)
    {
    // does the swapping function
        int rndValOne = std::abs((int)rndP.random()) % 13 + 1;
        int rndValTwo = std::abs((int)rndP.random()) % 13 + 1;
        // random numbers for the function for the value pairs
        // each of these random number variables are in range 1,13
        int rndSuitOne = std::abs((int)rand()) % 4;
        int rndSuitTwo = std::abs((int)rand()) % 4;
        // random numbers for the function for the value pairs
        // each of these random number variables are in range 0,3
        swap(rndValOne, rndValTwo, getSuitName(rndSuitOne), getSuitName(rndSuitTwo));
        // function performs swapping in linked lists of values designated rndValOne and rndValTwo
        // and they need to have the suits name rndSuitTwo and rndSuitOne for them to be found
        // these values are then swapped in the linked list to create a random value
        
    }

}
void Deck::swap(int x, int y, std::string one, std::string two)
// swap function takes in two node values which are x and y with suits one and two
// performs the swapping of these two elements based on the condition for it in the array
// first the function search for the two cards in the linked list and also has the variable
// which contains the previous values to each of the elements in the node list
{
    node<Card> *prevOne = NULL, *currOne = NULL;
    // variables for the previous and curr first node found with value x and suit one
    node<Card> *prevTwo = NULL, *currTwo= NULL;
    // variables for the previous and curr second node found with value y and suit two
    node<Card> *iter;
    // iter is a variable used to go through all the elments in the linked list
    iter = front;
    // set iter to front to start going through the elements
    if (x == y && one == two)
    {// checks to see if these values are the same
        return;// returns since cannot swap if they are the same element
    }
   // checks to see if the elemnt found is the first value if so sets currOne to this value
    if (x == iter -> nodeValue.getValue() && one == iter -> nodeValue.getSuit())
    {
        currOne = front;
    }
    else
    {
        
        while (iter -> next != NULL)
        {
           // goes through the elements in the list and checks if the last element is null
           prevOne = iter;
           // prevOne is set to the current iteration
           iter = iter -> next;
           // set the linked list to next element in the linked list
           if (iter -> nodeValue.getValue() == x && iter -> nodeValue.getSuit() == one)
           {
           // checks if the current value in the linked list has value and correct suit
                currOne = iter;
            // set the current linked list value the given current value
                break;
            // breaks through the function
            }// end if
        }// end while
    }// end else
    
    iter = front;
    // set iter to front to start going through the elements
    
    // checks to see if the elemnt found is the first value if so sets currTwo to this value
    if (y == iter -> nodeValue.getValue() && two == iter->nodeValue.getSuit())
    {
        currTwo = front;
    }
    else{
        while (iter -> next != NULL)
        {
            // goes through the elements in the list and until last element which is null
            prevTwo = iter;
            // prevOne is set to the current iteration
            iter = iter -> next;
            // set the linked list to next element in the linked list
            if(iter -> nodeValue.getValue() ==y && iter -> nodeValue.getSuit() == two)
            {
            // checks if the current value in the linked list has value and correct suit
                currTwo = iter;
            // set the current linked list value the given current value
                break;
            // breaks through the function
            }// end if
        }// end while
    }// end else
    
    // temporary variable for the storing node when neeeding to swap
    node<Card> *temp;
    if (prevOne == NULL)
    {
        // checks to see if trying to swap first element, special case
        if (currOne -> next == currTwo)
        {
            currOne -> next = currTwo -> next;
            // set the next element for the first elemnt to the second elemnts next
            currTwo -> next = currOne;
            // sets current element of the second one to the current element of the first
            front = currTwo;
            frontDeal=currTwo;
            // and set the fronts element to the current second now
        }
        else
        {
            temp = currTwo -> next;
            // creates a temporary variables for the next second element
            currTwo -> next = currOne -> next;
            // set the next element for the first elemnt to the temporary element
            currOne -> next = temp;
            // sets previous element of the second one to the current element of the first
            prevTwo -> next = currOne;
            // and set the fronts element to the current second now
            front = currTwo;
            frontDeal=currTwo;
        }
        
    }
    else if (prevTwo == NULL)
    {
        // checks to see if trying to swap first element, special case
        if (currTwo -> next == currOne)
        {
            currTwo -> next = currOne->next;
            // sets second nodes next to first nodes next
            currOne -> next = currTwo;
            // sets first node next to second node
            front = currOne;
            frontDeal=currOne;
            // resets first note to front
        }
        else
        {            
            temp = currOne -> next;
            // creates a temporary variables for the next primary element
            currOne -> next = currTwo -> next;
            // set the next element for the first elemnt to the second element
            currTwo -> next = temp;
            // sets  second one to the temporary element
            prevOne -> next = currTwo;
            // and set previous first object to the current second
            front = currOne;
            frontDeal=currOne;
            // sets new front element to the first one
        }
    }
    else if (currOne -> next == currTwo)
    {
        // checks to see if trying to swapping sequential element, special case
        prevOne -> next = currTwo;
        // sets the previous of first element to current second element
        currOne -> next = currTwo -> next;
        // sets current one next to the current two next
        currTwo -> next = currOne;
        // curr two next is now current one        
    }
    else if (currTwo -> next == currOne)
    {
        // checks to see if trying to swapping sequential element, special case
        prevTwo -> next = currOne;
        // sets the previous of second element to current first element
        currTwo -> next = currOne -> next;
        // sets current two next to the current one next
        currOne -> next = currTwo;
        // curr one next is now current two
    }
    else
    {
        // case for swapping element in an location within the array
        temp = currTwo -> next;
        // sets a temporary variable for the current next element
        prevOne -> next = currTwo;
        // sets the previous one to the current second
        currTwo -> next = currOne -> next;
        // sets the current second to the current first
        currOne -> next = temp;
        // sets current one next to the temporary
        prevTwo -> next = currOne;
        // finally sets the previous second to the current one
    }    
}

int Deck::bound_check(std::string prompt, int min , int max)
{
    int tr = 1;										  // flag used for remprompt of input
    int temp = 0;									  // holds temporary number for returning if in bound
    while (tr == 1)							          // repeat loop till correct input in bound
    {
        std::cout << prompt << std::endl;			  // prints the prompt
        std::cin >> temp;							  // inputs from keyboard single number
        if (std::cin.fail())						  // checks if input is a failure
        {
            std::cout << "NOT A NUMBER!" << std::endl;// prints not number
            std::cin.clear();						  // clears buffer
            std::cin.ignore(INT_MAX,'\n');			  // ignores error
            fflush(stdin);							  // flushes input
            continue;								  // contiune through
        }
        else
        {
            if (temp > min && temp < max)			  // checks if temp within min and max
            {
                tr=0;								  // sets flag to 0 for sucess
            }
            else									  // else, the user is in the incorrect range
            {
                std::cout << "Number not incorrect range please renter" << std::endl;
                std::cin.clear();					  // clears buffer
                fflush(stdin);						  // flushes input
            }
        }        
    }			 // end of the while loop
    return temp; // returns integer value checked to be within bounds
}				 // end of bound check function.
