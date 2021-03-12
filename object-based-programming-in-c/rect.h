#include <stdio.h>  

#ifndef RECT_H  
#define RECT_H 

struct rect_t;
typedef struct rect rect_t; 

struct vtable 
{
    int (*peri)(rect_t * ptr); 
    int (*area)(rect_t * ptr); 
    void (*disp)(rect_t * ptr); 
}; 

struct rect
{
    int length; 
    int breadth; 
    struct vtable * ptr_vtable;
}; 

void init(rect_t * ptr, int length, int breadth); 


#endif 

