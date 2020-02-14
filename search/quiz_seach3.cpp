#include <stdio.h>
#include <vector>
#include <string>
#include <sys/time.h>
using namespace std;

void NotOverLap(vector<int>&F){
    int x,y;
    srand(time(NULL));

    for(int i=0; i<(int)F.size(); i ++)
        F[i]= i+1;
    for(int i=0; i<(int)F.size(); i ++){
        x=rand()%F.size();
        y=rand()%F.size();
        if(x!=y){
            swap(F[x],F[y]);
        }
    
    }
}

int seq_search(vector<int> arr,int key){
    for(int i=0; i < arr.size(); i++){
        if(arr[i]==key)
            return i;
    }
    return -1;
}

int seq_search2(vector<int>arr,int key)
{ 
  int i;
  int low=0;
  int high=arr.size();
  arr[high+1] = key;   
  for(i=low; arr[i] != key; i++) 
    ;
  if(i==(high+1)) return -1;  
  else     return i;         
}
int search_binary(vector<int> arr,int key)
{
  int middle;
  int low=0;
  int high=arr.size();
 while( low <= high ){          
    middle = (low+high)/2;
    if( key == arr[middle] ) return middle;    
    else if( key > arr[middle] ) low = middle+1;   
    else high = middle-1;           
    }
 return -1;                     
}
int index_search(vector<int> arr,int key) 
{ 
    int size = arr.size();
    int elements[size/3], indices[size/3],i; 
    int j = 0, ind = 0, start, end; 
    for (i = 0; i < size; i += 3) { 
            elements[ind] = arr[i]; 
            indices[ind++] = i; 
    } 
if (key < elements[0]) { 
    return -1;
    } 
    else { 
        for (i = 1; i <= ind; i++) 
        if (key < elements[i]) { 
            start = indices[i - 1]; 
            end = indices[i]; 
            break; 
        } 
    } 
        for (i = start; i <= end; i++) { 
        if (key == arr[i]) { 
            j = 1; 
            break; 
        } 
    } 
    if (j == 1) 
        return i;
    else
        return -1;
 } 


int interpol_search(vector<int> arr,int key)
{
    int low, high, j;
    int n = arr.size();
    low = 0;
    high = n - 1;
    while ((arr[high] >= key) && (key > arr[low])) {
            j = ((float)(key - arr[low]) / (arr[high] - arr[low])
                                *(high - low)) + low;
            if (key > arr[j]) low = j + 1;
            else if (key < arr[j]) high = j - 1;
            else low = j;
        }
    if (arr[low] == key) low; 
    else return -1;  
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

    printf("%lf\n",time_set(a,num,seq_search,"seq_search"));
    printf("%lf\n",time_set(a,num,seq_search2,"seq_search2"));
    printf("%lf\n",time_set(a,num,search_binary,"search_binary"));
    printf("%d",index_search(a,num));
    printf("%lf\n",time_set(a,num,interpol_search,"interpol_search"));
    return 0;
}






