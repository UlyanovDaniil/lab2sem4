#include <gtest.h>
#include "ForwardList.h"

TEST(TForwardList, creating_list)
{
	ASSERT_NO_THROW(TForwardList<int>());

	TForwardList<int> l = TForwardList<int>();

	l.AddBegin(1);

	ASSERT_NO_THROW(TForwardList<int>(l));
}

TEST(TForwardList, get_count)
{
	TForwardList<int> l = TForwardList<int>();

	l.AddBegin(1);
	l.AddBegin(2);
	l.AddBegin(3);

	EXPECT_EQ(l.GetCount(), 3);

	l.DeleteBegin();

	EXPECT_EQ(l.GetCount(), 2);
}

TEST(TForwardList, list_assignment)
{
	TForwardList<int> l1 = TForwardList<int>();

	l1.AddBegin(1);
	l1.AddBegin(2);
	l1.AddBegin(3);

	TForwardList<int> l2 = TForwardList<int>();

	l2 = l1;

	for (int i = 0; i < l1.GetCount(); i++)
	{
		EXPECT_EQ(l1[i], l2[i]);
	}
}

TEST(TForwardList, list_index)
{
	TForwardList<int> l1 = TForwardList<int>(), l2 = TForwardList<int>();

	l1.AddBegin(1);
	l1.AddBegin(2);
	l1.AddBegin(3);

	l2.AddEnd(4);
	l2.AddEnd(5);
	l2.AddEnd(6);

	EXPECT_EQ(l1[0], 3);
	EXPECT_EQ(l1[2], 1);
	EXPECT_EQ(l2[1], 5);
	EXPECT_EQ(l2[2], 6);
}

TEST(TForwardList, list_add)
{
	TForwardList<int> l1 = TForwardList<int>();

	ASSERT_NO_THROW(l1.AddBegin(1));
	ASSERT_NO_THROW(l1.AddEnd(3));
	ASSERT_NO_THROW(l1.Add(2, 1));
	ASSERT_ANY_THROW(l1.Add(4, 4));

	EXPECT_EQ(l1[0], 1);
	EXPECT_EQ(l1[1], 2);
	EXPECT_EQ(l1[2], 3);
}

TEST(TForwardList, list_delete)
{
	TForwardList<int> l1 = TForwardList<int>();

	l1.AddEnd(1);
	l1.AddEnd(2);
	l1.AddEnd(3);
	l1.AddEnd(4);
	l1.AddEnd(5);

	ASSERT_NO_THROW(l1.DeleteBegin());
	ASSERT_NO_THROW(l1.DeleteEnd());
	ASSERT_NO_THROW(l1.Delete(1));

	EXPECT_EQ(l1[0], 2);
	EXPECT_EQ(l1[1], 4);
}

TEST(TForwardList, list_empty)
{
	TForwardList<int> l1 = TForwardList<int>();

	EXPECT_EQ(l1.IsEmpty(), true);

	l1.AddBegin(1);

	EXPECT_EQ(l1.IsEmpty(), false);
}

TEST(TForwardList, list_clear)
{
	TForwardList<int> l1 = TForwardList<int>();

	l1.AddBegin(1);
	l1.AddBegin(2);
	l1.AddBegin(3);

	l1.Clear();

	EXPECT_EQ(l1.IsEmpty(), true);
}