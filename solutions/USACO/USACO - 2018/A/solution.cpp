#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);
    
    int c[3], m[3], j = 0;
    cin >> c[0] >> m[0] >> c[1] >> m[1] >> c[2] >> m[2];
    for(int i = 1; i <= 100; i++){
        if(j == 2){
            if(m[2] + m[0] <= c[0]){
                m[0] += m[2];
                m[2] = 0;
            }
            else{
                m[2] -= c[0] - m[0];
                m[0] = c[0];
            }
        }else{
            if(m[j] + m[j + 1] <= c[j + 1]){
                m[j + 1] += m[j];
                m[j] = 0;
            }else{
                m[j] -= c[j+1] - m[j + 1];
                m[j + 1] = c[j + 1];
            }
        }
        j++;
        if(j >= 3)j = 0;
    }
    cout << m[0] << endl << m[1] << endl << m[2] << endl;
    return 0;
}