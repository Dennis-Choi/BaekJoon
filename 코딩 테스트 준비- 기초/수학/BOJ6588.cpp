#include <iostream>
long long dp[1000001];
int main(){
    long long N;

    //에라토스테네스의 체 만들어 놓기
    for(int i = 2; i<=1000000;i++){
       dp[i]=i;
    }
    for(int i = 2; i<=1000000;i++){
        if(dp[i]==0)continue;
        for(int j=2*i;j<=1000000;j+=i){
            dp[j]=0;
        }
    } 

    while(true){
        //Input
        scanf("%lld",&N);
        //Stop
        if(N==0)break;
        //Output
        for(long long i=N-1; i>1;i--){
            if(N == dp[i] + dp[N-i]){
                printf("%lld = %lld + %lld\n", N,dp[N-i],dp[i]);
                break;
            }
        }
    }   
}