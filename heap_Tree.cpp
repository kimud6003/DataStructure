#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_ELEMENT 200

typedef struct HeapType{
    int heap[MAX_ELEMENT];
    int size;
} HeapType;

HeapType* MakeUp(){
    return (HeapType*)malloc(sizeof(HeapType*));
}
void Init_Heap(HeapType* H){
    H->size=0;
}

void Insert_Heap(HeapType* H, int item){
    int i;
    for(i=++(H->size);i!=1;i/=2){
        if(item<H->heap[i/2]) H->heap[i]=H->heap[i/2];  
        else break;
    }
    H->heap[i]=item;
}

int Delete_Heap(HeapType* H){

    int Parent=1,Child=2;
    int item,temp;
    item = H->heap[1];
    temp=H->heap[H->size--];
    while(Child<=H->size){
        if(H->heap[Child]<H->heap[Child+1]) Child++;

        if(temp>=H->heap[Child])break;
        H->heap[Parent]=H->heap[Child];
        Parent=Child;
        Child*=2;
    }
    H->heap[Parent]=temp;
    return item;
}

int main(void)
{
    int e1=10,e2=5,e3=30;
    int e4, e5, e6;
    HeapType* heap;

    heap =MakeUp ();
    Init_Heap(heap);
    Insert_Heap(heap, e1);
    Insert_Heap(heap, e2);
    Insert_Heap(heap, e3);

    e4 = Delete_Heap(heap);
    printf("< %d > ", e4);
    e5 = Delete_Heap(heap);
    printf("< %d > ", e5);
    e6 = Delete_Heap(heap);
    printf("< %d > \n", e6);
    free(heap);
    return 0;
} 

