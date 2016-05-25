#include "priority_queue.h"
#include <gtest.h>
#include "d-heap.h"



TEST(PRIORITY_QUEUE_ON_D_HEAP, can_create_queue) {
	Priority_Queue* a;
	ASSERT_NO_THROW(a = new on_d_heap(5,2));
}

TEST(PRIORITY_QUEUE_ON_D_HEAP, created_queue_is_empty) {
	on_d_heap a(5,2);
	EXPECT_EQ(1, a.isEmpty());
}

TEST(PRIORITY_QUEUE_ON_D_HEAP, can_push_key) {
	on_d_heap a(5,2);
	ASSERT_NO_THROW(a.Push(1));
}

TEST(PRIORITY_QUEUE_ON_D_HEAP, can_pop_elem) {
	on_d_heap a(5,2);
	a.Push(1);
	a.Push(2);
	ASSERT_NO_THROW(a.Pop());
}

TEST(PRIORITY_QUEUE_ON_D_HEAP, throws_when_pop_from_empty) {
	on_d_heap a(5,1);
	ASSERT_ANY_THROW(a.Pop());
}

TEST(PRIORITY_QUEUE_ON_D_HEAP, can_get_back_elem)
{
	on_d_heap a(5,2);
	a.Push(1);
	a.Push(2);
	ASSERT_NO_THROW(a.Back());
}

TEST(PRIORITY_QUEUE_ON_D_HEAP, throws_when_back_from_empty)
{
	on_d_heap a(5,2);
	ASSERT_ANY_THROW(a.Back());
}

TEST(PRIORITY_QUEUE_ON_D_HEAP, back_returns_elem_with_max_priority)
{
	on_d_heap a(10,2);
	for (int i = 9; i > -1; i--) {
		a.Push(i);
	}
	
	EXPECT_EQ(0, a.Back());
}

TEST(PRIORITY_QUEUE_ON_D_HEAP, can_copy_queue) {
	on_d_heap a(2, 2);
	a.Push(3);
	ASSERT_NO_THROW(on_d_heap b(a));
}

//===================================================

//TEST(PRIORITY_QUEUE_ON_BINARY_SEARCH_TREE, can_create_queue) {
//	Priority_Queue* a;
//	ASSERT_NO_THROW(a = new on_bst());
//}
//
//TEST(PRIORITY_QUEUE_ON_BINARY_SEARCH_TREE, created_queue_is_empty) {
//	on_bst a;
//	EXPECT_EQ(1, a.isEmpty());
//}
//
//TEST(PRIORITY_QUEUE_ON_BINARY_SEARCH_TREE, can_push_key) {
//	on_bst a;
//	ASSERT_NO_THROW(a.Push(1));
//}
//
//TEST(PRIORITY_QUEUE_ON_BINARY_SEARCH_TREE, can_pop_elem) {
//	on_bst a;
//	a.Push(2);
//	a.Push(1);
//	a.Push(3);
//	ASSERT_NO_THROW(a.Pop());
//}
//
//TEST(PRIORITY_QUEUE_ON_BINARY_SEARCH_TREE, throws_when_pop_from_empty) {
//	on_bst a;
//	ASSERT_ANY_THROW(a.Pop());
//}
//
//TEST(PRIORITY_QUEUE_ON_BINARY_SEARCH_TREE, can_get_back_elem) {
//	on_bst a;
//	a.Push(1);
//	a.Push(2);
//	ASSERT_NO_THROW(a.Back());
//}
//
//TEST(PRIORITY_QUEUE_ON_BINARY_SEARCH_TREE, throws_when_back_from_empty) {
//	on_bst a;
//	ASSERT_ANY_THROW(a.Back());
//}
//
//TEST(PRIORITY_QUEUE_ON_BINARY_SEARCH_TREE, back_returns_elem_with_max_priority) {
//	on_bst a;
//	for (int i = 10; i > -1; i--) {
//		a.Push(i);
//	}
//	EXPECT_EQ(0, a.Back());
//}
//
//TEST(PRIORITY_QUEUE_ON_BINARY_SEARCH_TREE, can_copy_queue) {
//	on_bst a;
//	a.Push(3);
//	ASSERT_NO_THROW(on_bst b(a));
//}

//=================================================================

TEST(PRIORITY_QUEUE_ON_SORT_TABLE, can_create_queue) {
	Priority_Queue* a;
	ASSERT_NO_THROW(a = new on_table(2));
}

TEST(PRIORITY_QUEUE_ON_SORT_TABLE, created_queue_is_empty) {
	on_table a(2);
	EXPECT_EQ(1, a.isEmpty());
}

TEST(PRIORITY_QUEUE_ON_SORT_TABLE, can_push_key) {
	on_table a(2);
	ASSERT_NO_THROW(a.Push(1));
}

TEST(PRIORITY_QUEUE_ON_SORT_TABLE, can_pop_elem) {
	on_table a(5);
	a.Push(1);
	a.Push(2);
	ASSERT_NO_THROW(a.Pop());
}

TEST(PRIORITY_QUEUE_ON_SORT_TABLE, throws_when_pop_from_empty) {
	on_table a(1);
	ASSERT_ANY_THROW(a.Pop());
}

TEST(PRIORITY_QUEUE_ON_SORT_TABLE, can_get_back_elem) {
	on_table a(5);
	a.Push(1);
	a.Push(2);
	ASSERT_NO_THROW(a.Back());
}

TEST(PRIORITY_QUEUE_ON_SORT_TABLE, throws_when_back_from_empty) {
	on_table a(2);
	ASSERT_ANY_THROW(a.Back());
}

TEST(PRIORITY_QUEUE_ON_SORT_TABLE, back_returns_elem_with_max_priority) {
	on_table a(12);
	for (int i = 10; i > -1; i--) {
		a.Push(i);
	}
	EXPECT_EQ(0, a.Back());
}

TEST(PRIORITY_QUEUE_ON_SORT_TABLE, can_copy_queue) {
	on_table a(2);
	a.Push(3);
	ASSERT_NO_THROW(on_table b(a));
}
