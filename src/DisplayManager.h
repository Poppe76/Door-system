#ifndef _DISPLAYMANAGER_H_
#define _DISPLAYMANAGER_H_

#include <string>
#include <vector>
#include "Card.h"

class DisplayManager
{
  private:
    const std::string REMOTE_OPTION         = "Remote open door";    
    const std::string LIST_ALL_OPTION       = "List all cards in system";
    const std::string LIST_LOGGED_IN_OPTION = "List all logged in";
    const std::string EDIT_OPTION           = "Add/Remove access";
    const std::string EXIT_OPTION           = "Exit";
    const std::string FAKE_SCAN_OPTION      = "FAKE TEST SCAN CARD";

    const std::string ADMIN_SCREEN        = "*****Admin*****";
    const std::string CARD_LIST_SCREEN    = "*****Card list - ";
    const std::string EDIT_CARD_SCREEN    = "*****Add / Edit*****";
    const std::string FAKE_SCAN_SCREEN    = "*****Fake Scan*****";

    const std::string STATUS_GREEN_MGS    = "CURRENT LAMP IS:Green";
    const std::string STATUS_ORANGE_MSG   = "CURRENT LAMP IS:Orange"; 
    const std::string STATUS_RED_MSG      = "CURRENT LAMP IS:Red";
    const std::string STATUS_OFF_MSG      = "CURRENT LAMP IS:Off";
    const std::string CONTINUE_MSG        = "Press SPACE to continue";
    const std::string SCAN_MSG            = "Please scan card to enter or X to back to admin menu"; 
    const std::string NO_CARDS            = "No cards added to list.";
    const std::string ENTER_CARD_NO       = "Enter card number>";
    const std::string HAS_ACCESS_MSG      = "This card has ";
    const std::string ENTER_ACCESS_MSG    = "Enter 1 for access, 2 for no access.";
    const std::string CARD_UPDATED_MSG    = "Card updated.";
    
    const std::string ADMIN_INPUT_ERROR     = "Please input valid menu selection from list.";    
    const std::string INVALID_INT_ERROR     = "Input an integer. Please try again.";    
    const std::string INVALID_ACCESS_ERROR  = "Please insert either 1 or 2 for access. Try again.";    
    const std::string ID_INPUT_ERROR        = "Invalid card id. Please input card id (integer) or enter 'x' to return to main menu.";  

  public:
    void displayError(const int &errorId);
    void displayAdminMenu();
    void displayCardList(const std::vector<Card> &cards, const bool showLoggedIn);
    void displayEditor();
    void displayFakeScan();
    void displayRemoteOpen();
    void displayAllLoggedIn(const std::vector<Card> &cards);
    void cardAccessStatus(bool &hasAccess, bool &isScan);
    void cardUpdated();

    DisplayManager() = default;
};

#endif // _DISPLAYMANAGER_H_