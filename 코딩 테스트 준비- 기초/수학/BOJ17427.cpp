#include <iostream>

using namespace std;

int main(){
    /* Input */
    int N;
    cin>>N;
    
    /* Output */
    long long ans = 0;
    for(int i = 1; i <= N; i++){
        ans += (N/i) *i;
    }
    cout << ans;
}
