#ifndef list_header_h
#define list_header_h
#include <iostream>
#include <initializer_list>
#include <utility>
#include <vector>

template <typename T>
class List
{
private:
    
    class Node
    {
    public:
        Node *npx{nullptr};
        T data{};
        Node(T& Data){data = Data;}
    };
    
    Node* first = nullptr;
    Node* last = nullptr;
    Node* XOR(Node* x, Node* y);
    std::size_t size_of_list{};
    
public:
    List() = default;
    List(const T& value);
    List(const std::initializer_list<T>& values);
    List(const List<T>& copy);
    List(List<T>&& move);
    List& operator = (const List<T>& copy);
    List& operator = (List<T> &&obj);
    friend std::ostream& operator << (std::ostream& COUT, const List<T>& oth);
    List& choosing_operation();
    List& choose(int index);
    ~List();
    
public:
    void insert(T& value, std::size_t position);
    void size();
    void push_front(T& object);
    void push_back(T& object);
    void pop_front();
    void pop_back();
    bool empty();
    void clear();
    void traverse();
    void swap(List& swapped);
    void print_forward();
    void print_back();
    
    void choose_insert();
    void choose_push();
    void choose_pop();
};


#include "implementation.hpp"

#endif /* list_header_h */

