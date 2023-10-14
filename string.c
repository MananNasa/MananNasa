#include<stdio.h>
int main()
{
    char*str4 = " Hello HRU I am fine";
    printf("String-4: %s\n", str4);
    printf("Address stored in the pointer : %p\n", str4);
    printf("Address allocated in the pointer : %p\n", &str4);

    str4 = " What do you study?";       //New Address(with new string)is assigned
    printf("String-4: %s\n", str4);

    //Modification of individual character is not possible (ReadOnly part of Data Segment)
    printf("First character: %c\n", str4[0]);
    
    str4[0] = 'Y';                       //Segmentation fault ( Core Dumped)
    *(str4+1) = 'a';                    //Segmentation fault ( Core Dumped) 

    return 0;
}
