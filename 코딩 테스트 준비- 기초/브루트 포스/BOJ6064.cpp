#include <iostream>

using namespace std;

int m, n, x, y;
// 최대 공약수
int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
// 최소 공배수
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int year()
{
    int limit = lcm(m, n);
    int j;
    for (j = x; j <= limit; j += m)
    {
        int temp = (j % n == 0) ? n : j % n;
        if (temp == y)
        {
            return j;
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n >> x >> y;
        cout<<year()<<'\n';
    }
}

