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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

ii to_num(string & s) {
    ii c = {0, 0};
    bool dot = 0;
    fori(i,0,sz(s)) {
        if(s[i] == '.') { dot = 1; continue; }
        if(s[i] == '$') continue;
        if(dot) c.sd = c.sd*10 + (s[i]-'0');
        else c.ft = c.ft*10 + (s[i]-'0');
    }
    return c;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; string s;
    cin >> n >> s;
    ii c = to_num(s);
    int ans = 0;
    fori(i,0,n) {
        cin >> s;
        auto p = to_num(s);
        int d = c.sd + p.sd;
        c.ft += p.ft;
        c.sd = d % 100;
        if(d >= 100) c.ft++;
        if(c.sd != 0) ans++; 
    }
    cout << ans << endl;
    return 0;
}