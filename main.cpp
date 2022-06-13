#include "list_header.h"

int main()
{
    int n = 0;
    List<int> list{1,2,3,4,5,6};
    list.choosing_operation();
    list.insert(n, 1);
    list.print_forward();
    return 0;
}
