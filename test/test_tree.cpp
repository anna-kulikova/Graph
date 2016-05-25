#include <gtest.h>
#include "binary_search_tree.h"


TEST(bst, can_create_tree)
{
	ASSERT_NO_THROW(bst *tree = new bst());
}

TEST(bst, can_copy_tree)
{
	bst *tree = new bst();
	Node *copytree = new Node();
	copytree->key = 6;
	tree->Push(tree->root, copytree);
	ASSERT_NO_THROW(bst *copytree = new bst(*tree));
}

TEST(bst, copied_tree_is_equal_to_source_one)
{
	bst *a = new bst();
	Node *b = new Node();
	b->key = 6;
	a->Push(a->root, b);
	b->key = 2;
	a->Push(a->root, b);
	bst *c = new bst(*a);
	int d = a->operator==(*c);
	EXPECT_EQ(d, 1);
}

TEST(bst, FindKey_works_properly)
{
	bst *a = new bst();
	Node *b = new Node();
	b->key = 6;
	a->Push(a->root, b);
	b->key = 2;
	a->Push(a->root, b);
	b->key = 8;
	a->Push(a->root, b);
	b->key = 0;
	a->Push(a->root, b);
	b = a->FindKey(a->root, 2);
	EXPECT_EQ(b->key, 2);
}

TEST(bst, FindMin_works_properly)
{
	bst *a = new bst();
	Node *b = new Node();
	b->key = 9;
	a->Push(a->root, b);
	b->key = 6;
	a->Push(a->root, b);
	b->key = 8;
	a->Push(a->root, b);
	b->key = 2;
	a->Push(a->root, b);
	b->key = 4;
	a->Push(a->root, b);
	b->key = 0;
	a->Push(a->root, b);
	b->key = 5;
	a->Push(a->root, b);
	b->key = 1;
	a->Push(a->root, b);
	b->key = 7;
	a->Push(a->root, b);
	Node *c = a->FindMin(a->root);
	EXPECT_EQ(c->key, 0);
}

TEST(bst, throws_when_FindMin_from_empty_tree)
{
	bst *a = new bst();
	ASSERT_ANY_THROW(a->FindMin(a->root));
}

TEST(bst, FindMax_works_properly)
{
	bst *a = new bst();
	Node *b = new Node();
	b->key = 9;
	a->Push(a->root, b);
	b->key = 6;
	a->Push(a->root, b);
	b->key = 8;
	a->Push(a->root, b);
	b->key = 2;
	a->Push(a->root, b);
	b->key = 4;
	a->Push(a->root, b);
	b->key = 0;
	a->Push(a->root, b);
	b->key = 5;
	a->Push(a->root, b);
	b->key = 1;
	a->Push(a->root, b);
	b->key = 7;
	a->Push(a->root, b);
	Node *c = a->FindMax(a->root);
	EXPECT_EQ(c->key, 9);
}

TEST(bst, throws_when_FindMax_from_empty_tree)
{
	bst *a = new bst();
	ASSERT_ANY_THROW(a->FindMax(a->root));
}

TEST(bst, FindNext_works_properly)
{
	bst *a = new bst();
	Node *b = new Node();
	b->key = 9;
	a->Push(a->root, b);
	b->key = 6;
	a->Push(a->root, b);
	b->key = 8;
	a->Push(a->root, b);
	b->key = 2;
	a->Push(a->root, b);
	b->key = 4;
	a->Push(a->root, b);
	b->key = 0;
	a->Push(a->root, b);
	b->key = 5;
	a->Push(a->root, b);
	b->key = 1;
	a->Push(a->root, b);
	b->key = 7;
	a->Push(a->root, b);
	b->key = 6;
	Node *c = a->FindNext(a->root, b);
	EXPECT_EQ(c->key, 7);
}

TEST(bst, can_find_previous)
{
	bst *a = new bst();
	Node *b = new Node();
	b->key = 9;
	a->Push(a->root, b);
	b->key = 6;
	a->Push(a->root, b);
	b->key = 8;
	a->Push(a->root, b);
	b->key = 2;
	a->Push(a->root, b);
	b->key = 4;
	a->Push(a->root, b);
	b->key = 0;
	a->Push(a->root, b);
	b->key = 5;
	a->Push(a->root, b);
	b->key = 1;
	a->Push(a->root, b);
	b->key = 7;
	a->Push(a->root, b);
	b->key = 6;
	Node *c = a->FindPrevious(a->root, b);
	EXPECT_EQ(c->key, 5);
}

TEST(bst, GetSize_works_properly)
{
	bst *a = new bst();
	Node *b = new Node();
	b->key = 9;
	a->Push(a->root, b);
	b->key = 6;
	a->Push(a->root, b);
	b->key = 8;
	a->Push(a->root, b);
	b->key = 2;
	a->Push(a->root, b);
	b->key = 4;
	a->Push(a->root, b);
	b->key = 0;
	a->Push(a->root, b);
	b->key = 5;
	a->Push(a->root, b);
	b->key = 1;
	a->Push(a->root, b);
	b->key = 7;
	a->Push(a->root, b);
	EXPECT_EQ(a->GetSize(), 9);
}

TEST(bst, GetHeight_works_properly)
{
	bst *a = new bst();
	Node *b = new Node();
	b->key = 9;
	a->Push(a->root, b);
	b->key = 6;
	a->Push(a->root, b);
	b->key = 8;
	a->Push(a->root, b);
	b->key = 2;
	a->Push(a->root, b);
	b->key = 4;
	a->Push(a->root, b);
	b->key = 0;
	a->Push(a->root, b);
	b->key = 5;
	a->Push(a->root, b);
	b->key = 1;
	a->Push(a->root, b);
	b->key = 7;
	a->Push(a->root, b);
	EXPECT_EQ(a->GetHeight(a->root), 4);
}

TEST(bst, throws_when_no_next)
{
	bst *a = new bst;
	Node *b = new Node(1);
	ASSERT_ANY_THROW(a->FindNext(a->root, b));
}

TEST(bst, throws_when_no_previous)
{
	bst *a = new bst;
	Node *b = new Node(1);
	ASSERT_ANY_THROW(a->FindPrevious(a->root, b));
}