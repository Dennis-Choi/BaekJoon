#include <iostream>

long long dp[1000001];
int main(){
    int T, N;
    /* TestCase Input */
    scanf("%d",&T);

    /* 약수들의 합을 저장 */
    for(int i = 1; i <= 1000001; i++){
        for(int j = i; j <= 1000001; j+=i){
            dp[j] += i;
        }
    }
    /* 이전 약수의 합 까지 저장 */ 
    for(int i = 2; i <= 1000001; i++){
        dp[i] += dp[i-1];
    }


    for(int j=0; j<T; j++){
        /* Input */
        scanf("%d", &N);
        /* Output */
        printf("%lld\n",dp[N]);
    }

    return 0;
}