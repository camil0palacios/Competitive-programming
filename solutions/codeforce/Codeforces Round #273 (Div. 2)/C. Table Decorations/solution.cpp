#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll a[3];
    fori(i, 0, 3) cin >> a[i];
    sort(a, a + 3);
    ll s = (a[0]+a[1]+a[2])/3;
    if(a[0] + a[1] < s) s = a[0] + a[1]; 
    cout << s << endl;
    return 0; 
}