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

string a, s;
set<string> ans;

void rec(int i, bool op, string & tmp) {
    if(i == sz(s) || op) {
        ans.insert(tmp + s.substr(i));
        return;
    }
    tmp.push_back(s[i]);
    rec(i+1, 0, tmp);
    tmp.pop_back();
    rec(i+1, 1, tmp);
    fori(j,0,sz(a)) {
        tmp.push_back(a[j]);
        rec(i, 1, tmp);
        rec(i+1, 1, tmp);
        tmp.pop_back();
        tmp.push_back(s[i]);
        tmp.push_back(a[j]);
        rec(i+1, 1, tmp);
        tmp.pop_back();
        tmp.pop_back();
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> s;
    string tmp;
    rec(0, 0, tmp);
    ans.erase(s);
    for(auto t : ans) cout << t << endl;
    return 0; 
}