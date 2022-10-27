#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 2e5 + 5;
int fac[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll q;
    cin >> q;
    int k = 0;
    for(ll i = 2; i*i <= q; i++) {  
        while(q % i == 0) {
            q /= i;
            fac[k++] = i;
        }
    }
    if(q > 1) fac[k++] = q;
    if(k == 2) cout << 2 << endl;
    else {
        cout << 1 << endl;
        cout << fac[0]*fac[1] << endl;
    }
    return 0; 
}