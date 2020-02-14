#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100 
#define INF 1000000 

typedef struct GraphType{
    int Node_num;
    int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void set_INF(GraphType* g){
    for(int i = 0 ; i< g->Node_num;i++){
        for(int j = 0 ; j < g->Node_num; j++){
            if(i==j) g->weight[i][j]=0;
            else g->weight[i][j]=INF; 
        }
    }
}

void init_seting(int *found,int*ans,GraphType* g,int start){
    for(int i=0; i< g->Node_num;i++){
        ans[i]=g->weight[start][i];
        found[i]=0;
    }
    found[start]=1;
}

int search_min(int *found,int* ans,GraphType* g,int start){
    int tmp = INF;
    int tmp_2;
    for(int i = 0; i< g->Node_num; i++){
        if(found[i]==1) continue;
        
        if(tmp>ans[i]){
          tmp=ans[i];
          tmp_2=i;
        }
    }
    return tmp_2;
}

void shortest_path(GraphType *g,int start){
    int found[g->Node_num]={0};
    int ans[g->Node_num];
    int next_node;
    init_seting(found,ans,g,start);
    for(int i =0; i<g->Node_num-1;i++){
       next_node = search_min(found,ans,g,start);
        found[next_node]=1;
       
       for(int j=0; j<g->Node_num;j++){
           if(ans[j]>g->weight[next_node][j]+ans[next_node])
               ans[j]=g->weight[next_node][j]+ans[next_node];
       } 
    }
    for(int k =0; k<g->Node_num; k++){
        if(ans[k]==INF)
          printf("INF\n");
        else
        printf("%d\n",ans[k]);
    }
   }

int main(void)
{
    GraphType g;
    int roop;
    int start,row,col,wei;
    scanf("%d %d",&g.Node_num,&roop);
    scanf("%d",&start);
    set_INF(&g);

    for(int i=0; i <roop;i++){
        scanf("%d %d %d",&row,&col,&wei);
         g.weight[row-1][col-1]=wei; 
    //     g.weight[col-1][row-1]=wei;
    }
    /*for(int i=0; i<g.Node_num;i++){
        for(int j =0; j<g.Node_num;j++)
            printf("%d\t",g.weight[i][j]);
        printf("\n");
    }*/
    shortest_path(&g,start-1);
    return 0;
}

