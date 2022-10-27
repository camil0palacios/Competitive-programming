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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    map<string, int> m, cnt;
    fori(i,0,n) {
        string s;
        cin >> s;
        m[s] += i;
        cnt[s]++;
    }
    vector<pair<double, string>> ans;
    for(auto p : m) ans.eb(1.0*p.sd/cnt[p.ft], p.ft);
    sort(all(ans));
    for(auto p : ans) cout << p.sd << endl;
    return 0; 
}