#include <iostream>
#include <ctime>

#include "Collection.h"

//Collection::Collection() {}

const std::vector<Card>& Collection::getAllItems()
{
  return m_cards;
}

Card& Collection::addCard(int &id)
{
  Card newCard(id, getDateNow());
  m_cards.push_back(newCard);
  return m_cards.back();
}

Card& Collection::getCardByIdOrNew(int &id)
{
  if(m_cards.size() > 0)
  {
    for(Card& c : m_cards)
    {
      if(c.getId() == id)
      {
        return c;
      }
    }
  }
  std::cout << "Card does not exist. Setting up new one." << std::endl;   // breaking pattern a bit by printing here... but...
  return addCard(id);
}

void Collection::removeCardById(int &id)
{
  // delete card
}

bool Collection::scanCard(int &id)
{
  for(Card& c : m_cards)  // remember ref on Card c to not get a copy!!
  {
    if(c.getId() == id)
    {
      c.setLoggedInStatus(c.getHasAccess());
      return c.getHasAccess();
    }
  }
  return false;   // if card doesn't exist, return false
}

void Collection::updateCardAccess(int id, bool newAccess)   // ta bort ref och sätt som const
{
  Card& updatedCard = getCardByIdOrNew(id);
  updatedCard.setAccess(newAccess);
}

std::vector<Card> Collection::getLoggedIn()
{
  std::vector<Card> loggedInCards;

  for(const Card& c : m_cards)
  {
    if(c.getLoggedInStatus())
    {
      loggedInCards.push_back(c);
    }
  }
  return loggedInCards;
}

std::string Collection::getDateNow()
{
  std::time_t now = std::time(0);
  std::tm *ltm = std::localtime(&now);
  std::string theYear = std::to_string(1900 + ltm->tm_year);
  std::string theMonth = std::to_string(1 + ltm->tm_mon);
  std::string theDay = std::to_string(ltm->tm_mday);

  return theYear + "-" + theMonth + "-" + theDay;
}