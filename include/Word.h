#define __Word_H__
#ifdef __Word_H__

#include <iostream>
#include "MyString.h"

class TWord
{
protected:
  TWord* next;
  TString data;

  friend class TParagraph;
public:
  TWord(TString _data = TString(), TWord* _next = nullptr);
  TWord(const TWord& word);

  TString GetData();

  TWord& operator=(const TWord& text);

  friend std::ostream& operator<<(std::ostream& os, TWord& word);
};

#endif