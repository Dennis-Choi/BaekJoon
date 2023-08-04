#include <iostream>
#include <algorithm>
using namespace std;

int N,MAX=0;
char b[51][51];
void find_max(){
    int tmp;
    //row case;
    for(int i=0;i<N;i++){
        tmp=1;
        for(int j=0;j<N;j++){
            if(b[i][j]==b[i][j+1])tmp++;
            else{
                if(MAX<=tmp)MAX=tmp;
                tmp=1;
            }
        }  
    }
    //col case
    for(int i=0;i<N;i++){
        tmp=1;
        for(int j=0;j<N;j++){
            if(b[j][i]==b[j+1][i])tmp++;
            else{
                if(MAX<=tmp)MAX=tmp;
                tmp=1;
            }
        }
    }
}


int main(){
    //input size
    cin>>N;
    //input candy
    for(int i=0; i<N; i++){
        for(int j=0;j<N;j++){
            cin>>b[i][j];
        }
    }
    //find row case
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            //swap
                swap(b[i][j],b[i][j+1]);
            //check
                find_max();
            //return
                 swap(b[i][j],b[i][j+1]);
            }
    }
    //find col case
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){

            //swap
                swap(b[j][i],b[j+1][i]);
            //check
                find_max();
            //return
                swap(b[j][i],b[j+1][i]);
        }
    }  
    cout<<MAX<<'\n';
}
