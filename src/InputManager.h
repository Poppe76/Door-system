#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include "Card.h"
#include "DisplayManager.h"
#include "Collection.h"
#include "InputManager.h"

class InputManager
{
  private:
    const std::string m_validMainMenuInput [6] = { "1", "2", "3", "4", "5", "9"};  
    int &m_state;   // scan, list, etc   // rename to inputState?
    int m_currentCardId;
    DisplayManager m_displayManager;
    Collection m_cardCollection;  

    void handleAdminInput(std::string &input);
    void handleAddEditInput(std::string &input);
    void handleEditInput(std::string &input);
    void handleFakeScan(std::string &input);
    void processInput(std::string &input);    
    bool isInt(std::string &input);

  public:
    void listenToInput();
    void keyPressed();

    InputManager(const DisplayManager &displayManager, const Collection &cardCollection, int &state);
};

#endif // _INPUTMANAGER_H_