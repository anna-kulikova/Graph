#include "d-heap.h"
#include <gtest.h>

TEST(D_HEAP, can_create_heap)
{

	ASSERT_NO_THROW(D_heap heap(2, 2));
}

TEST(D_HEAP, throws_when_create_heap_with_size_less_than_0)
{

	ASSERT_ANY_THROW(D_heap heap(-7, 2));
}

TEST(D_HEAP, throws_when_create_heap_with_D_equal_to_0)
{

	ASSERT_ANY_THROW(D_heap heap(2, 0));
}

TEST(D_HEAP, throws_when_create_heap_with_D_less_than_0)
{

	ASSERT_ANY_THROW(D_heap heap(3, -5));
}

TEST(D_HEAP, can_get_size_heap)
{
	D_heap heap(4, 2);
	ASSERT_NO_THROW(heap.GetSize());
}


TEST(D_HEAP, created_heap_is_empty)
{
	D_heap heap(5, 3);
	EXPECT_EQ(0, heap.GetHeapSize());
}

TEST(D_HEAP, compare_equal_heaps_return_true)
{
	D_heap heap1(5, 3);
	D_heap heap2(5, 3);
	for (int i = 0; i < 5; i++)
	{
		heap1.PushKey(i);
		heap2.PushKey(i);
	}
	EXPECT_EQ(heap1, heap2);
}

TEST(D_HEAP, compare_non_equal_heaps_return_false)
{
	D_heap heap1(5, 3);
	D_heap heap2(5, 3);
	for (int i = 0; i < 5; i++)
	{
		heap1.PushKey(i);
		heap2.PushKey(-i);
	}
	EXPECT_NE(heap1, heap2);
}

TEST(D_HEAP, can_copy_heap)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	ASSERT_NO_THROW(D_heap heap2(heap));
}

TEST(D_HEAP, copied_heap_is_equal_to_source_one)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	D_heap heap2(heap);
	EXPECT_EQ(heap, heap2);
}


TEST(D_HEAP, can_swap_two_nodes)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	ASSERT_NO_THROW(heap.Swap(1, 2));
}

TEST(D_HEAP, throws_when_swap_with_negative_first_argument)
{
	D_heap heap(5, 3);
		for (int i = 0; i < 5; i++)
			heap.PushKey(i);
	ASSERT_ANY_THROW(heap.Swap(-4, 1));
}

TEST(D_HEAP, throws_when_swap_with_negative_second_argument)
{
	D_heap heap(5, 3);
		for (int i = 0; i < 5; i++)
			heap.PushKey(i);
	ASSERT_ANY_THROW(heap.Swap(1, -4));
}

TEST(D_HEAP, throws_when_swap_with_too_large_first_argument)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	ASSERT_ANY_THROW(heap.Swap(20, 1));
}

TEST(D_HEAP, throws_when_swap_with_too_large_second_argument)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	ASSERT_ANY_THROW(heap.Swap(1, 20));
}


TEST(D_HEAP, can_sift_up)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	heap.Swap(0, 2);
	ASSERT_NO_THROW(heap.SiftUp(2));
}

TEST(D_HEAP, SiftUp_throws_when_negative_index)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	heap.Swap(0, 2);
	ASSERT_ANY_THROW(heap.SiftUp(-3));
}

TEST(D_HEAP, SiftUp_throws_when_index_is_too_large)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	heap.Swap(0, 2);
	ASSERT_ANY_THROW(heap.SiftUp(20));
}


TEST(D_HEAP, can_sift_down)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	heap.Swap(0, 2);
	ASSERT_NO_THROW(heap.SiftDown(0));
}

TEST(D_HEAP, SiftDown_throws_when_negative_index)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	heap.Swap(0, 2);
	ASSERT_ANY_THROW(heap.SiftDown(-4));
}

TEST(D_HEAP, SiftDown_throws_when_index_is_too_large)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	heap.Swap(0, 2);
	ASSERT_ANY_THROW(heap.SiftDown(20));
}


TEST(D_HEAP, can_insert)
{
	D_heap heap(5, 3);
	ASSERT_NO_THROW(heap.PushKey(2));
}

TEST(D_HEAP, insertion_increases_size)
{
	D_heap heap(5, 3);
	int tmp = heap.GetHeapSize();
	heap.PushKey(2);
	EXPECT_EQ(tmp + 1, heap.GetHeapSize());
}


TEST(D_HEAP, can_remove_min)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	ASSERT_NO_THROW(heap.RemoveMin());
}

TEST(D_HEAP, removing_min_decreases_size)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	int tmp = heap.GetHeapSize();
	heap.RemoveMin();
	EXPECT_EQ(tmp - 1, heap.GetHeapSize());
}

TEST(D_HEAP, cant_remove_min_from_empty_heap)
{
	D_heap heap(5, 3);
	ASSERT_ANY_THROW(heap.RemoveMin());
}


TEST(D_HEAP, can_remove_element)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	ASSERT_NO_THROW(heap.RemoveInd(1));
}

TEST(D_HEAP, removing_element_decreases_size)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	int tmp = heap.GetHeapSize();
	heap.RemoveInd(1);
	EXPECT_EQ(tmp - 1, heap.GetHeapSize());
}

TEST(D_HEAP, cant_remove_element_from_empty_heap)
{
	D_heap heap(5, 3);
	ASSERT_ANY_THROW(heap.RemoveInd(1));
}


TEST(D_HEAP, throws_when_remove_element_with_negative_index)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	ASSERT_ANY_THROW(heap.RemoveInd(-1));
}

TEST(D_HEAP, throws_when_remove_element_with_too_large_index)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	ASSERT_ANY_THROW(heap.RemoveInd(20));
}


TEST(D_HEAP, swap_does_not_change_size)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	int tmp = heap.GetHeapSize();
	heap.Swap(0, 2);
	EXPECT_EQ(tmp, heap.GetHeapSize());
}

TEST(D_HEAP, SiftUp_does_not_change_size)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	int tmp = heap.GetHeapSize();
	heap.Swap(0, 2);
	heap.SiftUp(4);
	EXPECT_EQ(tmp, heap.GetHeapSize());
}

TEST(D_HEAP, SiftDown_does_not_change_size)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	int tmp = heap.GetHeapSize();
	heap.Swap(0, 2);
	heap.SiftDown(0);
	EXPECT_EQ(tmp, heap.GetHeapSize());
}

TEST(D_HEAP, heapify_does_not_change_size)
{
	D_heap heap(5, 3);
	for (int i = 0; i < 5; i++)
		heap.PushKey(i);
	int tmp = heap.GetHeapSize();
	heap.Swap(0, 2);
	heap.Heapify();
	EXPECT_EQ(tmp, heap.GetHeapSize());
}
