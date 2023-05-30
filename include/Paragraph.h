#define __Paragraph_H__
#ifdef __Paragraph_H__

#include <iostream>

#include "Word.h"

class TParagraph
{
protected:
  TWord* child;
  TParagraph* next;
  uint32_t count;

  friend class TText;
  friend TWord;
public:
  TParagraph(TWord* _child = nullptr, TParagraph* _next = nullptr);
  TParagraph(const TParagraph& paragraph);

  uint32_t GetCount();

  TParagraph& operator=(const TParagraph& text);
  TWord* operator[](long i);

  void AddBegin(TWord* word);
  void AddEnd(TWord* word);
  void Add(TWord* word, long i);
  void DeleteBegin();
  void DeleteEnd();
  void Delete(long i);
  bool IsEmpty();
  void Clear();
  void Print();

  //friend std::ostream& operator<<(std::ostream& os, TParagraph& paragraph);
};

#endif 