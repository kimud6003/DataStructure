#include "head.h"

int main(int argc,char*argv[]){
    Head *head=malloc(sizeof(Head));
    Insert_front(3,head);
    Insert_front(2,head);
    Insert_front(1,head);
    Print_List(head);
    printf("%d\n",Pop_back(head));
    Print_List(head);
    Insert_behind(10,head);
    Print_List(head);
    printf("%d\n",Pop_front(head));
    Print_List(head);
    return 0;
   

}
