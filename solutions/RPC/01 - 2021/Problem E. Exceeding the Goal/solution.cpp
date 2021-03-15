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

ll k, s, g;

bool check(ll m) {
    return s*m + k*(m*(m-1)/2) > g;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> k >> s >> g;
        ll l = 0, r = k/2;
        while(l <= r) {
            ll m = (l + r) >> 1;
            if(check(m)) r = m-1;
            else l = m+1;
        }
        r++;
        cout << s*(r) + k*(r*(r-1)/2) << endl;
        cout << r << endl;
    }
    return 0; 
}