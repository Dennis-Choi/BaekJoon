#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int h[9];
    int sum=0;
    //input
    for(int i = 0 ; i < 9; i++){
        scanf("%d",&h[i]);
        sum+=h[i];
    }
    sort(h,h+9);
    
    //전체에서 2개 빼서 100이 되는지 확인
    for(int i = 0; i <8; i++){
        for(int j = i+1; j<9; j++){
            if(sum - h[i]-h[j]==100){
                //output
                for(int k=0;k<9;k++){
                    if(k==i || k==j)continue;
                    printf("%d\n",h[k]);
                }
                return 0;
            }
        }
    }
}