#define __MyString_H__
#ifdef __MyString_H__

#include <iostream>

class TString
{
private:
  char* str;
  uint64_t len;
public:
  TString();
  TString(const char* s);
  TString(long n, char c = 0);
  TString(const TString& s);
  TString(TString&& s) noexcept;
  ~TString();

  uint64_t GetLen() const noexcept;

  TString& operator=(const TString& s);
  TString& operator=(const char* s);
  TString& operator=(TString&& s) noexcept;
  TString operator+(const TString& s);
  TString operator+(const char* s);
  TString& operator+=(const TString& s);
  TString& operator+=(const char* s);
  bool operator==(const TString& s) const noexcept;
  bool operator!=(const TString& s) const noexcept;
  bool operator<(const TString& s) const noexcept;
  bool operator>(const TString& s) const noexcept;
  bool operator<=(const TString& s) const noexcept;
  bool operator>=(const TString& s) const noexcept;
  bool operator==(const char* s) const noexcept;
  bool operator!=(const char* s) const noexcept;
  bool operator<(const char* s) const noexcept;
  bool operator>(const char* s) const noexcept;
  bool operator<=(const char* s) const noexcept;
  bool operator>=(const char* s) const noexcept;
  char& operator[](long i);

  uint64_t Find(char c);
  uint64_t Find(const TString& s);
  uint64_t Find(const char* s);

  friend std::ostream& operator<<(std::ostream& a, TString& b);
  friend std::istream& operator>>(std::istream& a, TString& b);
};

#endif