//Title: Alchemist.h
//Author: Jeremy Dixon
//Date: 2/22/2019
//Description: This is part of the Alchemist Project in CMSC 202 @ UMBC
// This is the pointer version header files

#ifndef ALCHEMIST_H //Include/Header Guard
#define ALCHEMIST_H //Include/Header Guard

#include "Element.h" //Include for the element struct
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Constants (allowed to add more as needed)
const int PROJ2_SIZE = 390;

// class - allowed to add HELPER functions only
class Alchemist{
 public:
  // Name: Alchemist() - Default Constructor
  // Desc: Used to build a new Alchemist
  // Preconditions - Requires default values
  // Postconditions - Creates a new Alchemist
  Alchemist();
  // Name: Alchemist(name) - Overloaded constructor
  // Desc - Used to build a new Alchemist
  // Preconditions - Requires name
  // Postconditions - Creates a new Alchemist
  Alchemist(string name);
  // Name: GetName()
  // Desc - Getter for Alchemist name
  // Preconditions - Alchemist exists
  // Postconditions - Returns the name of the Alchemist
  string GetName();
  // Name: SetName(string)
  // Desc - Allows the user to change the name of the Alchemist
  // Preconditions - Alchemist exists
  // Postconditions - Sets name of Alchemist
  void SetName(string name);
  // Name: DisplayElements()
  // Desc - Displays a numbered list of all elements known by the Alchemist
  // Preconditions - Alchemist exist
  // Postconditions - None
  void DisplayElements();
  // Name: GetNumElements()
  // Desc - Returns number of elements known by the Alchemist
  // Preconditions - Alchemist exists
  // Postconditions - None
  int GetNumElements();
  // Name: CheckElement(Element)
  // Desc - Checks to see if the Alchemist has an element
  // Preconditions - Alchemist already has elements
  // Postconditions - Returns true if Alchemist has element else false
  bool CheckElement(Element);
  // Name: AddElement(Element)
  // Desc - Adds element to m_myElements if not known increases numElements
  // Preconditions - Alchemist exists and new element not already known
  // Postconditions - Adds element to m_myElements
  void AddElement(Element);
  // Name: GetElement(int)
  // Desc - Checks to see if the alchemist has an element
  // Preconditions - Alchemist already has elements
  // Postconditions - Returns element at index
  Element GetElement(int);
  // Name: AddAttempt
  // Desc - Increments attempts
  // Preconditions - Alchemist attempts a merge
  // Postconditions - Increments every time a merge is attempted
  void AddAttempt();
  // Name: GetAttempts()
  // Desc - Returns number of attempts for that Alchemist
  // Preconditions - Alchemist exists
  // Postconditions - Returns total number of attempts
  int GetAttempts();
  // Name: AddRepeat()
  // Desc - Increments repeats for every time an element has already been found
  // Preconditions - Alchemist attempts a merge
  // Postconditions - Increments every time a merge yields an element already found
  void AddRepeat();
  // Name: GetRepeats()
  // Desc - Returns number of repeats for that Alchemist
  // Preconditions - Alchemist exists
  // Postconditions - Returns total number of repeats
  int GetRepeats();
private:
  string m_myName; //Name of Alchemist
  int m_attempts; //Total Combination Attempts
  int m_repeats; //Combination Attempts Repeated
  int m_numElements; //Number of elements known to the Alchemist
  Element m_myElements[PROJ2_SIZE] = {}; //List of elements known to the Alchemist
};

#endif //Exit Header Guard
