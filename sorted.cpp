#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct field{
    int num;
    char name;
    float exam;
}FIELD;
FIELD sorted[100];

void insert_sort(vector<FIELD>& f){
 int j, least;
 int n=f.size();
    for(int i=0; i<n-1; i++) {
            least = i;
            for(j=i+1; j<n; j++)            // 최솟값 탐색
                if(f[j].num<f[least].num)
                least = j;
    swap(f[i], f[least]);

    }
}
//----------------------------------------------------------------------삽입 
void buble_sort(vector<FIELD>& f)
{  
    int i, j;
    int n=f.size();
    for(i=n-1; i>0; i--){
        for(j=0; j<i; j++)  // 앞뒤의 레코드를 비교한 후 교체
            if(f[j].num>f[j+1].num)   
            swap(f[j], f[j+1]);
    }
}
//----------------------------------------------------------------------버블
void insertion_sort(vector<FIELD>& f, int fst, int last, int gap)
{
    int i, j,key;
    FIELD tmp;
    for(i=fst+gap; i<=last; i=i+gap){
        key = f[i].num;
        tmp=f[i];
        for(j=i-gap; j>=fst && key<f[j].num;j=j-gap)
            f[j+gap]=f[j];
        f[j+gap]=tmp;
        }
}

void shell_sort( vector<FIELD>& f)   // n = size
{
    int i, gap;
    int n = f.size();
    for( gap=n/2; gap>0; gap = gap/2 ) {
        if( (gap%2) == 0 ) gap++;
            for(i=0;i<gap;i++)      // 부분 리스트의 개수는 gap
            insertion_sort(f, i, n-1, gap);
        }
}
//------------------------------------------------------------------------쉘 정렬 

void merge(vector<FIELD>& f, int left, int mid, int right)
{
    int i, j, k;
    i=left; j=mid+1; k=left;
        while(i<=mid && j<=right){
            if(f[i].num<=f[j].num)
              sorted[k++] = f[i++];
            else sorted[k++] = f[j++];
    }
}
                
                
void merge_sort(vector<FIELD>& f, int left, int right)
{
    int mid;
    if(left<right){
    mid = (left+right)/2;              
    merge_sort(f, left, mid);     
    merge_sort(f, mid+1, right);
    merge(f, left, mid, right);    
        }
}
int main(int argc, char* argv[]){
    vector<FIELD> F;
    F.push_back(FIELD{1,'a',3.14});
    F.push_back(FIELD{38,'t',2.14});
    F.push_back(FIELD{221,'c',5.14});
    F.push_back(FIELD{155,'k',1.14});
    F.push_back(FIELD{22,'z',9.14});
    F.push_back(FIELD{21,'p',7.14});
    //insert_sort(F);
    //buble_sort(F);
    //shell_sort(F);
    merge_sort(F);
    for(int i=0; i<6; i++)
      printf("%d %c %.2f \n",F[i].num,F[i].name,F[i].exam); 

    return 0;
}
