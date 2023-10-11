#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* next;
	Node(const T& item) : data(item), next(nullptr) {}
};

template <typename Item_Type>
class LinkedList {
private:
	Node<Item_Type>* head;
	Node<Item_Type>* tail;
	size_t num_items;

public:
	LinkedList();
	~LinkedList();

	void push_front(const Item_Type& item);
	void push_back(const Item_Type& item);
	void pop_front();
	void pop_back();
	Item_Type front() const;
	Item_Type back() const;
	bool empty() const;
	void insert(size_t index, const Item_Type& item);
	bool remove(size_t index);
	size_t find(const Item_Type& item) const;
	void displayList() const;
};
