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

bool hasA(string & s) {
    for(auto & c : s) {
        if(c == 'a') return 1;
    }
    return 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        if(hasA(s) && hasA(t) && sz(t) > 1) {
            cout << -1 << endl;
            continue;
        }
        int cnt = 0;
        fori(i,0,sz(s)) cnt += s[i] == 'a';
        if(hasA(t)) cout << 1 << endl;
        else cout << (1ll << cnt) << endl;
    }
    return 0; 
}