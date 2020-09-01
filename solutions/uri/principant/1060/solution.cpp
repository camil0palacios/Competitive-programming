#include <bits/stdc++.h>
using namespace std;

int main(){
 
    int cont=0; 
    double tmp;
    for(int i = 0; i < 6; i++){
        cin>>tmp;
        if(tmp > 0)cont++;
    }
    cout<<cont<<" valores positivos"<<endl;
 
    return 0;
}