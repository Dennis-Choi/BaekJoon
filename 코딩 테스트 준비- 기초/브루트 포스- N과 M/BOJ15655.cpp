#include <iostream>
#include <algorithm>
using namespace std; 

int n,m;
int num[8];
int arr[8];
int visited[8];
//1 7 8 9
void dfs(int depth,int start){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=start;i<n;i++){
        if(visited[i])continue;
        visited[i]=1;
        arr[depth]=num[i];
        dfs(depth+1,i);
        visited[i]=0;
    }

}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n);
    dfs(0,0);
}