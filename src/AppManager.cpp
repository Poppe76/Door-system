#include "AppManager.h"

AppManager::AppManager()
:m_inputManager(m_displayManager, m_cardCollection, m_state)
{
  m_state = 1;
}
AppManager::~AppManager() { 
};

void AppManager::setup()
{  
  m_displayManager.displayAdminMenu();
  runLoop();
}

void AppManager::runLoop()
{
  while (m_state != 0)
  {
    if(m_state == 1 || m_state == 5 || m_state == 6 || m_state == 9) 
    {
      m_inputManager.listenToInput();
    }
    else if(m_state == 3)
    {
      m_inputManager.keyPressed();
    }    
  }  
}