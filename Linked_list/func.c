#include "head.h"

void Insert_front(element item,Head *Now){
   Node *tmp = malloc(sizeof(Node)) ;
   tmp->data = item;
   if(Now->Top ==NULL)
       Now->Top=tmp; 
    else{
        Now->Top->Left=tmp;
        tmp->Right=Now->Top;
        Now->Top=tmp; 
    }
}
void Insert_behind(element item,Head *Now){
   Node *tmp = malloc(sizeof(Node)) ;
   Node *tmp_head=malloc(sizeof(Node));
   tmp_head=Now->Top;
   tmp->data = item;
   if(Now->Top==NULL)
       Now->Top=tmp; 
    else{
        while(tmp_head->Right!=NULL){
            tmp_head=tmp_head->Right;
        }
        tmp_head->Right = tmp;
        tmp->Left=tmp_head;
        }
}
element Pop_back(Head *Now){
    Node *tmp_head=malloc(sizeof(Node));
    element result;
    tmp_head=Now->Top;
     while(tmp_head->Right->Right!=NULL){
            tmp_head=tmp_head->Right;
        }
    result = tmp_head->Right->data;
    tmp_head->Right=NULL;
   // free(tmp_head);
    return result;
}
element Pop_front(Head *Now){
    element result;
    result=Now->Top->data;
    Now->Top=Now->Top->Right;
    Now->Top->Left=NULL;
    return result;

}
void Print_List(Head *Now){
   Node *tmp_head=malloc(sizeof(Node));
   tmp_head = Now->Top;
    while(tmp_head!=NULL){
         printf("%d->",tmp_head->data);
            tmp_head=tmp_head->Right;
        }printf("NULL\n");
}
