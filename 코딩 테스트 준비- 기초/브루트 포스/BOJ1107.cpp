#include <iostream>
#include <cmath>
using namespace std;

//고장난 remote 번호
bool remote[10];
/*n(해당 채널)로 이동하는 것이 가능한지, 가능하면 remote 번호를 몇번 눌러야하는지 */
int check(int n){
    if(n==0){
        if(remote[0]){
            return 0;
        }
        else{
            return 1;
        }
    }
    int len=0;
    while(n>0){
        if(remote[n%10]){
            return 0;
        }
        n=n/10;
        len++;
    }
    return len;
}
int main()
{
    //최소 버튼 개수
    int count;
    //n=target_channel, m=num_of_broken;
    int n,m;
    int tmp;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>tmp;
        //고장난 버튼을 1로 표시
        remote[tmp]=1;
    }
    //일단은 + 버튼 만으로 갈 수 있는 횟수로 초기화
    count=abs(n-100);
    //브루트 포스 알고리즘
    for(int i=0;i<=1000000;i++){
        int c=i;
        //i번 채널로 이동할 수 있는지
        int len=check(c);
        if(len>0){
            //i번 채널에서 n(타겟 채널로) + 버튼 만으로 가는 횟수
            int press=abs(c-n);
            //두개 비교후 작은거로 초기화
            if(count>press+len){
                count=press+len;
            }
        }
    }
    cout<<count;
}