#include <stdio.h>
#include <algorithm>
#define INF 10000
using namespace std;

int main(int argc,char* argv[]) {
    int city, bus, dist[100][100];
    scanf("%d %d", &city, &bus);
    
    for (int i = 0; i < city; i++){
    	for (int j = 0; j < city; j++)
        	if(i==j)
        		dist[i][j]=0;
           	else
           		dist[i][j]=INF;
    	
	}
        
    for (int i = 0; i < bus; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        dist[start - 1][end - 1] = min(cost,dist[start - 1][end - 1]);
    }
    
    for (int k = 0; k < city; k++)
        for (int i = 0; i < city; i++)
            for (int j = 0; j < city; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                
    for (int i = 0; i < city; i++) {
        for (int j = 0; j < city; j++) {
            if (dist[i][j] == INF) dist[i][j] = 0;
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
 
