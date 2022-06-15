#include "list_header.h"

int main()
{
    List<int> list1{1,2,3,4,5,6,7,8,9};
    List<int> list2(10);
    List<int> list3;

    
    list1.print_forward();
    list2.print_forward();
    list3.print_forward();
    
    std::cout << list1 << std::endl;
    
    return 0;
}
