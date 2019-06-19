#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int const nmax = 2e5 + 5;
int a[nmax], pref[nmax], x[nmax];

int main(){
    int n, k, q, l, r;
    cin >> n >> k >> q;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        x[l]++; x[r+1]--;
    }
    int cur = 0;
    for(int i = 1; i < nmax; i++){
        cur += x[i];
        a[i] = cur;
    }
    for(int i = 1; i < nmax; i++){
        pref[i] = pref[i-1];
        if(a[i] >= k)pref[i]++;
    }
    while(q--){
       cin >> l >> r;
       cout << pref[r] - pref[l-1] << endl; 
    }
    return 0;
}