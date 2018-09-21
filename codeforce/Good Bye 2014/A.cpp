#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,t;
    scanf("%d %d",&n,&t);
    int c[n-1];
    for(int i=0; i < n-1 ; i++){
        cin>>c[i];
    }
    int i=0;
    while(i < n-1){
        i += c[i];
        if(i+1 == t){printf("%s","YES"); break;}
        else if(i+1 > t){printf("%s","NO"); break;}
    }
}
