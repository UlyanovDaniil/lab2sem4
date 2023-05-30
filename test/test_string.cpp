#include <gtest.h>
#include "MyString.h"

TEST(TString, creating_strings)
{
	ASSERT_NO_THROW(TString s1());
	ASSERT_NO_THROW(TString s2("abc123"));
	ASSERT_NO_THROW(TString s3(5));
	ASSERT_NO_THROW(TString s4(5, '1'));
	ASSERT_ANY_THROW(TString s4(-3));

	TString s5("str");

	ASSERT_NO_THROW(TString s6(s5));
}

TEST(TString, get_length)
{
	TString s1(5), s2(123456789), s3("abcdef");

	EXPECT_EQ(s1.GetLen(), 5);
	EXPECT_EQ(s2.GetLen(), 123456789);
	EXPECT_EQ(s3.GetLen(), 6);
}

TEST(TString, string_addition)
{
	TString s1("hello"), s2("world"), s3("helloworld"), s4(10, '1');

	EXPECT_EQ(s1 + s2, s3);
	EXPECT_EQ(s1 + s2, "helloworld");
	EXPECT_EQ(s4 + s4, TString(20, '1'));
	EXPECT_EQ(s1 += s2, s1);
	EXPECT_EQ(s2 += s2, "worldworld");
}

TEST(TString, string_compare)
{
	TString s1("123"), s2("123"), s3("1234"), s4("1235");

	EXPECT_EQ(s1 == s2, true);
	EXPECT_EQ(s3 != s4, true);
	EXPECT_EQ(s2 < s3, true);
	EXPECT_EQ(s3 < s4, true);
	EXPECT_EQ(s3 <= s4, true);
}

TEST(TString, string_assignment)
{
	TString s1("123"), s2("abc"), s3, s4;

	s3 = s1;
	s4 = s2;

	EXPECT_EQ(s1, s3);
	EXPECT_EQ(s2, s4);
	EXPECT_NE(s3, s4);
}

TEST(TString, string_index)
{
	TString s1("abcdefg1234567890"), s2("123");

	EXPECT_EQ(s1[0], 'a');
	EXPECT_EQ(s1[-1], '0');
	EXPECT_EQ(s2[1], '2');
}

TEST(TString, string_find)
{
	TString s1("abcdefg1234567890"), s2("123");

	EXPECT_EQ(s1.Find('e'), 5);
	EXPECT_EQ(s1.Find(s2), 8);
	EXPECT_EQ(s1.Find("90"), s1.GetLen() - 1);
}