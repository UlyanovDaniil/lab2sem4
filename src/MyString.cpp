#include "MyString.h"

TString::TString()
{
	len = 0;
	str = new char[len + 1];
	str[len] = 0;
}

TString::TString(const char* s)
{
	if (s == nullptr)
	{
		throw -1;
	}
	len = strlen(s);
	str = new char[len + 1];
	std::copy(s, s + len + 1, str);
}

TString::TString(long n, char c)
{
	if (n < 0)
	{
		throw -1;
	}
	len = n;
	str = new char[len + 1];
	memset(str, c, len);
	str[len] = 0;
}

TString::TString(const TString& s)
{
	len = s.len;
	str = new char[len + 1];
	std::copy(s.str, s.str + s.len + 1, str);
}

TString::TString(TString&& s) noexcept
{
	str = s.str;
	len = s.len;

	s.str = nullptr;
	s.len = 0;
}

TString::~TString()
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
}

uint64_t TString::GetLen() const noexcept
{
	return len;
}

TString& TString::operator=(const TString& s)
{
	if (this == &s)
	{
		return *this;
	}
	if (str != nullptr)
	{
		delete[] str;
	}
	len = s.len;
	str = new char[len + 1];
	std::copy(s.str, s.str + s.len + 1, str);
	return *this;
}

TString& TString::operator=(const char* s)
{
	if (s == nullptr)
	{
		throw - 1;
	}
	if (str != nullptr)
	{
		delete[] str;
	}
	len = strlen(s);
	str = new char[len + 1];
	std::copy(s, s + len + 1, str);
	return *this;
}

TString& TString::operator=(TString&& s) noexcept
{
	if (s.str == nullptr)
	{
		throw -1;
	}
	if (str != nullptr)
	{
		delete[] str;
	}

	str = s.str;
	len = s.len;

	s.str = nullptr;
	s.len = 0;
}

TString TString::operator+(const TString& s)
{
	TString tmp(len + s.len);
	std::copy(str, str + len, tmp.str);
	std::copy(s.str, s.str + s.len + 1, tmp.str + len);
	return tmp;
}

TString TString::operator+(const char* s)
{
	if (s == nullptr)
	{
		throw - 1;
	}
	uint64_t l = strlen(s);
	TString res(len + l);
	std::copy(str, str + len, res.str);
	std::copy(s, s + l + 1, res.str + len);
	return res;
}

TString& TString::operator+=(const TString& s)
{
	char* tstr = new char[len + s.len + 1];
	std::copy(str, str + len, tstr);
	std::copy(s.str, s.str + s.len + 1, tstr + len);
	if (str != nullptr)
	{
		delete[] str;
	}
	len = len + s.len;
	str = tstr;
	return *this;
}

TString& TString::operator+=(const char* s)
{
	if (s == nullptr)
	{
		throw -1;
	}
	uint64_t l = strlen(s);
	char* tstr = new char[len + l + 1];
	std::copy(str, str + len, tstr);
	std::copy(s, s + l + 1, tstr + len);
	if (str != nullptr)
	{
		delete[] str;
	}
	len = len + l;
	str = tstr;
	return *this;
}

bool TString::operator==(const TString& s) const noexcept
{
	return len == s.len && memcmp(str, s.str, len > s.len ? s.len : len) == 0;
}

bool TString::operator!=(const TString& s) const noexcept
{
	return len != s.len || memcmp(str, s.str, len > s.len ? s.len : len) != 0;
}

bool TString::operator<(const TString& s) const noexcept
{
	return len < s.len || memcmp(str, s.str, len > s.len ? s.len : len) < 0;
}

bool TString::operator>(const TString& s) const noexcept
{
	return len > s.len || memcmp(str, s.str, len > s.len ? s.len : len) > 0;
}

bool TString::operator<=(const TString& s) const noexcept
{
	return len < s.len || memcmp(str, s.str, len > s.len ? s.len : len) <= 0;
}

bool TString::operator>=(const TString& s) const noexcept
{
	return len > s.len || memcmp(str, s.str, len > s.len ? s.len : len) >= 0;
}

bool TString::operator==(const char* s) const noexcept
{
	uint64_t l = strlen(s);
	return len == l && memcmp(str, s, len > l ? l : len) == 0;
}

bool TString::operator!=(const char* s) const noexcept
{
	uint64_t l = strlen(s);
	return len != l || memcmp(str, s, len > l ? l : len) != 0;
}

bool TString::operator<(const char* s) const noexcept
{
	uint64_t l = strlen(s);
	return len < l || memcmp(str, s, len > l ? l : len) < 0;
}

bool TString::operator>(const char* s) const noexcept
{
	uint64_t l = strlen(s);
	return len > l || memcmp(str, s, len > l ? l : len) > 0;
}

bool TString::operator<=(const char* s) const noexcept
{
	uint64_t l = strlen(s);
	return len < l || memcmp(str, s, len > l ? l : len) <= 0;
}

bool TString::operator>=(const char* s) const noexcept
{
	uint64_t l = strlen(s);
	return len > l || memcmp(str, s, len > l ? l : len) >= 0;
}

char& TString::operator[](long i)
{
	if (str == nullptr)
	{
		throw -1;
	}
	if (i > -len && i < 0)
	{
		i += len;
	}
	return str[std::abs(i % (long)len)];
}

uint64_t TString::Find(char c)
{
	auto i = std::find(str, str + len, c);
	if (i != str + len)
	{
		return i - str + 1;
	}
	else
	{
		return -1;
	}
}

uint64_t TString::Find(const TString& s)
{
	auto i = strstr(str, s.str);
	if (i != NULL)
	{
		return i - str + 1;
	}
	else
	{
		return -1;
	}
}

uint64_t TString::Find(const char* s)
{
	auto i = strstr(str, s);
	if (i != NULL)
	{
		return i - str + 1;
	}
	else
	{
		return -1;
	}
}

std::ostream& operator<<(std::ostream& a, TString& b)
{
	a << b.str;
	return a;
}

std::istream& operator>>(std::istream& a, TString& b)
{
	char s[2716];
	a >> s;
	b.len = strlen(s);
	if (b.str != nullptr)
	{
		delete[] b.str;
	}
	b.str = new char[b.len + 1];
	std::copy(s, s + b.len + 1, b.str);
	return a;
}