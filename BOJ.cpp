#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    int x,y;
}Node;

typedef struct Length_Node{
    double dist;
    int B_node,A_node;
}Length_node;

int find (int par[],int num){
    if(par[num]==num) return num;
    return par[num] = find(par,par[num]);
}
int Union(int par[],int x,int y){
    int Px = find(par,x);	 //루트찾기 
    int Py = find(par,y);	//루트찾기 
    if(Px==Py) return 0;  //같은 좌표라면 0 
    par[Px]=Py;			 // 아니라면 합해라 
    return 1;
}
double get_length(int x1, int x2, int y1,int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void Swap(Length_node arr[], int a, int b) // a,b 스왑 함수 
{
    Length_node temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int Partition(Length_node arr[], int left, int right)
{
    double pivot = arr[left].dist;  // 피벗의 위치는 가장 왼쪽에서 시작
    int low = left + 1;
    int high = right;
 
    while (low <= high) // 교차되기 전까지 반복한다 
    {
        while (pivot >= arr[low].dist && low <= right){ // 피벗보다 큰 값을 찾는 과정 
            low++;  // low를 오른쪽으로 이동 
        	}
        while (pivot <= arr[high].dist && high >= (left+1) ){ // 피벗보다 작은 값을 찾는 과정 
            high--;  // high를 왼쪽으로 이동
            }
        if (low <= high){ // 교차되지 않은 상태이면 스왑 과정 실행 
            Swap(arr, low, high);  //low와 high를 스왑 
            }
	}
    Swap(arr, left, high);  // 피벗과 high가 가리키는 대상을 교환 
    return high;  // 옮겨진 피벗의 위치정보를 반환 
 
}
 
 
void QuickSort(Length_node arr[], int left, int right)
{
    if (left <= right)
    { 
            int pivot = Partition(arr, left, right);  // 둘른로 나누어서
            QuickSort(arr, left, pivot - 1);  // 왼쪽 영역을 정렬한다.
            QuickSort(arr, pivot + 1, right);  // 오쪽 영역을 정렬한다.
        }
}

int main(int argc,char* argv[]){
    int node_num,road_num; // node는 전체 노드 갯수, road는 연결된 노드 갯수 
    int Count =0 ; 		  //  node끼리 연결할수있는 링크의 갯수 
    int par [1000] = {0}; // kruskal 방식을 위한 배열 
    double ans = 0;		  // 답 출력 변수 
    scanf("%d %d",&node_num,&road_num);  // 변수 받기 
    Node Total_Node[node_num];			// 받은 노드의 x,y좌표 저장하는 구조체 배열 
    Length_Node NODES[node_num*node_num]={0,}; // 노드 끼리의 연결된 길이를 저장하는 구조체 배열 
    Node Link_Node[road_num];				  // 미리 연결된 노드를 저장하는 구조체 배열 

    for(int i=1; i<= node_num; i++){
    scanf("%d %d",&(Total_Node[i].x),&(Total_Node[i].y));	// x좌표 y좌표 입력 
    par[i]=i;											
    }

    for(int j=0; j < road_num; j++){
    scanf("%d %d",&Link_Node[j].x,&Link_Node[j].y); 	//연결된 노드연결 
    Union(par,Link_Node[j].x,Link_Node[j].y);			// union에서 집적 연결 
    }

    for(int i=1; i<=node_num; i++){
        for(int j=i+1; j<=node_num;j++){
            double len = get_length(Total_Node[i].x,Total_Node[j].x,Total_Node[i].y,Total_Node[j].y);	//노드간의 길이를 len에 저장 
            NODES[Count].dist=len;	// 구조체에 dist에 len삽입 
            NODES[Count].B_node =i; // 구조체 B.node에 연결된 노드가 몇번쨰인지 저장 
            NODES[Count].A_node=j;	// 구조체 B.node에 연결된 노드가 몇번쨰인지 저장 
            Count++;
        }
    }
    QuickSort(NODES,0,Count-1); 	// 퀵정렬로 정렬 
    int roop=0;
    int cnt =road_num;
    while(roop<Count && cnt!=node_num-1){
    if(Union(par,NODES[roop].B_node,NODES[roop].A_node)) {
        ans=ans+NODES[roop].dist;
        cnt++;
    }
        roop++;
    }
    
    printf("%.2lf",ans);
    return 0;
}
