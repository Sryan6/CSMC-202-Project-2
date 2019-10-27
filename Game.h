//Title: Game.h
//Author: Jeremy Dixon
//Date: 2/22/2019
//Description: This is part of the Alchemist Project in CMSC 202 @ UMBC

#ifndef GAME_H //Header Guard
#define GAME_H //Header Guard
#include <fstream>
#include "Element.h"
#include "Alchemist.h"

//Constants (additional constants allowed)
const string PROJ2_DATA = "proj2_data.txt"; //File constant

//Additional HELPER functions allowed to be added as needed

class Game{
public:
  /* Name: Game() Default Constructor
  // Desc - Builds a new game by: 
  // 1. Loads all Alchemy recipes into m_elements (by making elements)
  // 2. Asks user for their alchemist's name (store in m_myAlchemist as m_myName)
  // 3. Adds fire, water, air, and earth to m_myElements (in m_myAlchemist)
  // Preconditions - None
  // Postconditions - m_elements is populated
  */ 
  Game(); //Default Constructor
  // Name: LoadElements
  // Desc - Loads each element into m_elements from file
  // Preconditions - Requires file with valid element data
  // Postconditions - m_element is populated with element structs
  void LoadElements();
  // Name: StartGame()
  // Desc - Manages the game itself including win conditions continually
  //         calling the main menu 
  // Preconditions - Player is placed in game
  // Postconditions - Continually checks to see if player has entered 5
  void StartGame();
  // Name: DisplayMyElements()
  // Desc - Displays the current elements
  // Preconditions - Player has elements
  // Postconditions - Displays a numbered list of elements
  void DisplayElements();
  // Name: MainMenu()
  // Desc - Displays and manages menu
  // Preconditions - Player has an Alchemist
  // Postconditions - Returns number including exit
  int MainMenu();
  // Name: CombineElements()
  // Desc - Attempts to combine known elements
  // Preconditions - Alchemist is populated with elements
  // Postconditions - May add element to Alchemist's list of elements
  void CombineElements();
  // Name: RequestElement()
  // Desc - Requests element to use to merge
  // Preconditions - Alchemist has elements to try and merge
  // Postconditions - Returns
  void RequestElement(int &choice);
  // Name: SearchRecipes()
  // Desc - Searches recipes for two strings
  // Preconditions - m_elements is populated
  // Postconditions - Returns int index of matching recipe
  int SearchRecipes(string, string);
  // Name: CalcScore()
  // Desc - Displays current score for Alchemist
  // Preconditions - Alchemist is populated with elements
  // Postconditions - None
  void CalcScore();
  // Name: GameTitle()
  // Desc - Title for Game (Do not edit)
  // Preconditions - None
  // Postconditions - None
  void GameTitle(){
    cout << "**************************************************************" << endl;
    cout << "    AAA   L     CCCCC  H   H  EEEEE  M   M  I  SSSSS  TTTTT   " << endl;
    cout << "   A   A  L     C      H   H  E      MM MM  I  S        T     " << endl;
    cout << "   AAAAA  L     C      HHHHH  EEEEE  M M M  I  SSSSS    T     " << endl;
    cout << "   A   A  L     C      H   H  E      M   M  I      S    T     " << endl;
    cout << "   A   A  LLLLL CCCCC  H   H  EEEEE  M   M  I  SSSSS    T     " << endl;
    cout << "**************************************************************" << endl;
  }
private:
  Alchemist m_myAlchemist; //Player's Alchemist for the game
  Element m_elements[PROJ2_SIZE]; //All elements in the game (loaded from file)
};

#endif //Exit Header Guard
