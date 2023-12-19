#include "Card.h"

Card::Card(const int &id, const std::string &dateAdded)
  : m_id(id), m_dateAdded(dateAdded), m_hasAccess(false), m_isLoggedIn(false) {}

const int Card::getId() const
{
  return m_id;
}

const std::string Card::getDateAdded() const
{
  return m_dateAdded;
}

const bool Card::getLoggedInStatus() const
{
  return m_isLoggedIn;
}
    
void Card::setLoggedInStatus(bool isLoggedIn)
{
  m_isLoggedIn = isLoggedIn;
}

const bool Card::getHasAccess() const
{
  return m_hasAccess;
}

void Card::setAccess(bool hasAccess) 
{
  m_hasAccess = hasAccess;
}