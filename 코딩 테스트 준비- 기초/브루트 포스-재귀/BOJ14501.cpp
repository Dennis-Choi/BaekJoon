#include <iostream>

using namespace std;

int n;
int T[16], P[16];
int result;
int visited[16];
void dfs(int sum,int start)
{
    if (start > n)
    {
        if (sum > result)
        {
            result = sum;
            return;
        }
    }
    int istrue;
    for (int i = start; i <= n; i++)
    {
        istrue=false;
        if (!visited[i])
        {
            if (i + T[i] - 1 <= n)
            {
                sum += P[i];
                istrue=true;
            }
            visited[i] = true;
            dfs(sum, i + T[i]);
            if(istrue)sum-=P[i];
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> T[i] >> P[i];
    }
    dfs(0,1);
    cout << result;
}