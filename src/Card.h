#ifndef _CARD_H_
#define _CARD_H_

#include <string> 

class Card
{
  private:
    int m_id;
    std::string m_dateAdded;
    bool m_isLoggedIn;
    bool m_hasAccess;

  public:
    const int getId() const;
    const std::string getDateAdded() const;
    const bool getLoggedInStatus() const;
    void setLoggedInStatus(bool isLoggedIn);
    const bool getHasAccess() const;
    void setAccess(bool hasAccess);

    Card(const int &id, const std::string &dateAdded);
};

#endif // _CARD_H_