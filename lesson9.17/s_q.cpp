#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int main(int argc,char* argv[]){
    stack<int> s;
    queue<int> q;
    int i; 
    for(i =0; i< 10; i++){
    s.push(i);
    q.push(i);
    };
    printf("--------------stack-------------;\n");
    for(i =0 ; i<10; i++){
        printf("s.top=%d\n",s.top()) ;
        s.pop();
        printf("\n");
    };
    printf("\n");
    printf("--------------Queue-------------;\n");
    for(i =0 ; i<10; i++){
        printf("q.front=%d\n",q.front()) ;
        q.pop();
        printf("\n");
    };
    printf("\n");
    return 0;
    
}

