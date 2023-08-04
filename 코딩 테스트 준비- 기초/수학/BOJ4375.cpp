#include <iostream>
using namespace std;

/* 자리수 찾는 함수 */
int testfunc(int num)
{
    int start=1, count = 1;
    while(true){
        if(start%num== 0)return count;
        start=start*10+1;
        count++;
        start %= num;
    }
}

/* 메인 함수 */ 
int main(void)
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    /* Input */
    int input;
    while (cin >> input)
    {
        /* Output */
        cout<<testfunc(input)<<endl;
    }
}