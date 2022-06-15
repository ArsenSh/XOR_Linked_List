#ifndef LIST_HEADER_H
#define LIST_HEADER_H
#include <iostream>
#include <initializer_list>
#include <utility>

template <typename T>
class List;

template <typename T>
std::ostream& operator << (std::ostream& COUT, const List<T>& oth);


template <typename T>
class List
{
public:
    template <typename N>
    friend std::ostream& operator << (std::ostream& COUT, const List<N>& oth);
    List() = default;
    List(const T& value);
    List(const std::initializer_list<T>& values);
    List(const List<T>& copy);
    List(List<T>&& move);
    List& operator = (const List<T>& copy);
    List& operator = (List<T> &&obj);
    List& choosing_operation();
    List& choose(int index);
    ~List();
    
    void insert(T& value, std::size_t position);
    void size();
    void push_front(const T& object);
    void push_back(const T& object);
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
    void choose_print();
    
private:
    class Node
    {
    public:
        Node *npx{nullptr};
        T data{};
    public:
        Node(const T& Data){data = Data;}
    };
    
    Node* first = nullptr;
    Node* last = nullptr;
    Node* XOR(Node* x, Node* y)const;
    std::size_t size_of_list{};
};


#include "implementation.hpp"

#endif /* LIST_HEADER_H */

