#include <iostream>
#include <string>
using namespace std;

int k;
char arr[9];
int visited[10];
string mx,mn;

bool possible(int i, int j, char k) {
	if (k == '<')return i < j;
	if (k == '>')return i > j;
	return true;
}


void dfs(int depth,string s){
    if(depth==k+1){
        if(!mn.size()){
            mn=s;
        }
        else mx=s;
        return;
    }
    for(int i=0;i<10;i++){
        if(!visited[i]){
            if(depth==0 || possible(s[depth-1],i+'0',arr[depth-1])){
                visited[i]=true;
                dfs(depth+1,s+to_string(i));
                visited[i]=false;
            }
        }
    }
}
int main(){
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    dfs(0,"");
    cout<<mx<<'\n';
    cout<<mn<<'\n';
}