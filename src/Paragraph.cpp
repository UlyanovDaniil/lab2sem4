#include "Paragraph.h"

TParagraph::TParagraph(TWord* _child, TParagraph* _next)
{
  next = _next;
  child = _child;
  //count = 0;

  if (child == nullptr)
  {
    count = 0;
  }
  else
  {
    TWord* tmp = child;

    while (tmp->next != nullptr)
    {

    }
  }

}

TParagraph::TParagraph(const TParagraph& paragraph)
{
  next = paragraph.next;
  child = paragraph.child;
  count = paragraph.count;
}

uint32_t TParagraph::GetCount()
{
  return count;
}

TParagraph& TParagraph::operator=(const TParagraph& text)
{
  return *this;
}

TWord* TParagraph::operator[](long i)
{
  return nullptr;
}

void TParagraph::AddBegin(TWord* word)
{
}

void TParagraph::AddEnd(TWord* word)
{
}

void TParagraph::Add(TWord* word, long i)
{
}

void TParagraph::DeleteBegin()
{
  if (count == 0)
  {
    throw - 1;
  }

  TWord* tmpw = child;

  child = child->next;
  count--;

  delete tmpw;
}

void TParagraph::DeleteEnd()
{
}

void TParagraph::Delete(long i)
{
}

bool TParagraph::IsEmpty()
{
  return count == 0;
}

void TParagraph::Clear()
{
  while (count > 0)
  {
    DeleteBegin();
  }
}

void TParagraph::Print()
{
  if (child == nullptr)
  {
    std::cout << "";
  }
  else
  {
    TWord* tmp = child;

    while (tmp->next != nullptr)
    {
      std::cout << *tmp << " ";
      tmp = tmp->next;
    }

    std::cout << *tmp;
  }
}

//std::ostream& operator<<(std::ostream& os, TParagraph& paragraph)
//{
//  if (paragraph.child == nullptr)
//  {
//    os << "";
//    return os;
//  }
//  else
//  {
//    TWord* tmp = paragraph.child;
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