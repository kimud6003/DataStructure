#include <stdio.h>
#include <malloc.h>
typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;


void AddList(ListNode** head);
void GetSize(ListNode** head);
void FindList(ListNode** head);
void RemoveList(ListNode** head);
void DisplayList(ListNode** head);
void printMenu(void);
void FreeList(ListNode** head);

