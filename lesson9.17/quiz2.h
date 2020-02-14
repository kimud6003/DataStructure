#include <stdio.h>
#include <malloc.h>
typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;
typedef struct Head{
    ListNode* Top;
}Head;

void AddList(Head *Now,int item);
void RemoveList(Head *Now) ;
void DisplayList(Head *Now);
void FindList(Head *Now);
void GetSize(Head *Now);
void printMenu(void);
