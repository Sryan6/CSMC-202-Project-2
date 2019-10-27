/************************************************
 ** File: Alchemist.cpp
 ** Project: CMSC 202 Project 2, Alchemist
 ** Author: Steven Ryan
 ** Date: 3/4/19
 ** Section: 12
 ** E-Mail: sryan6@umbc.edu
 **
 ** This file is used to write the source code
 ** for the Alchemist methods
 ***********************************************/

//Preprocessor Directives
#include "Alchemist.h"
#include "Element.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

//Default Constructor
Alchemist::Alchemist(){
  m_myName = "John Doe";
  m_attempts = 0;
  m_repeats = 0;
  m_numElements = 0;
}

//Overloaded Constructor
Alchemist::Alchemist(string name){
  m_myName = name;
  m_attempts = 0;
  m_repeats = 0;
  m_numElements = 0;
}

//Getter function for Alchemist Name
string Alchemist::GetName(){
  return m_myName;
}

//Setter function for Alchemist Name
void Alchemist::SetName(string name){
  m_myName = name;
}

//Prints out elements belonging to the Alchemist
void Alchemist::DisplayElements(){
  for(int i = 0; i < m_numElements; i++){
    cout << i + 1 << ". " << m_myElements[i].m_name << endl;
  }
}

//Getter function for the number of elements the Alchemist knows
int Alchemist::GetNumElements(){
  return m_numElements;
}

//Returns true if the element being checked is already known to the Alchemist.
bool Alchemist::CheckElement(Element element){
  for(int i = 0; i < PROJ2_SIZE; i++){
    if((element.m_name).compare(m_myElements[i].m_name) == 0){
      return true;
    }
  }
  return false;
}

//Adds a new element to the list of known elements.
void Alchemist::AddElement(Element element){
  if(CheckElement(element) == false){
    m_myElements[m_numElements] = element;
    m_numElements++;
  }
}

//Getter function for the element needed at a certain slot
Element Alchemist::GetElement(int elementNum){
  return m_myElements[elementNum];
}

//Increments the Attempts by 1
void Alchemist::AddAttempt(){
  m_attempts++;
}

//Getter function for Attempts
int Alchemist::GetAttempts(){
  return m_attempts;
}

//Increments the Repeats by 1
void Alchemist::AddRepeat(){
  m_repeats++;
}

//Getter function for Repeats
int Alchemist::GetRepeats(){
  return m_repeats;
}
