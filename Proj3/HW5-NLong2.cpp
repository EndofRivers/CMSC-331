/***********************************************************
 **
 ** CMSC 331 Homework 5
 ** Nicholas J Long
 ** nlong2@umbc.edu
 ** Implementing my finite automata from Homework 4
 **
 **********************************************************/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>

typedef int state;
typedef char transition;

enum States {S,A,B,C,D,E};

int main() {
  std::fstream myfile; // fstream variable
  std::string data; // string extracted from file

  // Collection of 1D maps used in the 2D map stateMachine
  std::map <transition, state> stateS;
  stateS['+'] = A;
  stateS['-'] = A;
  stateS['0'] = E;
  stateS['1'] = E;
  stateS['2'] = E;
  stateS['3'] = E;  // This method of initiazing also works.
  stateS['4'] = E; 
  stateS['5'] = E;
  stateS['6'] = E;
  stateS['7'] = E;
  stateS['8'] = E;
  stateS['9'] = E;
  std::map <transition, state> stateA;
  stateA.insert(std::pair <transition, state> ('+', E));
  stateA.insert(std::pair <transition, state> ('-', E));
  stateA.insert(std::pair <transition, state> ('0', B));
  stateA.insert(std::pair <transition, state> ('1', C));
  stateA.insert(std::pair <transition, state> ('2', C));
  stateA.insert(std::pair <transition, state> ('3', C));
  stateA.insert(std::pair <transition, state> ('4', C));
  stateA.insert(std::pair <transition, state> ('5', C));
  stateA.insert(std::pair <transition, state> ('6', C));
  stateA.insert(std::pair <transition, state> ('7', C));
  stateA.insert(std::pair <transition, state> ('8', C));
  stateA.insert(std::pair <transition, state> ('9', C));
  std::map <transition, state> stateB;
  stateB.insert(std::pair <transition, state> ('+', E));
  stateB.insert(std::pair <transition, state> ('-', E));
  stateB.insert(std::pair <transition, state> ('0', E));
  stateB.insert(std::pair <transition, state> ('1', D));
  stateB.insert(std::pair <transition, state> ('2', D));
  stateB.insert(std::pair <transition, state> ('3', D));
  stateB.insert(std::pair <transition, state> ('4', D));
  stateB.insert(std::pair <transition, state> ('5', D));
  stateB.insert(std::pair <transition, state> ('6', D));
  stateB.insert(std::pair <transition, state> ('7', D));
  stateB.insert(std::pair <transition, state> ('8', E));
  stateB.insert(std::pair <transition, state> ('9', E));
  std::map <transition, state> stateC;
  stateC.insert(std::pair <transition, state> ('+', E));
  stateC.insert(std::pair <transition, state> ('-', E));
  stateC.insert(std::pair <transition, state> ('0', C));
  stateC.insert(std::pair <transition, state> ('1', C));
  stateC.insert(std::pair <transition, state> ('2', C));
  stateC.insert(std::pair <transition, state> ('3', C));
  stateC.insert(std::pair <transition, state> ('4', C));
  stateC.insert(std::pair <transition, state> ('5', C));
  stateC.insert(std::pair <transition, state> ('6', C));
  stateC.insert(std::pair <transition, state> ('7', C));
  stateC.insert(std::pair <transition, state> ('8', C));
  stateC.insert(std::pair <transition, state> ('9', C));
  std::map <transition, state> stateD;
  stateD.insert(std::pair <transition, state> ('+', E));
  stateD.insert(std::pair <transition, state> ('-', E));
  stateD.insert(std::pair <transition, state> ('0', D));
  stateD.insert(std::pair <transition, state> ('1', D));
  stateD.insert(std::pair <transition, state> ('2', D));
  stateD.insert(std::pair <transition, state> ('3', D));
  stateD.insert(std::pair <transition, state> ('4', D));
  stateD.insert(std::pair <transition, state> ('5', D));
  stateD.insert(std::pair <transition, state> ('6', D));
  stateD.insert(std::pair <transition, state> ('7', D));
  stateD.insert(std::pair <transition, state> ('8', E));
  stateD.insert(std::pair <transition, state> ('9', E));

  // 2D Map used for the FSM
  std::map <state, std::map<transition, state> > stateMachine;
  stateMachine.insert(std::pair <state, std::map<transition, state> > (S, stateS));
  stateMachine.insert(std::pair <state, std::map<transition, state> > (A, stateA));
  stateMachine.insert(std::pair <state, std::map<transition, state> > (B, stateB));
  stateMachine.insert(std::pair <state, std::map<transition, state> > (C, stateC));
  stateMachine.insert(std::pair <state, std::map<transition, state> > (D, stateD));

  // Map used for output
  std::map <state, std::string> finalStatus;
  finalStatus.insert(std::pair <state, std::string> (S, "Rejected"));
  finalStatus.insert(std::pair <state, std::string> (A, "Rejected"));
  finalStatus.insert(std::pair <state, std::string> (B, "Accepted"));
  finalStatus.insert(std::pair <state, std::string> (C, "Accepted"));
  finalStatus.insert(std::pair <state, std::string> (D, "Accepted"));
  finalStatus.insert(std::pair <state, std::string> (E, "Rejected"));
  
  // loops until the end of the file
  myfile.open("test-data.txt");
  while(!myfile.eof()) {
    
    getline(myfile, data, ' '); // saves the next value into data, delimited by a space( ' ' )
    data.erase(std::remove(data.begin(), data.end(), '\n'), // Trims the newline
	       data.end());

    state finalState = S; // Starting state
    // Loops for the duration of the string extracted
    for(unsigned int i = 0; i < data.length(); i++)
      finalState  = (( stateMachine[finalState] ) [data[i]] ); // updates finalState based on char

    std::cout << finalStatus[finalState] << ": " << data << std::endl;
  }// while
return 0;
}// main
