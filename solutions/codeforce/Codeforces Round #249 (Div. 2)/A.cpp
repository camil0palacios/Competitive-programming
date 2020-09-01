#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a,cupo=0,buses=0;
    vector<int> cola;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n ; i++){
        cin>>a;
        cola.push_back(a);
    }

    for(int i=0; i < cola.size(); i++){
        if(cupo+cola[i] <= m){
            cupo += cola[i];
            if(i == cola.size()-1)
                buses++;
        }else{
            buses++;
            cupo = cola[i];
            if(i == cola.size()-1)
                buses++;
        }
    }
    printf("\n%d",buses);
}
