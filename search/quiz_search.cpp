#include <stdio.h>
#include <vector>
#include <string>
#include <sys/time.h>
using namespace std;

int seq_search(vector<int> arr,int key){
    for(int i=0; i < arr.size(); i++){
        if(arr[i]==key)
            return i;
    }
    return -1;
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
float time_set(vector<int>arr,int key,int(*sea)(vector<int>,int),string s){
      struct timeval start_point, end_point;
      double operating_time;
      gettimeofday(&start_point, NULL);
 
     sea(arr,key); 
 
      gettimeofday(&end_point, NULL);
      operating_time = (double)(end_point.tv_sec)+(double)(end_point.tv_usec)/1000000.0-(double)(start_point.tv_sec)-(double)(start_point.tv_usec)/1000000.0;
      return operating_time;
  }
 

int main(int argc, char* argv[]){
    int num,num2;
    float seq_sum=0;
    float bin_sum=0;
    printf("Input Data Size:\n");
    scanf("%d",&num);
    num2=num/2;
    vector<int> odd_a;
    vector<int> even_a;
    for(int i=1; i<num ; i+=2){
        odd_a.push_back(i+1);
        even_a.push_back(i);
    }
    for(int i=0; i<num/2;i++){
    seq_sum+=time_set(odd_a,even_a[i],seq_search,"seq_search");
    bin_sum+=time_set(odd_a,even_a[i],search_binary,"search_binary");
    }
    
    seq_sum=bin_sum=0;
    for(int i=0; i<num/2;i++){
    seq_sum+=time_set(odd_a,odd_a[i],seq_search,"seq_search");
    bin_sum+=time_set(odd_a,odd_a[i],search_binary,"search_binary");
    }
    return 0;
}






