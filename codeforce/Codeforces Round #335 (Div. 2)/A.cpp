#include <bits/stdc++.h>
using namespace std;

int main(){

    int ex[3],ne[3],dif[3];
    int pos = 0,neg = 0;

    for(int i=0; i < 3 ; i++)
        cin>> ex[i];

    for(int i=0; i < 3; i++)
        cin>> ne[i];

    for(int i=0; i < 3; i++)
        dif[i]= ex[i] - ne[i];

    for(int i=0; i < 3; i++){
        if(dif[i]>0)pos+=dif[i]/2;
        else neg+=dif[i];
    }

    if(pos >= -neg)cout<<"yes";
    else cout<< "no";
}
