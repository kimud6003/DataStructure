#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define SET 10

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* init_node(int data){  
    TreeNode *tmp = (TreeNode*)malloc(sizeof(TreeNode*));
    tmp->data = data;
    tmp->left=tmp->right=NULL;
    return tmp;
}
void Print_BST(TreeNode *Root)
{
    if(!Root) return;
    printf("%d ",Root->data);
    Print_BST(Root->left);
    Print_BST(Root->right);
}
TreeNode* insert_BST(TreeNode *Root,int data){
    if(!Root) return init_node(data);
    if(data<Root->data) Root->left=insert_BST(Root->left,data);
    else if(data>Root->data) Root->right=insert_BST(Root->right,data);
    return Root;
}
void Insert_BST(TreeNode **Root){
    int num;
    printf("추가값 입력:");
    scanf("%d",&num);
    *Root=insert_BST(*Root,num);
    Print_BST(*Root);
}

TreeNode* Max_Node(TreeNode *Root){
    while(Root->right){Root=Root->right;}
    return Root;
}

TreeNode* delete_BST(TreeNode *Root,int num,int*def){
    TreeNode* tmp =Root ;
    if (!tmp) return tmp;
    if(num < tmp->data) tmp->left=delete_BST(tmp->left,num,def);
    else if(num >tmp->data) tmp->right=delete_BST(tmp->right,num,def);
    else{
        *def=1;
        if(tmp->left ==NULL){
           TreeNode *bridge = tmp->right;
           free(tmp);
           return bridge;
        }
        else if(tmp->right ==NULL){
            TreeNode *bridge = tmp->left;
           free(tmp);
            return bridge; 
        
        }
        TreeNode *bridge = Max_Node(tmp->right);
        tmp->data=bridge->data;
        tmp->right=delete_BST(tmp->right,bridge->data,def);
    }
        return tmp;
}

void Delete_BST(TreeNode **Root){
    int num;
    int def=0;
    printf("지우고 싶은 값을 입력:");
    scanf("%d",&num);
    if(!*Root){printf("트리가 비어있다\n"); return;}
    *Root=delete_BST(*Root,num,&def);
    if(def==0)printf("지우고자 하는값이 X\n");
    Print_BST(*Root);
}

TreeNode* search_BST(TreeNode *Root,int data,int* def){
    if(!Root) return Root ;
    if(data<Root->data) return search_BST(Root->left,data,def);
    else if(data>Root->data) return search_BST(Root->right,data,def);
    else {
        *def=1;
        return Root;
    }
}
void Search_BST(TreeNode *Root){
    TreeNode *tmp;
    int num;
    int def=0;
    printf("찾을려는 숫자를 입력하시오:");
    scanf("%d",&num);
    if(!Root){printf("Root는 NULL\n"); return;}
    tmp=search_BST(Root,num,&def);
    if(def==1)printf("%d는 있습니다\n",tmp->data);
    else printf("%d는 없습니다\n",num);
    
}
void Menu(){
    printf("\n-----------------------\n");
    printf("1.삽입\n");
    printf("2.삭제\n");
    printf("3.출력\n");
    printf("4.탐색\n");
    printf("5.트리모양으로 출력 \n");
    printf("6.EXIT\n");
    printf("-----------------------\n");

}
void Print_TreeShape(TreeNode *root, int spacebar) 
{ 
    if (root == NULL) 
        return; 
    spacebar += SET; 
    Print_TreeShape(root->right, spacebar); 
    printf("\n"); 
//    for (int i = SET; i < spacebar; i++) printf(" "); 
    printf("%d\n", root->data); 
    Print_TreeShape(root->left, spacebar); 
}


int main(int argc,char*argv[]){
    TreeNode * Root=NULL;
    int select,roop=1;
   while(roop){
     Menu();
     scanf("%d",&select);
     switch(select){
        case 1: Insert_BST(&Root); break;
        case 2: Delete_BST(&Root); break;
        case 3: Print_BST(Root); break;
        case 4: Search_BST(Root); break;
        case 5:  Print_TreeShape(Root,0); break;
        case 6: roop=0;
     }
   } 

return 0;
}
