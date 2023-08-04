#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int num[8];
int visited[8];
int arr[8];
void dfs(int depth){
    if(depth==m){
        for(int i=0; i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int j=0;j<n;j++){
        if(visited[j])continue;
        visited[j]=1;
        arr[depth]=num[j];
        dfs(depth+1);
        visited[j]=0;
    }
    //1 7 8 9

}
int main(){
    //input
    cin>>n>>m;
    int temp;
    for(int i=0; i<n;i++){
        cin>>num[i];
    }
    //sort
    sort(num,num+n);
    dfs(0);
}
