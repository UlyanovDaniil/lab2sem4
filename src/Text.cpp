#include "Text.h"

TText::TText()
{
  child = nullptr;
  count = 0;
}

TText::TText(const TText& text)
{
  if (text.child == nullptr)
  {
    child = nullptr;
    count = 0;
  }
  else
  {
    child = new TParagraph(*text.child);
    count = text.count;

    TParagraph* cur = child;

    while (cur->next != nullptr)
    {
      cur->next = new TParagraph(*cur->next);
      cur = cur->next;
    }
  }
}

TText::~TText()
{
  Clear();
}

uint32_t TText::GetCount()
{
  return count;
}

TText& TText::operator=(const TText& text)
{
  return *this;
}

TParagraph* TText::operator[](long i)
{
  if (i < 0 || i > count)
  {
    throw - 1;
  }

  TParagraph* tmp = child;
  long j = 0;

  while (tmp != nullptr)
  {
    if (j == i)
    {
      return tmp;
    }
    tmp = tmp->next;
    j++;
  }
}

void TText::AddBegin(TParagraph* paragraph)
{
  child = new TParagraph(paragraph->child, child);
  count++;
}

void TText::AddEnd(TParagraph* paragraph)
{
  if (child == nullptr)
  {
    child = new TParagraph(*paragraph);
  }
  else
  {
    TParagraph* tmp = child;

    while (tmp->next != nullptr)
    {
      tmp = tmp->next;
    }

    tmp->next = new TParagraph(*paragraph);
  }
  count++;
}

void TText::Add(TParagraph* paragraph, long i)
{
  if (i < 0 || i > count)
  {
    throw - 1;
  }
  if (i == 0)
  {
    AddBegin(paragraph);
  }
  else
  {
    TParagraph* prev = child;

    for (uint32_t j = 0; j < i - 1; j++)
    {
      prev = prev->next;
    }

    prev->next = new TParagraph(paragraph->child, prev->next);

    count++;
  }
}

void TText::DeleteBegin()
{
  if (count == 0)
  {
    throw - 1;
  }

  TParagraph* tmpp = child;

  child = child->next;
  count--;

  tmpp->Clear();

  delete tmpp;
}

void TText::DeleteEnd()
{
  Delete(count - 1);
}

void TText::Delete(long i)
{
  if (i < 0 || i > count - 1)
  {
    throw - 1;
  }
  if (i == 0)
  {
    DeleteBegin();
  }
  else
  {
    TParagraph* prev = child;

    for (uint32_t j = 0; j < i - 1; j++)
    {
      prev = prev->next;
    }

    TParagraph* del = prev->next;

    prev->next = del->next;

    del->Clear();

    delete del;

    count--;
  }
}

bool TText::IsEmpty()
{
  return count == 0;
}

void TText::Clear()
{
  while (count > 0)
  {
    DeleteBegin();
  }
}

void TText::Print()
{
  if (child == nullptr)
  {
    std::cout << "";
  }
  else
  {
    TParagraph* tmp = child;

    while (tmp->next != nullptr)
    {
      tmp->Print();
      std::cout << "\n";
      tmp = tmp->next;
    }

    tmp->Print();
  }
}

//std::ostream& operator<<(std::ostream& os, TText& text)
//{
//  if (text.child == nullptr)
//  {
//    os << "";
//    return os;
//  }
//  else
//  {
//    TParagraph* tmp = text.child;
//
//    while (tmp->next != nullptr)
//    {
//      os << *tmp << "\n";
//      tmp = tmp->next;
//    }
//
//    os << *tmp;
//
//    return os;
//  }
//}
