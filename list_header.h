#ifndef list_header_h
#define list_header_h
#include <iostream>
#include <initializer_list>

template <typename T>
struct Node
{
    Node<T> *next{nullptr};
    T data{};
    Node<T>() = default;
    Node<T>(const T &value, Node<T> *ptr = nullptr) : data{value}, next{ptr} {}
};

template <typename T>
class List
{
private:
    Node<T>* head = nullptr;
    Node<T>* Xor(Node<T>* x, Node<T>* y)
    {
        return reinterpret_cast<Node<T>*>(reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
    }
    std::size_t size_of_node{};
    
public:
    List() = default;
    List(const T& value);
    List(const std::initializer_list<T>& values);
    List(const List<T> &obj);
    List& choosing_operation();
    List& choose(int index);
    List(List<T> &&obj);
    List& operator = (const List<T> &obj);
    List& operator = (List<T> &&obj);
    friend std::ostream& operator << (std::ostream& COUT, const List<T>& oth);
    ~List();
    
public:
    void insert(const T& value, std::size_t position);
    void size();
    void pop();
    void push(const T &value);
    void push(T&& value);
    bool empty();
    void clear();
    void traverse();
    
    void reverse_node() noexcept;
    void choose_insert();
    void choose_push();
    void choose_pop();
    void choose_traverse();
};

#include "implementation.hpp"

#endif /* list_header_h */

