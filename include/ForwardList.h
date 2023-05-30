#define __ForwardList_H__
#ifdef __ForwardList_H__

#include <iostream>

template <typename T>
class TForwardList
{
protected:
  template <typename T>
  class TForwardListItem
  {
  public:
    T data;
    TForwardListItem<T>* next;

    TForwardListItem(T _data = T(), TForwardListItem<T>* _next = nullptr)
    {
      data = _data;
      next = _next;
    }
  };

  TForwardListItem<T>* head;
  uint32_t count;
public:
  TForwardList();
  TForwardList(const TForwardList<T>& flist);
  ~TForwardList();

  uint32_t GetCount() const noexcept;

  TForwardList<T>& operator=(const TForwardList<T>& flist);
  T& operator[](long i);

  void AddBegin(T data);
  void AddEnd(T data);
  void Add(T data, long i);
  void DeleteBegin();
  void DeleteEnd();
  void Delete(long i);
  bool IsEmpty() const noexcept;
  void Clear();

  //template <typename T>
  friend std::ostream& operator<<(std::ostream& os, TForwardList<T>& flist)
  {
    if (flist.head == nullptr)
    {
      os << "";
      return os;
    }
    else
    {
      TForwardListItem<T>* tmp = flist.head;

      while (tmp->next != nullptr)
      {
        os << tmp->data << " ";
        tmp = tmp->next;
      }

      os << tmp->data;

      return os;
    }
  }
};

template<typename T>
inline TForwardList<T>::TForwardList()
{
  head = nullptr;
  count = 0;
}

template<typename T>
inline TForwardList<T>::TForwardList(const TForwardList<T>& flist)
{
  if (flist.count == 0)
  {
    head = nullptr;
    count = 0;
  }
  else
  {
    head = new TForwardListItem<T>(flist.head->data, flist.head->next);
    count = flist.count;

    TForwardListItem<T>* cur = head;

    while (cur->next != nullptr)
    {
     cur->next = new TForwardListItem<T>(cur->next->data, cur->next->next);
     cur = cur->next;
    }
  }
}

template<typename T>
inline TForwardList<T>::~TForwardList()
{
  Clear();
}

template<typename T>
inline uint32_t TForwardList<T>::GetCount() const noexcept
{
  return count;
}

template<typename T>
inline TForwardList<T>& TForwardList<T>::operator=(const TForwardList<T>& flist)
{
  this->Clear();

  if (flist.count != 0)
  {
    head = new TForwardListItem<T>(flist.head->data, flist.head->next);
    count = flist.count;

    TForwardListItem<T>* cur = head;

    while (cur->next != nullptr)
    {
      cur->next = new TForwardListItem<T>(cur->next->data, cur->next->next);
      cur = cur->next;
    }
  }

  return *this;
}

template<typename T>
inline T& TForwardList<T>::operator[](long i)
{
  if (i < 0 || i > count)
  {
    throw -1;
  }

  TForwardListItem<T>* tmp = head;
  long j = 0;

  while (tmp != nullptr)
  {
    if (j == i)
    {
      return tmp->data;
    }
    tmp = tmp->next;
    j++;
  }
}

template<typename T>
inline void TForwardList<T>::AddBegin(T data)
{
  head = new TForwardListItem<T>(data, head);
  count++;
}

template<typename T>
inline void TForwardList<T>::AddEnd(T data)
{
  if (head == nullptr)
  {
    head = new TForwardListItem<T>(data);
  }
  else
  {
    TForwardListItem<T>* tmp = head;

    while (tmp->next != nullptr)
    {
      tmp = tmp->next;
    }

    tmp->next = new TForwardListItem<T>(data);
  }
  count++;
}

template<typename T>
inline void TForwardList<T>::Add(T data, long i)
{
  if (i < 0 || i > count)
  {
    throw -1;
  }
  if (i == 0)
  {
    AddBegin(data);
  }
  else
  {
    TForwardListItem<T>* prev = head;

    for (uint32_t j = 0; j < i - 1; j++)
    {
      prev = prev->next;
    }

    prev->next = new TForwardListItem<T>(data, prev->next);

    count++;
  }
}

template<typename T>
inline void TForwardList<T>::DeleteBegin()
{
  if (count == 0)
  {
    throw -1;
  }

  TForwardListItem<T>* tmp = head;

  head = head->next;
  count--;

  delete tmp;
}

template<typename T>
inline void TForwardList<T>::DeleteEnd()
{
  Delete(count - 1);
}

template<typename T>
inline void TForwardList<T>::Delete(long i)
{
  if (i < 0 || i > count - 1)
  {
    throw -1;
  }
  if (i == 0)
  {
    DeleteBegin();
  }
  else
  {
    TForwardListItem<T>* prev = head;

    for (uint32_t j = 0; j < i - 1; j++)
    {
      prev = prev->next;
    }

    TForwardListItem<T>* del = prev->next;

    prev->next = del->next;

    delete del;

    count--;
  }
}

template<typename T>
inline bool TForwardList<T>::IsEmpty() const noexcept
{
  return count == 0;
}

template<typename T>
inline void TForwardList<T>::Clear()
{
  while (count > 0)
  {
    DeleteBegin();
  }
}

#endif