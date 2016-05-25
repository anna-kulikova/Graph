#include "Binary_Search_Tree.h"
#include "gtest.h"


TEST(BINARY_SEARCH_TREE, can_create_tree)
{
	ASSERT_NO_THROW(Node *root = new Node);
}

TEST(BINARY_SEARCH_TREE, can_find_node_by_key)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *findnode = new Node;
	ASSERT_NO_THROW(findnode = root.FindKey(n, 15));
}

TEST(BINARY_SEARCH_TREE, find_node_by_key_correctly)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *findnode = root.FindKey(n, 5);
	Node *node = n1;
	EXPECT_EQ(node, findnode);
}

TEST(BINARY_SEARCH_TREE, can_find_min)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *min = new Node;
	ASSERT_NO_THROW(min = root.FindMin(n));
}

TEST(BINARY_SEARCH_TREE, find_min_correctly)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *min = root.FindMin(n);
	Node *node = n1;
	EXPECT_EQ(node, min);
}

TEST(BINARY_SEARCH_TREE, can_find_max)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *max = new Node;
	ASSERT_NO_THROW(max = root.FindMax(n));
}

TEST(BINARY_SEARCH_TREE, find_max_correctly)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *max = root.FindMax(n);
	Node *node = n2;
	EXPECT_EQ(node, max);
}

TEST(BINARY_SEARCH_TREE, can_find_next_node)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *findnode = new Node;
	ASSERT_NO_THROW(findnode = root.FindNext(n));
}

TEST(BINARY_SEARCH_TREE, find_next_node_correctly)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *findnode = root.FindNext(n);
	Node *node = n2;
	EXPECT_EQ(node, findnode);
}

TEST(BINARY_SEARCH_TREE, can_find_previous_node)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *findnode = new Node;
	ASSERT_NO_THROW(findnode = root.FindPrevious(n));
}

TEST(BINARY_SEARCH_TREE, find_previous_node_correctly)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *findnode = root.FindPrevious(n2);
	cout << findnode->key;
	Node *node = n;
	cout << node->key;
	EXPECT_EQ(node, findnode);
}

TEST(BINARY_SEARCH_TREE, can_push_node)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *node = new Node;
	node->key = 18;
	ASSERT_NO_THROW(root.Push(node));
}

TEST(BINARY_SEARCH_TREE, pushes_node_correctly)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *node = new Node;
	node->key = 18;
	root.Push(node);
	EXPECT_EQ(n2->right->key, node->key);
}

TEST(BINARY_SEARCH_TREE, throws_when_findnode_does_not_exist)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *findnode = new Node;
	ASSERT_ANY_THROW(findnode = root.FindKey(n, 20));
}

TEST(BINARY_SEARCH_TREE, throws_when_tree_is_empty_min)
{
	Node *n = 0;
	bst root;
	Node *min = new Node;
	ASSERT_ANY_THROW(min = root.FindMin(n));
}

TEST(BINARY_SEARCH_TREE, throws_when_tree_is_empty_max)
{
	Node *n = 0;
	bst root;
	Node *max = new Node;
	ASSERT_ANY_THROW(max = root.FindMax(n));
}

TEST(BINARY_SEARCH_TREE, throws_when_tree_is_empty_fin_next)
{
	Node *n = 0;
	bst root;
	Node *next = new Node;
	ASSERT_ANY_THROW(next = root.FindNext(n));
}

TEST(BINARY_SEARCH_TREE, throws_when_tree_is_empty_fin_previous)
{
	Node *n = 0;
	bst root;
	Node *prev = new Node;
	ASSERT_ANY_THROW(prev = root.FindPrevious(n));
}

TEST(BINARY_SEARCH_TREE, throws_when_next_node_does_not_exist)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *next = new Node;
	ASSERT_ANY_THROW(next = root.FindNext(n2));
}

TEST(BINARY_SEARCH_TREE, throws_when_previous_node_does_not_exist)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	Node *prev = new Node;
	ASSERT_ANY_THROW(prev = root.FindPrevious(n1));
}

TEST(BINARY_SEARCH_TREE, can_workaround)
{
	Node *n = new Node();
	bst root;
	n->parent = 0;
	n->key = 10;
	Node *n1 = new Node();
	n1->key = 5;
	root.Push(n1);
	Node *n2 = new Node();
	n2->key = 15;
	root.Push(n2);
	n1->left = 0;
	n1->right = 0;
	n2->left = 0;
	n2->right = 0;
	ASSERT_NO_THROW(root.WorkAroundSearch(n));
}