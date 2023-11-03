#pragma once

#include <iostream>
#include <sstream>
#include <string>

// single linked list<int>
// add
// print

namespace interview
{
template <typename T>
class List
{
public:
    List() {}
    ~List()
    {
        Node* node = head;
        while (node != nullptr)
        {
            Node* next = node->next;
            delete node;
            node = next;
        }
    }
    void add(const T& val)
    {
        if (head == nullptr)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            Node* node = new Node(val);
            tail->next = node;
            tail = node;
        }
    }
    void print()
    {
        Node* node = head;
        while (node != nullptr)
        {
            std::cout << node->value << ", ";
            node = node->next;
        }
        std::cout << std::endl;
    }
    std::string to_string()
    {
        std::stringstream ss;
        Node* node = head;
        while (node != nullptr)
        {
            ss << node->value << ",";
            node = node->next;
        }
        std::string res = ss.str();
        if (!res.empty()) res.pop_back();
        return res;
    }

private:
    class Node
    {
    public:
        Node(const T& val) : value(val){};
        T value;
        Node* next{nullptr};
    };
    Node* head{nullptr};
    Node* tail{nullptr};
};
} // namespace interview
