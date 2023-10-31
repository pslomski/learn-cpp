#pragma once

#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <utility>
#include <initializer_list>

class ListError : public std::exception {
public:
	ListError(const char* message) : std::exception(message) {}
};

template <class T>
class List {
public:
	List()
	{
	}
	List(const List& lst)
	{
		Node* tmp = lst.head;
		while (tmp) {
			push_back(tmp->value);
			tmp = tmp->next;
		}
	}
	List(List&& lst) noexcept :
		head(std::exchange(lst.head, nullptr)),
		tail(std::exchange(lst.tail, nullptr))
	{
	}
	List(const std::initializer_list<T>& lst)
	{
		for (auto val : lst)
			push_back(val);
	}
	~List()
	{
		clear();
	}
	bool is_empty() const
	{
		return head == nullptr;
	}
	size_t size() const
	{
		int sz = 0;
		Node* tmp = head;
		while (tmp) {
			++sz;
			tmp = tmp->next;
		}
		return sz;
	}
	void clear()
	{
		Node* tmp = head;
		while (head) {
			tmp = head;
			head = head->next;
			delete tmp;
		}
		head = tail = nullptr;
	}
	void push_back(const T& value)
	{
		if (tail == nullptr) {
			head = tail = Node::create(value);
		}
		else {
			Node* tmp = Node::create(value);
			tail->next = tmp;
			tail = tmp;
		}
	}
	void reverse() {
		// Values stay in place
		// Just relink nodes
		if (head == nullptr)
			return;
		tail = head;
		Node* prev = nullptr;
		Node* next = head->next;
		while (next) {
			head->next = prev;
			Node* nextnext = std::exchange(next->next, head);
			prev = std::exchange(head, next);
			next = nextnext;
		}
	}
	void heapsort()
	{
		sort(head, size());
	}
	T& operator[](size_t index) const
	{
		int pos = 0;
		Node* tmp = head;
		while (tmp) {
			if (pos == index) {
				return tmp -> value;
			}
			++pos;
			tmp = tmp->next;
		}
		throw ListError("Invalid index value");
	}
private:
	class Node {
	private:
		Node(const T& val) : value(val) {}
	public:
		T value;
		//Node* prev{ nullptr };
		Node* next{ nullptr };
		static Node* create(const T& value)
		{
			return new Node(value);
		}
	};
	Node* head{ nullptr };
	Node* tail{ nullptr };

	void sort(Node* start, int cnt)
	{
		if (cnt > 1) {
			int mid = cnt / 2;
			//sort(start, mid_node, )
		}
	}
};

#endif // LINKED_LIST_H_INCLUDED
