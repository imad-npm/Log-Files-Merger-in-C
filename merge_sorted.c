#include <stdio.h>

int main()
{

    int list1[] = {10, 20, 30, 40};
    int list2[] = {1, 12, 13, 24};
    int l1 = sizeof(list1) / sizeof(int);
    int l2 = sizeof(list2) / sizeof(int);
    int *sorted = merge(list1,l1 ,list2,l2);

    for (int i = 0; i < l1+l2; i++)
    {
        printf("%d \n", sorted[i]);
        /* code */
    }
}