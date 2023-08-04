#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n,result=0;
    cin>>n;
    for (int i = 1; i <= n; i *= 10) 
		result += n - i + 1;
    //n=120인 경우: 120(1의 자리 개수)+111(10의자리 개수)+21(100의 자리 개수)
    cout<<result;
}

