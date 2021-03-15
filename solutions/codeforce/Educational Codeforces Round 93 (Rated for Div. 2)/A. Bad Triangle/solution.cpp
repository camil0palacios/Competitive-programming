#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

bool check(ll a, ll b, ll c) {
    return a + b > c && a + c > b && b + c > a;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vll a(n);
        fori(i,0,n) cin >> a[i];
        if(!check(a[0], a[1], a[n-1])) {
            cout << 1 << ' ' << 2 << ' ' << n << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0; 
}