#pragma once

#include <functional>
#include <utility>

template <class T>
class Tree
{
public:
    Tree() {}
    ~Tree() { clear(); }
    void clear()
    {
        traverse_postorder(root, [](Node* node) { delete node; });
        root = nullptr;
    }
    bool is_empty() const { return root == nullptr; }
    size_t size()
    {
        size_t count = 0;
        traverse_postorder(root, [&count](Node* node) { ++count; });
        return count;
    }
    void insert(T val)
    {
        Node* prev{nullptr};
        Node* p = root;
        while (p)
        {
            prev = p;
            if (p->value < val)
                p = p->right;
            else
                p = p->left;
        }
        if (root == nullptr)
        {
            root = Node::create(val);
        }
        else if (prev->value < val)
        {
            prev->right = Node::create(val);
        }
        else if (prev->value > val)
        {
            prev->left = Node::create(val);
        }
    }
    void traverse_preorder(std::function<void(const T& val)> f) { traverse_preorder(root, f); }
    void traverse_inorder(std::function<void(const T& val)> f) { traverse_inorder(root, f); }
    void traverse_postorder(std::function<void(const T& val)> f) { traverse_postorder(root, f); }

private:
    class Node
    {
    public:
        static Node* create(const T& val) { return new Node(val); }
        Node(const T& val) : value(val){};
        T value;
        Node* left{nullptr};
        Node* right{nullptr};
    };
    Node* root{nullptr};

    void traverse_postorder(Node* node, std::function<void(Node* node)> f)
    {
        if (node)
        {
            traverse_postorder(node->left, f);
            traverse_postorder(node->right, f);
            f(node);
        }
    }
    void traverse_preorder(Node* node, std::function<void(const T& val)> f)
    {
        if (node)
        {
            f(node->value);
            traverse_preorder(node->left, f);
            traverse_preorder(node->right, f);
        }
    }
    void traverse_inorder(Node* node, std::function<void(const T& val)> f)
    {
        if (node)
        {
            traverse_inorder(node->left, f);
            f(node->value);
            traverse_inorder(node->right, f);
        }
    }
    void traverse_postorder(Node* node, std::function<void(const T& val)> f)
    {
        if (node)
        {
            traverse_postorder(node->left, f);
            traverse_postorder(node->right, f);
            f(node->value);
        }
    }
    bool find(T val) const
    {
        Node* p = root;
        while (p)
        {
            if (p->value == val) return true;
            if (p->value < val)
                p = p->right;
            else
                p = p->left;
        }
        return false;
    }
};
