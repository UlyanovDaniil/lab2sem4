#define __Text_H__
#ifdef __Text_H__

#include <iostream>
#include "Paragraph.h"

class TText
{
protected:
  TParagraph* child;
  uint32_t count;

  friend class TParagraph;
public:
  TText();
  TText(const TText& text);
  ~TText();

  uint32_t GetCount();

  TText& operator=(const TText& text);
  TParagraph* operator[](long i);

  void AddBegin(TParagraph* paragraph);
  void AddEnd(TParagraph* paragraph);
  void Add(TParagraph* paragraph, long i);
  void DeleteBegin();
  void DeleteEnd();
  void Delete(long i);
  bool IsEmpty();
  void Clear();
  void Print();

  friend std::ostream& operator<<(std::ostream& os, TText& text);
};

#endif