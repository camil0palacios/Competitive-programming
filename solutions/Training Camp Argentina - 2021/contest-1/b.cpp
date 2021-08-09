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

string shift(string s, int j) {
    string ans;
    fori(i,j,sz(s)) ans += s[i];
    fori(i,0,j) ans += s[i];
    return ans;
}

string change(string s) {
    string ans;
    int d = 10 - (s[0]-'0');
    fori(i,0,sz(s)) ans += char(((s[i]-'0') + d) % 10 + '0');
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    string ans(n, '9');
    fore(i,0,n) ans = min(ans, change(shift(s, i)));
    cout << ans << endl;
    return 0; 
}