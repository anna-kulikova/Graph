#pragma once
#include <iostream>

#include "d-heap.h"
#include "binary_search_tree.h"
#include "sort_table.h"


class Priority_Queue {
public:
	virtual void Push(const KeyType&) = 0;
	virtual void Pop(void) = 0;
	virtual KeyType Back(void)const = 0;

	virtual int isFull(void)const = 0;
	virtual int isEmpty(void)const = 0;
};

class on_d_heap : public Priority_Queue {
	D_heap* heap;
public:
	on_d_heap(size_t keysize, size_t d) { heap = new D_heap(keysize, d); }
	on_d_heap(const on_d_heap& heap) { this->heap = new D_heap(*heap.heap);}
	~on_d_heap(void) {delete heap;}

	virtual void Push(const KeyType& data) {
		if (isFull()) throw("err"); // add an exception
		heap->PushKey(data);}
	virtual void Pop(void) { 
		if (isEmpty()) throw("err"); // add an exception
		heap->RemoveMin();}
	virtual KeyType Back(void)const {
		if (isEmpty()) throw("err"); //add an exception
	 return heap->GetKey(0);}

	virtual int isFull(void)const {return heap->GetSize() == heap->GetHeapSize();}
	virtual int isEmpty(void)const {return heap->GetHeapSize() == 0;}
};

class on_table : public Priority_Queue {
	SortTable* table;
public:
	on_table(size_t size) {table = new SortTable(size);}
	on_table(const on_table& table) {this->table = new SortTable(*table.table);}
	~on_table(void) {delete table;}

	virtual void Push(const KeyType& data) {
		if (isFull()) throw("err"); // add an exception
	 table->Push(data, NULL);}
	virtual void Pop(void) { 
		if (isEmpty()) throw("err"); // add an exception
		table->Remove(table->findMin()->GetKey());}
	virtual KeyType Back(void)const {
		if (isEmpty()) throw("err"); // add an exception
		return table->findMin()->GetKey();
	}

	virtual int isFull(void)const {return table->IsFull();}
	virtual int isEmpty(void)const { return table->IsEmpty();}
};

//class on_bst : public Priority_Queue{
//	bst* tree;
//public:
//	on_bst(void) {tree = new bst();}
//	on_bst(const on_bst& q) {tree = new bst(*q.tree);}
//	virtual void Push(const KeyType& data) {
//		if (isFull()) throw("err");
//		tree->Push(&Node(data));// бло. не в тот ашник
//	}
//	virtual void Pop(void) {
//		if (isEmpty()) throw("err");
//		tree->Remove(tree->FindMin(tree->GetRoot())->key);
//	}
//	virtual KeyType Back(void)const {
//		if (isEmpty()) throw("err");
//		return tree->FindMin(tree->GetRoot())->key; // Если поменяла на те, что у тебя до этого были
//	}
//
//	virtual int isFull(void)const {
//		Node* tmp = new Node;
//		if (tmp == NULL)
//			return 1;
//		delete tmp;
//		return 0;
//	}
//	virtual int isEmpty(void)const {
//		if (tree == NULL)
//			throw("queue does not exist");
//		return tree->GetRoot() == NULL;
//	}
//};