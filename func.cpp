#include"head.h"


void AddList(ListNode** head){//리스트 추가
    ListNode* tmp=(ListNode*)malloc(sizeof(ListNode));
    ListNode* Top=*head;
    int num;
    printf("숫자 입력:");
    scanf("%d",&num);
    tmp->data=num; tmp->link=NULL;
    if(*head==NULL){
        *head=tmp;
    }
    else{
        for(;Top->link!=NULL;Top=Top->link);
            Top->link=tmp;
        } 
   DisplayList(head);
    }

void RemoveList(ListNode** head)
{
   if(*head==NULL){ // 리스트이 값이 하나도 없을때
       fprintf(stderr,"값이 없다\nNULL\n");
       return;
   }
   else if((*head)->link==NULL){ //리스트의 값이 하나
       fprintf(stderr,"하나의 자료 삭제 완료 \nNULL\n");
        free((*head)->link);
        *head=NULL;
        return;
   }
   else{
   ListNode *after=(*head)->link;
   ListNode *before=*head;
   int num;
   printf("삭제할수를 입력바랍니다:");
   scanf("%d",&num); 
     while(after->data!=num){
        if(before->data==num)
        {     *head=after;  
            free(before);
            DisplayList(head);
            return;
        }
         before=after;
        after=after->link;
    }
    before->link=after->link;
    free(after);
    }

   DisplayList(head);
}
void DisplayList(ListNode** head){
    ListNode *roop=*head;
     while(roop!=NULL){
            printf("%d-> " ,roop->data) ;
        roop=roop->link;    
    }
     printf("NULL\n");
}

void FindList(ListNode** head)
{
    int num;
    printf("검색:");
    scanf("%d",&num);
    int count=0;
    ListNode* roop=*head;
    while(roop!=NULL){
        count++;
        if(roop->data==num){
            printf("찾는 숫자는%d번째에 있습니다 \n",count) ;
            return;
        }              
        roop=roop->link;    
    }
    printf("찾는 숫자는 없습니다 \n");

}
void GetSize(ListNode** head){
    ListNode* roop=*head;
    int size=0;
    while(roop!=NULL){
        size++;
        roop=roop->link;
        }              
    printf("리스트의 크기는%d\n",size) ;
}
void printMenu(void){
   printf("-------------------------\n");
   printf("메뉴\n");
   printf("1. 원소등록 \n");
   printf("2. 원소삭제 \n");
   printf("3. 원소내역 \n");
   printf("4. 원소검색  \n");
   printf("5. 원소개수 \n");
   printf("6. 종료\n");
   printf("-------------------------\n");
}
void FreeList(ListNode** head){
    ListNode* before,*after=*head;
    while(after){
        before=after;
        after=after->link;
        free(before);
    }
}
