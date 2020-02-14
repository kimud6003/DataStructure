#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SET 100

typedef struct Tree_Node{
    int cap;
    char CH;
    struct Tree_Node * Left,*Right;
}Tree_Node;

typedef struct Heap_Node{
    int cap;
    char CH;
    Tree_Node* P_tree;
}Heap_Node;

typedef struct HEAP{
    Heap_Node heap[SET];
    int Last;
}HEAP;
//-------------------Struct---------

HEAP* Heap_Make(){  
    HEAP* tmp =(HEAP*)malloc(sizeof(HEAP*));
    tmp->Last=0;
    return tmp;}

void Init_Heap(HEAP* heap){}

void Insert_Min_Heap(HEAP* h,Heap_Node item)
{
    int i= ++(h->Last);
    while ((i != 1) && (item.cap < h->heap[i / 2].cap)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
        }
    h->heap[i] = item;     
}

Heap_Node Delete_Heap(HEAP* H){
    int parent=1, child=2;
    Heap_Node root, cmp;
    root = H->heap[1];
    cmp = H->heap[(H->Last)--];
    while (child <= H->Last) {
            if ((H->heap[child].cap) > H->heap[child + 1].cap)child++;
            if (cmp.cap < H->heap[child].cap) break;
            H->heap[parent] = H->heap[child];
            parent = child;
            child *= 2;
        }
    H->heap[parent] = cmp;
    return root;
    
}
//-------------------HEAP--------------------------
void Input_String(char** String){
    printf("문자열 입력:");
    fgets(*String,SET,stdin);
}
void Arrange_String(char *String,Heap_Node**Arrange){
       for(int i=strlen(String)-2;i>=0;i--){
      (*Arrange)[String[i]-'a'].CH=String[i];
     (*Arrange)[String[i]-'a'].cap++;
   } 
}
void Compression(Heap_Node*Arrange);
//-------------------ARRAY--------------------------
Tree_Node* Make_Tree(Tree_Node* Left,Tree_Node* Right){
    
    Tree_Node* tmp = (Tree_Node*)malloc(sizeof(Tree_Node));
    tmp->Left=Left;
    tmp->Right=Right;
    return tmp;
}
int is_leaf(Tree_Node* root)
{
    return !(root->Left) && !(root->Right);
}
void print_array(int codes[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", codes[i]);
    //printf("\n");
}

void Print_Code(Tree_Node* root, int codes[], int top)
{
    if (root->Left) {
            codes[top] = 1;
            Print_Code(root->Left, codes, top + 1);
        }
    if (root->Right) {
            codes[top] = 0;
            Print_Code(root->Right, codes, top + 1);
        }
    if (is_leaf(root)) {
    //        printf("%c: ", root->CH);
            print_array(codes, top);
        }
}
void Make_Huff(Heap_Node** Root,char*String,Heap_Node* Arrange){
    
    int i,count=0;
    HEAP* H = Heap_Make();
    Tree_Node*node,*x;
    Heap_Node *e=*Root;
    Heap_Node e1,e2;
    int code[100];
    
    for(i=0;i<30;i++){
        if(Arrange[i].cap!=0){
        node=Make_Tree(NULL,NULL);
        (*e).CH=node->CH=Arrange[i].CH;
        (*e).cap=node->cap=Arrange[i].cap;
        (*e).P_tree=node;
        Insert_Min_Heap(H, *e);
        count++;
        }
    }
    for(i=1;i<count;i++){
    e1=Delete_Heap(H); 
    e2=Delete_Heap(H); 
    x=Make_Tree(e1.P_tree,e2.P_tree);
    (*e).cap=x->cap=e1.cap+e2.cap;
    (*e).P_tree = x;
    printf("\n%d+%d->%d \n",e1.cap,e2.cap,(*e).cap);
    Insert_Min_Heap(H,*e);
    }
    *e=Delete_Heap(H);
    Print_Code(e->P_tree,code,0);
}
//------------Fucking Huffman-------------
int main(void)
{
    int code[100];
    Heap_Node *Root=(Heap_Node*)malloc(sizeof(Heap_Node));
    Heap_Node* Arrange = (Heap_Node*)malloc(sizeof(Heap_Node)*30);
    char* String =(char*) malloc(sizeof(char)*100);
    Input_String(&String);
    Arrange_String(String,&Arrange);
    Make_Huff(&Root,String,Arrange);
    return 0;
}
