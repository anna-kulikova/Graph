#include "priority_queue.h"
#include <gtest.h>

TEST(PRIORITY_QUEUE, can_create_queue)
{
	Priority_Queue* q;
	ASSERT_NO_THROW(q = new Priority_Queue(2));
}

TEST(PRIORITY_QUEUE, created_queue_is_empty)
{
	Priority_Queue q(2);
	EXPECT_EQ(1, q.IsEmpty());
}

TEST(PRIORITY_QUEUE, can_get_size_queue)
{
	Priority_Queue q(2);
	ASSERT_NO_THROW(q.GetSize());
}

TEST(PRIORITY_QUEUE, gGetSize_works_correctly)
{
	Priority_Queue q(2);
	EXPECT_EQ(0, q.GetSize());
}

TEST(PRIORITY_QUEUE, can_Push_key)
{
	Priority_Queue q(2);
	ASSERT_NO_THROW(q.Push(2));
}

TEST(PRIORITY_QUEUE, Push_increases_size)
{
	Priority_Queue q(2);
	int tmp = q.GetSize();
	q.Push(1);
	EXPECT_EQ(tmp + 1, q.GetSize());
}

TEST(PRIORITY_QUEUE, can_Pop_elem)
{
	Priority_Queue q(2);
	q.Push(1);
	q.Push(5);
	ASSERT_NO_THROW(q.Pop());
}

TEST(PRIORITY_QUEUE, throws_when_Pop_from_empty)
{
	Priority_Queue q(1);
	ASSERT_ANY_THROW(q.Pop());
}

TEST(PRIORITY_QUEUE, Pop_decreases_size)
{
	Priority_Queue q(2);
	q.Push(1);
	q.Push(2);
	int tmp = q.GetSize();
	q.Pop();
	EXPECT_EQ(tmp - 1, q.GetSize());
}

TEST(PRIORITY_QUEUE, can_get_Back_element)
{
	Priority_Queue q(2);
	q.Push(1);
	q.Push(5);
	ASSERT_NO_THROW(q.Back());
}

TEST(PRIORITY_QUEUE, throws_when_Back_from_empty)
{
	Priority_Queue q(2);
	ASSERT_ANY_THROW(q.Back());
}

TEST(PRIORITY_QUEUE, Back_dont_decrease_size)
{
	Priority_Queue q(2);
	q.Push(1);
	q.Push(5);
	int tmp = q.GetSize();
	q.Back();
	EXPECT_EQ(tmp, q.GetSize());
}

TEST(PRIORITY_QUEUE, Back_returns_element_with_max_priority)
{
	Priority_Queue q(2);
	for (int i = 10; i > -1; i--)
		q.Push(i);
	EXPECT_EQ(0, q.Back());
}


TEST(PRIORITY_QUEUE, can_copy_queue)
{
	Priority_Queue q(2);
	q.Push(3);
	ASSERT_NO_THROW(Priority_Queue q2(q));
}

TEST(PRIORITY_QUEUE, copied_queue_is_equal_to_source_one)
{
	Priority_Queue q(2);
	for (int i = 0; i < 10; i++)
		q.Push(i);
	Priority_Queue q2(q);
	EXPECT_EQ(q, q2);
}
