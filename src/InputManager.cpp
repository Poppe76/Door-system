#include <iostream>
#include <iomanip>
#include <Windows.h>

#include "InputManager.h"

InputManager::InputManager(const DisplayManager &displayManager, const Collection &cardCollection, int &state) 
  : m_displayManager(displayManager), m_cardCollection(cardCollection), m_state(state)
{
  
}   

void InputManager::handleAdminInput(std::string &input)
{
  if(input == "1")
  {
    //std::cout << "ADMIN menu - clicked 1." << std::endl;
    m_displayManager.displayRemoteOpen();
    m_state = 2;
    m_displayManager.displayAdminMenu();
    m_state = 1;
  }
  else if(input == "2")
  {
    //std::cout << "ADMIN menu - clicked 2." << std::endl;
    m_state = 3;
    m_displayManager.displayCardList(m_cardCollection.getAllItems(), false);
  }
  else if(input == "3")
  {
    //std::cout << "ADMIN menu - clicked 3." << std::endl;
    m_state = 3;
    m_displayManager.displayAllLoggedIn(m_cardCollection.getLoggedIn());
  }
  else if(input == "4")
  {
    //std::cout << "ADMIN menu - clicked 4." << std::endl;
    m_state = 5;
    m_displayManager.displayEditor();
  }
  else if(input == "5")
  {
    std::cout << "Exiting application." << std::endl;
    m_state = 0;
  }
  else if(input == "9")
  {
    //std::cout << "ADMIN menu - clicked 9." << std::endl;
    m_displayManager.displayFakeScan();
    m_state = 9;
  }
}

void InputManager::handleAddEditInput(std::string &input)
{
  if(isInt(input))
  {   
    int inputInt = std::stoi(input);    
    const Card& card = m_cardCollection.getCardByIdOrNew(inputInt);
    m_currentCardId = card.getId();
    bool hasAccess = card.getHasAccess();
    bool isScan = false;
    m_displayManager.cardAccessStatus(hasAccess, isScan);
    m_state = 6;
  }
  else
  {
    m_displayManager.displayError(4);
  } 
}

void InputManager::handleEditInput(std::string &input)
{
  bool cardAccess;
  if(input == "1")
  {
    cardAccess = true;      
  }
  else if(input == "2")
  {
    cardAccess = false;
  }
  else 
  {
    m_displayManager.displayError(3);
    return;
  }
  m_cardCollection.updateCardAccess(m_currentCardId, cardAccess);
  m_displayManager.cardUpdated();
  m_displayManager.displayAdminMenu();
  m_state = 1;
}

void InputManager::handleFakeScan(std::string &input)
{
  if(isInt(input)) 
  {
    int inputInt = std::stoi(input);
    bool hasAccess = m_cardCollection.scanCard(inputInt);
    bool isScan = true;
    m_displayManager.cardAccessStatus(hasAccess, isScan);
    m_state = 1;
    m_displayManager.displayAdminMenu();
  }    
  else if(input == "x")
  {
    m_state = 1;
    m_displayManager.displayAdminMenu();
  }    
  else
  {
    m_displayManager.displayError(2);
    return;
  }
}

void InputManager::keyPressed()
{
  if(GetAsyncKeyState(VK_SPACE) & 0x80000000)
  {
    m_state = 1;
    m_displayManager.displayAdminMenu();
  }
}

void InputManager::listenToInput()
{
  std::string input;
  std::cin >> input;
  processInput(input);
}

void InputManager::processInput(std::string &input)
{
  //std::cout << "processInput() - input:" << input  << " | m_state:" << m_state << std::endl;

  if(m_state == 1)  // Admin menu
  {
    if (std::find(std::begin(m_validMainMenuInput), std::end(m_validMainMenuInput), input) == std::end(m_validMainMenuInput))
    {
      m_displayManager.displayError(1);
      return;
    }
    else 
    {
      handleAdminInput(input);
    }
  } 
  else if(m_state == 5)  // Add / Edit
  {
    //std::cout << "Show edit menu." << std::endl;
    handleAddEditInput(input); 
  }
  else if(m_state == 6)  // Edit
  {
    //std::cout << "Show edit menu 2." << std::endl;
    handleEditInput(input);
  }
  else if(m_state == 9)
  {
    handleFakeScan(input);   
  }
}

bool InputManager::isInt(std::string &input)
{
  for(int i=0; i<input.size(); i++)
  {
    if(isdigit(input[i]) == false) return false;
  }
  return true;
}

