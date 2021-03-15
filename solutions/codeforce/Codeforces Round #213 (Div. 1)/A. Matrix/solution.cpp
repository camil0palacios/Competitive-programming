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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a;
    string s;
    cin >> a >> s;
    int n = sz(s);
    ll p[n+1];
    p[0] = 0;
    fore(i,1,n) p[i] = p[i-1] + (s[i-1]-'0');
    map<int,int> m;
    fore(i,1,n) {
        fori(j,0,i) {
            m[p[i]-p[j]]++;
        }
    }
    ll h = p[n];
    ll ans = 0;
    if(!a) ans = 1ll*m[0]*(1ll*n*(n+1) - m[0]);
    for(int i = 1; i*i <= a; i++) {
        if(a % i == 0 && a/i <= h) {
            ans += 1ll*m[i]*m[a/i]*(i*i == a ? 1 : 2);
        }
    }
    cout << ans << endl;
    return 0; 
}