#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>
#include <sys/time.h>
using namespace std;

void print_Sorted(vector<int>&F,string s){
        printf("\n\n%s\n",s.c_str());
        for(int i=0; i<F.size();i++)
        printf("%d ",F[i]);

}
//----------------------------------------------------출력--------------------
void NotOverLap(vector<int>&F){
    int x,y,tmp;
    srand(time(NULL));

    for(int i=0; i<F.size(); i ++)
        F[i]= i+1;
    for(int i=0; i<F.size(); i ++){
        x=rand()%F.size();
        y=rand()%F.size();
        if(x!=y){
            tmp=F[x];
            F[x]=F[y];
            F[y]=tmp;
        }
    
    }
}
// -----------------------------------------------------중복없는 랜덤값 넣기
void merge(vector<int>& f, int left, int mid, int right)
{
    int i, j, k,l;
    int sorted[right];
    i=k=left; j=mid+1; 
        while(i<=mid && j<=right){
            if(f[i]<=f[j])
              sorted[k++] = f[i++];
            else sorted[k++] = f[j++];
    }
    if(i>mid)
        for(l=j; l<=right; l++)
        sorted[k++] = f[l];
    else    
        for(l=i; l<=mid; l++)
        sorted[k++] = f[l];

    for(l=left; l<=right; l++)
    f[l] = sorted[l];
}
                
void merge_sort(vector<int>& f, int left, int right)
{
    int mid;
    if(left<right){
    mid = (left+right)/2;              
    merge_sort(f, left, mid);     
    merge_sort(f, mid+1, right);
    merge(f, left, mid, right);    
        }
}
//---------------------------------------------------------------------합병 정렬 
//
int partition(vector<int>&f, int left, int right){
    int pivot,low,high;
    low =left;
    high=right+1;
    pivot = f[left];
    do{
        do
            low++;
        while(low<=right && f[low]<pivot);
        do
             high--;
        while(high>=left&&f[high]>pivot);

        if(low<high) swap(f[low],f[high]);
    }while(low<high);
    swap(f[left],f[high]);
    return high;
}

void quick_sort(vector<int>&f,int left,int right){
    if(left<right){
        int q = partition(f,left,right) ;
        quick_sort(f,left,q-1);
        quick_sort(f,q+1,right);
    }
}
//------------------------------------------------------TimeSet-------------------------------------

float time_set(vector<int>&F,void(*Sort)(vector<int>&,int,int)){
    struct timeval start_point, end_point;
    double operating_time;
   gettimeofday(&start_point, NULL);
    Sort(F,0,F.size()) ;
    gettimeofday(&end_point, NULL); 
    operating_time = (double)(end_point.tv_sec)+(double)(end_point.tv_usec)/1000000.0-(double)(start_point.tv_sec)-(double)(start_point.tv_usec)/1000000.0;
    return operating_time;
  
}


//-----------------------------------------------------------------퀵정렬---------------



int main(int argc, char* argv[]){
    double Q_TIME,M_TIME;
    int roop;
    scanf("%d",&roop);
    vector<int> M(roop),Q(roop);
    NotOverLap(M);
    sleep(1);
    NotOverLap(Q);
    print_Sorted(M,"Before");
    print_Sorted(Q,"Before");

    printf("\n\n-----------after----------\n");
    M_TIME=time_set(M,merge_sort);
    Q_TIME=time_set(Q,quick_sort);
    print_Sorted(M,"Merge");
    print_Sorted(Q,"Quick");
    printf("\n\nM_TIME= %f , Q_TIME=%f\n",M_TIME,Q_TIME);

    return 0;
}
