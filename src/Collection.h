#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <string>
#include <vector>
#include "Card.h"

class Collection
{
  private:
    std::vector<Card> m_cards;
    int m_id;
    int m_dateAdded;
    bool m_hasAccess;

  public:
    const std::vector<Card>& getAllItems(); 
    Card& addCard(int &id);   
    Card& getCardByIdOrNew(int &id);
    void removeCardById(int &id);
    bool scanCard(int &id); 
    void updateCardAccess(int id, bool newAccess); 
    std::vector<Card> getLoggedIn();
    std::string getDateNow();

    Collection() = default;
};

#endif // _COLLECTION_H_