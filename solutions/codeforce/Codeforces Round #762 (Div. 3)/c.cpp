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
    int t;
    cin >> t;
    while(t--) {
        ll a, s;
        cin >> a >> s;
        bool f = 0;
        ll cnt = 1, b = 0;
        while(a || s) {
            int x = a % 10;
            int y = s % 10;
            if(x > y && (s%100)/10 == 1) y = s % 100, s /= 100;
            else s /= 10;
            a /= 10;
            if(x > y) { f = 1; break; }
            b += (y - x)*cnt;
            cnt *= 10;
        }
        if(f) cout << -1 << endl;
        else cout << b << endl;
    }
    return 0; 
}