#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int typedef element;
typedef struct NODE{
    element data;
    struct NODE* Left;
    struct NODE* Right;
}Node;
typedef struct HEAD{
    Node *Top;
}Head;

void Insert_front(element item,Head *Now);
void Insert_behind(element item,Head *Now);
element Pop_back( Head *Now);
element Pop_front(Head *Now);
void Print_List(Head *Now);
int Empty(Head *Now);
void Search(Head *Now);


