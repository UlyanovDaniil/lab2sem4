#include "Word.h"

TWord::TWord(TString _data, TWord* _next)
{
  next = _next;
  data = _data;
}

TWord::TWord(const TWord& word)
{
  next = word.next;
  data = word.data;
}

TString TWord::GetData()
{
  return data;
}

TWord& TWord::operator=(const TWord& word)
{
  next = word.next;
  data = word.data;

  return *this;
}

std::ostream& operator<<(std::ostream& os, TWord& word)
{
  return os << word.data;
}
