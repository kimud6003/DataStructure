#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
 
int main(int argc,char *argv[]) {
	int test_case;
    scanf("%d", &test_case);
    
    while (test_case--) {
       queue<int> q;
	   vector<int> ans;
       int mat[501][501]={0}, before[501], champ[501]={0};
       int team_num,revise,certain=1;
       
        scanf("%d", &team_num);
        for (int i = 1; i <= team_num; i++)
            scanf("%d", &before[i]);
 
        for (int i = 1; i <= team_num; i++) {
            for (int j = i + 1; j <= team_num; j++) {
            	champ[before[j]]++;
                mat[before[i]][before[j]] = 1;
            }
        } 
        scanf("%d", &revise);
        for (int i = 0; i < revise; ++i) {
        	int  num1, num2;
            scanf("%d %d", &num1, &num2);
	            
            if (mat[num1][num2]) {
                mat[num1][num2] = 0;
                mat[num2][num1] = 1;
                champ[num2]--;
				   champ[num1]++;
	            }
            else {
                mat[num2][num1] = 0;
                mat[num1][num2] = 1;
                champ[num1]--;
				champ[num2]++;
            }
        }
        
        for (int i = 1; i <= team_num; i++)
            if (!champ[i])q.push(i);
        
        while (!q.empty()) {
           if (q.size() > 1) {
               certain = 0;
                break;
            }
            int tmp = q.front(); q.pop();
            ans.push_back(tmp);
            for (int next = 1; next <= team_num; next++) {
                if (mat[tmp][next]) {
                    champ[next]--;
                    if (!champ[next])
                        q.push(next);
                }
            }
        }
        
        if (ans.size() != team_num) 
        puts("IMPOSSIBLE");
        
        else
        for (int i = 0; i < team_num; i++)
                printf("%d ", ans[i]);
            
    }
    return 0;
}

 
