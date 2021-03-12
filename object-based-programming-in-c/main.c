#include <stdio.h> 
#include "rect.h"

int main() 
{
    rect_t r1; 
    init(&r1,12,10); 
    printf("The details of the rectangle : \n"); 
    r1.ptr_vtable->disp(&r1);
    printf("The area of the rectangle : %d \n",r1.ptr_vtable->area(&r1)); 
    printf("The perimeter of the rectangle : %d\n",r1.ptr_vtable->peri(&r1));  
}

