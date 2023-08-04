#include <iostream>
#include <algorithm>
using namespace std; 

int n,m;
int arr[7];
int num[7];
void dfs(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout<<num[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        num[depth]=arr[i];
        dfs(depth+1);
    }
}
int main(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    dfs(0);
}
