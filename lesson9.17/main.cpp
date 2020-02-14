#include "head.h"

int main(int argc,char*argv[]){
    ListNode *head =NULL;
   int input=0, loop=1;

    while(loop){
    printMenu();
    scanf("%d",&input);
    switch(input){
        case 1: AddList(&head); break;
        case 2: RemoveList(&head); break;
        case 3: DisplayList(&head); break;
        case 4: FindList(&head); break;
        case 5: GetSize(&head); break;
        case 6: loop = 0; break;
        default: printf("wrong inut..\n"); break;
        }   
    }
    free(head); 
return 0;
}

