#include <bits/stdc++.h>
#define llu long long unsigned
using namespace std;

const int NM = 5000000;
llu phi[NM+2];

void calc_phi(){
    for(int i = 2; i <= NM; i++){
        phi[i] = i;
    }
    for(int i = 2; i <= NM; i++){
        if(phi[i] == i){
            for(int j = i ; j <= NM ; j += i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}

void calc_sum(){
    phi[1] = 0;
    for(int i = 2; i <= NM; i++){
        phi[i] = phi[i-1] + phi[i]*phi[i];
    }
}

void solve(){
    llu x, y;
    scanf("%llu %llu",&x, &y);
    printf("%llu\n", phi[y]-phi[x-1]);
}

int main(){
    calc_phi();
    calc_sum();
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++){
        printf("Case %d: ", cs);
        solve();
    }
}