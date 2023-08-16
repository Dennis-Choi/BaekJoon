#include <iostream>

using namespace std;
int arr[10000];
int n;
bool func(){
    int i=n-1;
    while(i>0 && arr[i-1]>arr[i]){
        --i;
    }
    if(i<=0)return false;
    int j=n-1;
    while(arr[i-1]>arr[j]){
        --j;
    }
    swap(arr[i-1],arr[j]);
    for(int k=i,h=n-1;k<h;++k,--h){
        swap(arr[k],arr[h]);
    }
    return true;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(func()){
        for(int i=0;i<n;++i){
            cout<<arr[i]<<' ';
        }
    }
    else
    {
        cout<<-1;
    }
}