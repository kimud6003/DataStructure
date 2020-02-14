#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <sys/time.h>
using namespace std;

int index_search(vector<int> arr,int key) 
{ 
    int size = arr.size();
    int tmp =size;
    int cnt=0;
    while(tmp){
        tmp/=10;
        cnt+=tmp;
    }
    int elements[cnt], indices[cnt],i; 
    int ind = 0, start, end; 
    stack<int> inds;
    tmp=size;
    while(tmp){
       tmp/=10;  
       inds.push(ind);
       int k=0;
        for(int j=0; j<tmp; j++){
            elements[ind] = arr[k]; 
            indices[ind++] = k; 
            k+=10;
        }
       inds.push(ind);
    }
    if (key < elements[0]) return -1;
        else { 
            while(!inds.empty()){
                int inds_E=inds.top(); inds.pop();
                int inds_S=inds.top(); inds.pop();
                 
         for (i =inds_S ; i <= inds_E; i++) 
          if (key < elements[i]) { 
            start = indices[i - 1]; 
            end = indices[i]; 
            break; 
              }
        for (i = start; i <= end; i++) { 
         if (key == elements[i]) { 
            return i;
                } 
            } 
        } 
        for (i = start; i <= end; i++) { 
         if (key == arr[i])  
            return i;
                } 
    }
     return -1; 
      
}
float time_set(vector<int>arr,int key,int(*sea)(vector<int>,int),string s){
      struct timeval start_point, end_point;
      double operating_time;
      gettimeofday(&start_point, NULL);
 
      printf("%s의 탐색 위치는 = %d\n",s.c_str(),sea(arr,key)); 
 
      gettimeofday(&end_point, NULL);
      operating_time = (double)(end_point.tv_sec)+(double)(end_point.tv_usec)/1000000.0-(double)(start_point.tv_sec)-(double)(start_point.tv_usec)/1000000.0;
      return operating_time;
  }
 

int main(int argc, char* argv[]){
    int num;
    scanf("%d",&num);
    vector<int> a;
    for(int i=0; i<100000 ; i++)
        a.push_back(i);

    printf("%lf\n",time_set(a,num,index_search,"index_search"));
    return 0;
}






