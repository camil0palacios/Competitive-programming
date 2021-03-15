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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int f[100000];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, m;
    cin >> n;
    m = n;
    int k = 0;
    for(ll i = 2; i*i <= m; i++) {
        while(m % i == 0) {
            m /= i;
            f[k++] = i;          
        }
    }
    if(m > 1) f[k++] = m;
    if(k == 2) cout << 2 << endl;
    else {
        cout << 1 << endl;
        cout << f[0]*f[1] << endl;
    }
    return 0; 
}