#include <iostream>
#include <cstdlib>
using namespace std;

int n;
int S[20][20];
int visited[20];
int sum1, sum2;
int target_depth=2;
int result = 99999999;
void dfs(int depth, int start)
{
    if (depth == target_depth)
    {
        sum1 = 0;
        sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i] && visited[j])
                {
                    sum1 += S[i][j];
                }
                else if (!visited[i] && !visited[j])
                {
                    sum2 += S[i][j];
                }
            }
        }
        int tmp = abs(sum1 - sum2);
        if (tmp < result)
        {
            result = tmp;
        }
    }
    for (int i = start; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(depth + 1, i + 1);
            visited[i] = false;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &S[i][j]);
        }
    }
    while(target_depth<=n/2){
        dfs(0, 0);
        target_depth++;
    }
    
    printf("%d", result);
}