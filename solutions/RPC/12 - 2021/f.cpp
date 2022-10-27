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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    ll b = 0, p = 0;
    multiset<ii> s;
    fori(i,0,n) {
        int x, y; 
        cin >> x >> y;
        b += x, p += y;
        s.insert(mp(x, y));
    }
    int mid = n/2;
    if(n % 2 != 0 || b % mid != 0 || p % mid != 0) {
        cout << "impossible" << endl;
        return 0;
    }
    b /= mid, p /= mid;
    while(!s.empty()) {
        auto pr = *s.begin();
        int x = pr.ft, y = pr.sd;
        s.erase(s.begin());
        auto it = s.find({b - x, p - y});
        if(it == s.end()) break;
        s.erase(it);
    }    
    cout << (!sz(s) ? "possible" : "impossible") << endl;
    return 0; 
}