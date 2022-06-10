template <typename T>
List<T>::List(const T& value) : head{new Node<T>(value)}
{
    ++size_of_node;
}

template<typename T>
List<T>::List(const std::initializer_list<T>& values)
{
    for(auto i : values)
    {
        push(i);
    }
    Node<T>* current = head;
 
    if((current == nullptr) || (current -> next == nullptr))
    {
        return;
    }
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    while(current != nullptr)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template <typename T>
List<T>::List(const List<T> &obj)
{
    if (obj.head == nullptr)
    {
        head = nullptr;
    }
    else
    {
        head = new Node<T>(obj.head -> data);
        Node<T> *current = head;
        Node<T> *objHead = obj.head;
        Node<T>* currentObj = objHead;
        while (currentObj -> next != nullptr)
        {
            current -> next = new Node<T>(currentObj -> next -> data);
            currentObj = currentObj -> next;
            current = current -> next;
        }
    }
    size_of_node = obj.size_of_node;
}

template<typename T>
List<T>::List(List<T>&& obj)
{
    head = obj.head;
    size_of_node = obj.size_of_node;
    obj.head = nullptr;
    obj.size_of_node = 0;
}

template<typename T>
List<T>& List<T>::operator = (const List& obj)
{
    if(this == &obj) {return *this;}
    if (obj.head == nullptr)
    {
        head = nullptr;
    }
    else
    {
        head = new Node<T>(obj.head -> data);
        Node<T>* current = head;
        Node<T>* objHead = obj.head;
        Node<T>* currentObj = objHead;
        while (currentObj -> next != nullptr)
        {
            current -> next = new Node<T>(currentObj -> next -> data);
            currentObj = currentObj -> next;
            current = current -> next;
        }
    }
    size_of_node = obj.size_of_node;
    return *this;
}

template <typename T>
List<T>& List<T>::choosing_operation()
{
    std::cout << "============================================================" << std::endl;
    std::cout << "\t\t\t\t\t\tMAIN MANU\t\t\t" << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << std::endl << "Which operation do you choose ?" << std::endl << std::endl;
    std::cout << "\t[1]  Insert \t\n" << "\t[2]  Return the number of list size \t\n" << "\t[3]  Pop from list \t\n" << "\t[4]  Push inside list \t\n" << "\t[5]  Checking the list emptiness \t\n" << "\t[6]  Clear \t\n" << "\t[7]  Traverse \t\n" << "\t[8]  Exit menu operations \t\n" << "\t[9]  EXIT ALL \t\n" << std::endl;
    int index = 0;
    std::cout << "========================================= Choose by index: ";
    std::cin >> index;
    std::cout << std::endl;
    List<T>::choose(index);
    return *this;
}


template <typename T>
List<T>& List<T>::choose(int index)
{
    switch(index)
        {
            case 1:
                List<T>::choose_insert();
                choosing_operation();
                break;
            case 2:
                List<T>::size();
                choosing_operation();
                break;
            case 3:
                List<T>::choose_pop();
                choosing_operation();
                break;
            case 4:
                List<T>::choose_push();
                choosing_operation();
                break;
            case 5:
                if(empty()){std::cout << "It is empty\n\n";}
                else{std::cout << "It is not empty\n\n";}
                choosing_operation();
                break;
            case 6:
                List<T>::clear();
                std::cout << "List is cleared" << std::endl << std::endl;
                choosing_operation();
                break;
            case 7:
                List<T>::choose_traverse();
                choosing_operation();
                break;
            case 8:
                break;
            case 9:
                exit(0);
            default:
                std::cout << "No operation, you have entered a wrong index, try again: ";
                int tryagain = 0;
                std::cin >> tryagain;
                choose(tryagain);
        }
    return *this;
}

template <typename T>
void List<T>::choose_insert()
{
    std::cout << "Enter the value you want to insert: ";
    T val{};
    std::cin >> val;
    std::cout << "Now enter the position you want to insert: ";
    std::size_t pos;
    std::cin >> pos;
    List<T>::insert(val, pos);
    Node<T>* current = head;
    std::cout << std::endl;
    while(current != nullptr)
    {
        std::cout << current -> data << " -> ";
        current = current -> next;
    }
    std::cout << "nullptr";
    std::cout << std::endl << std::endl;
}

template <typename T>
void List<T>::size()
{
    std::cout << "Size: " << size_of_node << std::endl << std::endl;
}

template <typename T>
void List<T>::choose_pop()
{
    List<T>::pop();
    std::cout << "It is popped" << std::endl << "The result is: ";
    Node<T>* current = head;
    while(current != nullptr)
    {
        std::cout << current -> data << " -> ";
        current = current -> next;
    }
    std::cout << "nullptr";
    std::cout << std::endl << std::endl;
}

template <typename T>
void List<T>::clear()
{
    while(head != nullptr){pop();}
}

template <typename T>
void List<T>::choose_push()
{
    std::cout << "Enter the value you want to push: ";
    T val{};
    std::cin >> val;
    List<T>::push(val);
    Node<T>* current = head;
    std::cout << "The result is: ";
    while(current != nullptr)
    {
        std::cout << current -> data << " -> ";
        current = current -> next;
    }
    std::cout << "nullptr";
    std::cout << std::endl << std::endl;
}

template <typename T>
void List<T>::choose_traverse()
{
    List<T>::traverse();
    std::cout << "List is traversed" << std::endl;
    Node<T>* current = head;
 
    if((current == nullptr) || (current -> next == nullptr))
    {
        return;
    }
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    while(current != nullptr)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    
    Node<T>* print = head;
    std::cout << "The result is: ";
    while(print != nullptr)
    {
        std::cout << print -> data << " -> ";
        print = print -> next;
    }
    std::cout << "nullptr";
    std::cout << std::endl << std::endl;
}

template <typename T>
std::ostream& operator << (std::ostream& COUT, const List<T>& oth)
{
    Node<T>* current = oth -> head;
    Node<T>* previous= nullptr;
    while(current != nullptr)
    {
        std::cout << current -> data << " -> ";
    }
    COUT << "nullptr\n";
    return COUT;
}

template<typename T>
List<T>& List<T>::operator = (List<T>&& obj)
{
    head = obj.head;
    size_of_node = obj.size_of_node;
    obj.head = nullptr;
    obj.size_of_node = 0;
    return *this;
}

template<typename T>
bool List<T>::empty()
{
    if(head == nullptr){return true;}
    return false;
}

template<typename T>
void List<T>::push(const T& value)
{
    Node<T>* node = new Node<T>(value, head);
    head = node;
    ++size_of_node;
}

template <typename T>
void List<T>::push(T&& value)
{
    Node<T>* node = new Node<T>(value, head);
    head = node;
    ++size_of_node;
}

template<typename T>
void List<T>::pop()
{
    if(head == nullptr){return;}
    Node<T>* node = head -> next;
    delete head;
    head = node;
    --size_of_node;
}

template <typename T>
void List<T>::insert(const T& value, std::size_t position)
{
    if((position < 0) || (position > size_of_node))
    {
        std::cout << "Error: out of its length !" << std::endl;
        exit(1);
    }
    if(position == 0)
    {
        push(value);
        return;
    }
    Node<T>* node = new Node<T> (value);
    Node<T>* current = head;
    for(int i = 1; i < position; ++i)
    {
        current = current -> next;
    }
    node -> next = current -> next;
    current -> next = node;
    ++size_of_node;
}

template<typename T>
void List<T>::traverse()
{
    Node<T>* current = head;
    while(current != nullptr)
    {
        current = current -> next;
    }
}

template <typename T>
List<T>::~List()
{
    while(head != nullptr){pop();}
}
