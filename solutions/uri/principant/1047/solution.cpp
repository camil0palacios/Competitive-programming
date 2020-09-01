#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int h1,min1,h2,min2;
    cin>>h1>>min1>>h2>>min2;
    int h, m;
    if(h1 == h2 && min1 < min2){
        h=0;
        m = min2 - min1;
    }
    else{
        if( h1 == h2)h=24;
        else if(h1 > h2)h = (24 - h1) + h2; 
        else if(h1 < h2)h = h2-h1;
        
        if(min1 == min2)m=0;
        else if(min1 < min2) m = min2 - min1;
        else if(min1 > min2){
            m = (60 - min1) + min2;
            h --;
        }
    }
    cout<<"O JOGO DUROU "<<h<<" HORA(S) E "<<m<<" MINUTO(S)"<<endl;
 
    return 0;
}