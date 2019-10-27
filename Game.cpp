/*************************************************
 ** File: Game.cpp
 ** Project: CMSC 202 Project 2, Game
 ** Author: Steven Ryan
 ** Date: 3/4/19
 ** Section 12
 ** E-Mail: sryan6@umbc.edu
 ** 
 ** This file will run the game and implement
 ** methods unique to the game.
 ************************************************/

//Preprocessor Directives
#include "Game.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

//Constants
const int AIR_VALUE = 1;
const int EARTH_VALUE = 102;
const int FIRE_VALUE = 118;
const int WATER_VALUE = 365;
const int LIST_ELEMENTS = -1;

//Default Constructor
Game::Game(){
  //Loads Elements and prints title
  GameTitle();
  LoadElements();
  //loads the 4 basic elements
  m_myAlchemist.AddElement(m_elements[AIR_VALUE]);
  m_myAlchemist.AddElement(m_elements[EARTH_VALUE]);
  m_myAlchemist.AddElement(m_elements[FIRE_VALUE]);
  m_myAlchemist.AddElement(m_elements[WATER_VALUE]);
  string alchemistName;
  //inputs Alchemist Name
  cout << "What is the name of the Alchemist?" << endl;
  if(cin.peek() == '\n'){
    cin.ignore();
  }
  //Has alchemistName hold the name of the Alchemist
  getline(cin, alchemistName);
  m_myAlchemist.SetName(alchemistName);
}

void Game::LoadElements(){
  ifstream inputStream;
  
  inputStream.open(PROJ2_DATA);

  //if the file opens, load elements, else produce an error message
  if(inputStream.is_open()){
    int i = 0;
    //while the file can be read
    while(inputStream){
      string name;
      string element1;
      string element2;

      //use commas as delimiters to load elements into the array of all elements
      getline(inputStream, name, ',');
      getline(inputStream, element1, ',');
      if(inputStream.peek() == '\n')
	inputStream.ignore();
      getline(inputStream, element2);
      Element newElement(name, element1, element2);
      m_elements[i] = newElement;
      i++;
    }
  }
  //produces error message
  else{
    cerr << "Error: File could not be opened.";
  }
  //closes file
  inputStream.close();
  cout << PROJ2_SIZE << " Elements loaded" << endl;
}

void Game::StartGame(){
  //prints menu and recieves choice
  int choice = MainMenu();
  //while the player does not choose to quit
  while(choice != 4){
    //if player picks 1
    if(choice == 1){
      DisplayElements();
    }
    //if player picks 2
    else if(choice == 2){
      CombineElements();
    }
    //if player picks 3
    else if(choice == 3){
      CalcScore();
    }
    //if player does not choose 4, prompt again
    if(choice !=4){
      choice = MainMenu();
    }
  }
}
//Calls the Alchemist's DisplayElements function
void Game::DisplayElements(){
  m_myAlchemist.DisplayElements();
}
//prints Main Menu and gets a return value as a choice
int Game::MainMenu(){
  //prints menu
  int returnValue;
  cout << "What would you like to do?" << endl;
  cout << "1. Display the Alchemist's Elements" << endl;
  cout << "2. Attempt to Merge Elements" << endl;
  cout << "3. See Score" << endl;
  cout << "4. Quit" << endl;
  cin >> returnValue;
  //Validates input
  while((returnValue < 1) || (returnValue > 4)){
    cout << "Please choose a valid number 1-4" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Display the Alchemist's Elements" << endl;
    cout << "2. Attempt to Merge Elements" << endl;
    cout << "3. See Score" << endl;
    cout << "4. Quit" << endl;
    cin >> returnValue;
  }
  //returns choice
  return returnValue;
}

void Game::CombineElements(){
  int choice1;
  int choice2;
  
  //prompts user for Element choice 1
  cout << "Which elements would you like to merge?" << endl;
  cout << "To list known elements enter -1" << endl;
  cin >> choice1;
  //If user chooses -1, Display Elements
  if(choice1 == LIST_ELEMENTS){
    DisplayElements();
  }
  //Validates input
  RequestElement(choice1);

  //prompts user for Element choice 2
  cout << "Which elements would you like to merge?" << endl;
  cout << "To list known elements enter -1" << endl;
  cin >> choice2;
  //If user chooses -1, Display Elements
  if(choice2 == LIST_ELEMENTS){
    DisplayElements();
  }
  //Validates input
  RequestElement(choice2);

  //Decremenets choice1 and choice2 to fit in the indexing from the array.
  choice1--;
  choice2--;

  //Gets the array index if the recipe is found, if not, holds -1 value
  int elementID = SearchRecipes(m_myAlchemist.GetElement(choice1).m_name,
				m_myAlchemist.GetElement(choice2).m_name);

  //shorthand for the elements chosen by the user input
  Element element1 = m_myAlchemist.GetElement(choice1);
  Element element2 = m_myAlchemist.GetElement(choice2);

  //if there is no element that uses those two reactants
  if(elementID == -1){
    cout << "Nothing happened when you tried to combine "
    << element1.m_name << " and "
    	 << element2.m_name << endl;
  }
  //else if an element matches the two reactants
  else{
    cout << element1.m_name << " combined with "
	 << element2.m_name << " to make "
	 << m_elements[elementID].m_name << endl;

    //if the element chosen was a repeat
    if(m_myAlchemist.CheckElement(m_elements[elementID]) == true){
      m_myAlchemist.AddRepeat();
    }
    //if the element was not repeated, add it
    else{
      m_myAlchemist.AddElement(m_elements[elementID]);
    }
  }

  //increment attempts by 1
  m_myAlchemist.AddAttempt();
}
//Validates input for CombineElement
void Game::RequestElement(int &choice){
  //while the choice is one of the options provided
  while((choice < 1) || (choice >= m_myAlchemist.GetNumElements() + 1)){
    cout << "Which elements would you like to merge?" << endl;
    cout << "To list known elements enter -1" << endl;
    cin >> choice;
    //Display elements if -1 is chosen.
    if(choice == -1){
      DisplayElements();
    }
  }
}

int Game::SearchRecipes(string element1, string element2){
  //iterates through the list of all elements
  for(int i = 0; i < PROJ2_SIZE; i++){
    //compares the elements needed to make something and the two chosen and if so,
    //returns the array value.
    if((element1 == m_elements[i].m_element1) && (element2 == m_elements[i].m_element2)){
      return i;
    }
    else if((element1 == m_elements[i].m_element2) &&
	    (element2 == m_elements[i].m_element1)){
      return i;
    }
  }
  //value returned if the two elements don't match a created element
  return -1;
}

void Game::CalcScore(){
  //Prints out various stats through getter functions
  cout << "***The Alchemist***" << endl;
  cout << "The Great Alchemist " << m_myAlchemist.GetName() << endl;
  cout << "The Alchemist has tried to combine " << m_myAlchemist.GetAttempts()
       << " elements" << endl;
  cout << "The Alchemist has repeated attempts " << m_myAlchemist.GetRepeats()
       << " times" << endl;
  cout << "The Alchemist found " << m_myAlchemist.GetNumElements()
       << " out of " << PROJ2_SIZE << " elements." << endl;

  //sets the formatting of the percentage being printed out and prints it out
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  double percentComplete = double(m_myAlchemist.GetNumElements()) / double(PROJ2_SIZE);
  cout << "You have completed " << percentComplete
       << "% of the elements." << endl;
}
