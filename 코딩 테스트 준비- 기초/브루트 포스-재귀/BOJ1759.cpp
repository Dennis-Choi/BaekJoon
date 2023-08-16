#include <iostream>
#include <algorithm>

using namespace std;
int l,c;
char arr[15];
int visited[15];

//a c i s t w

void dfs(int depth,int start){
    
    if(depth==l){
        //ok1: 모음 개수, ok2=자음 개수
        int ok1=0,ok2=0;
        char result[15];
        int idx=0;
        for(int i=0;i<c;i++){
            if(visited[i]){
                result[idx++]=arr[i];
                if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u')ok1++;
                else ok2++;
            }
        }
        if(ok1>=1 && ok2>=2){
            for(int i=0;i<l;i++){
                cout<<result[i];
            }
            cout<<'\n';
        }
        return;

    }
    for(int i=start; i<c;i++){
        if(visited[i])continue;
        visited[i]=true;
        dfs(depth+1,i);
        visited[i]=false;
    }
}
int main(){

    cin>>l>>c;
    for(int i=0;i<c;i++){
        cin>>arr[i];
    }
    sort(arr,arr+c);
    dfs(0,0);
}
