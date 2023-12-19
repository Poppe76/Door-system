#include <iostream>
#include <windows.h>
#include <unistd.h>

#include "DisplayManager.h"

//DisplayManager::DisplayManager() {};

void DisplayManager::displayError(const int &errorId)
{
  switch (errorId)
  {
  case 1:
    std::cout << ADMIN_INPUT_ERROR << std::endl << std::endl;    
    displayAdminMenu(); 
    break;
  case 2:
    std::cout << ID_INPUT_ERROR << std::endl;
    break;
  case 3:
    std::cout << INVALID_ACCESS_ERROR << std::endl;
    break;
  case 4:
    std::cout << INVALID_INT_ERROR << std::endl;
    break;
  default:
    break;
  } 
}

void DisplayManager::displayRemoteOpen()
{
  std::cout << std::endl << REMOTE_OPTION << std::endl;
  std::cout << STATUS_GREEN_MGS << std::endl << std::endl;
  sleep(3);
  std::cout << STATUS_RED_MSG << std::endl << std::endl;
}

void DisplayManager::displayAdminMenu()
{
  std::cout << std::endl << ADMIN_SCREEN << std::endl;
  std::cout << "1. " << REMOTE_OPTION << std::endl;
  std::cout << "2. " << LIST_ALL_OPTION << std::endl;
  std::cout << "3. " << LIST_LOGGED_IN_OPTION << std::endl;
  std::cout << "4. " << EDIT_OPTION << std::endl;
  std::cout << "5. " << EXIT_OPTION << std::endl;
  std::cout << "9. " << FAKE_SCAN_OPTION << std::endl;
}

void DisplayManager::displayCardList(const std::vector<Card> &cards, const bool showLoggedIn)
{
  std::string cardListType = showLoggedIn ? "logged in" : "all";
  std::cout << std::endl << CARD_LIST_SCREEN + cardListType + "*****" << std::endl;
  std::string access = "";  
  
  if(cards.size() > 0)
  {
    for(const Card &c : cards)
    {
      if(!showLoggedIn)
      {
        access = c.getHasAccess() ? " Access" : " No access";
      }    
      std::cout << c.getId() << access << " Added to system: " << c.getDateAdded() << std::endl;
    }
  }
  else 
  {
    std::cout << NO_CARDS << std::endl << std::endl;
  } 
  std::cout << CONTINUE_MSG << std::endl;
}

void DisplayManager::displayAllLoggedIn(const std::vector<Card> &cards)
{
  displayCardList(cards, true);
}

void DisplayManager::displayEditor()
{
  std::cout << std::endl << EDIT_CARD_SCREEN << std::endl;  
  std::cout << ENTER_CARD_NO; 
}

void DisplayManager::displayFakeScan()
{
  std::cout << std::endl << FAKE_SCAN_SCREEN << std::endl;  
  std::cout << SCAN_MSG << std::endl;
}

void DisplayManager::cardAccessStatus(bool &hasAccess, bool &isScan)
{
  if(hasAccess)
  {
    if(isScan)
    {
      std::cout << std::endl << STATUS_GREEN_MGS << std::endl;
    }
    else
    {
      std::cout << std::endl << HAS_ACCESS_MSG << "access." << std::endl;
      std::cout << ENTER_ACCESS_MSG << std::endl;
    }    
  }
  else
  {
    if(isScan)
    {
      std::cout << std::endl << STATUS_RED_MSG << std::endl;
    }
    else
    {
      std::cout << std::endl << HAS_ACCESS_MSG << "no access." << std::endl;
      std::cout << ENTER_ACCESS_MSG << std::endl;
    }    
  }
}

void DisplayManager::cardUpdated()
{
  std::cout << std::endl << CARD_UPDATED_MSG << std::endl;
}