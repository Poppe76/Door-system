#ifndef _APPMANAGER_H_
#define _APPMANAGER_H_

#include <string>
#include <vector>

#include "DisplayManager.h"
#include "InputManager.h"
#include "Collection.h"

class AppManager
{
  private:
    int m_state;
    Collection m_cardCollection;
    DisplayManager m_displayManager;
    InputManager m_inputManager;

  public:
    void setup();
    void runLoop();

    AppManager();
    ~AppManager();
};


#endif // _APPMANAGER_H_