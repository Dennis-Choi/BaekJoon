#include <iostream>

using namespace std;

int main(){
    int e,s,m;
    int se=1,ss=1,sm=1;
    int year=1;
    cin>>e>>s>>m;
    while(true){
        if(se==e && ss==s && sm ==m){
            cout<<year;
            break;
        }
        se++;ss++;sm++;
        year++;
        if(se%16==0)se=1;
        if(ss%29==0)ss=1;
        if(sm%20==0)sm=1;
    }

}