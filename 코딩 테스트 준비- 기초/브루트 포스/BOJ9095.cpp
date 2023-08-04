#include <iostream>

using namespace std;
int dp[11]={1,2,4};

int main(){
    int T,n;
    //testcase
    cin>>T;
    //10까지 만들 수 있는 조합 규칙
    for(int i=3;i<11;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    for(int i = 0; i < T; i++){
        //input
        cin>>n;
        cout<<dp[n-1]<<'\n'; 
    }
}
