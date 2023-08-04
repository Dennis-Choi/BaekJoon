#include <iostream>
#include <algorithm>
using namespace std;

int arr[10][10];
int visited[10][10];
int n,m,k;
int answer = -210000000;
int D[4][2]={{-1,0},{1,0},{0,-1},{0,1}};


void dfs(int depth,int sum){
    if(depth==k){
        answer=max(answer,sum);
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j])continue;
            bool ok=true;
            for(int z=0;z<4;z++){
                int next_r,next_c;
                next_r=i+D[z][0],next_c=j+D[z][1];
                if(next_r>=0 && next_r<n && next_c>=0 && next_c<m){
                    if(visited[next_r][next_c])ok=false;
                }
            }
            if(ok){
                visited[i][j]=true;
                dfs(depth+1,sum+arr[i][j]);
                visited[i][j]=false;
            }
            
        }
    }

}
int main(void){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];

        }
    }
    dfs(0,0);
    cout<<answer;
}

