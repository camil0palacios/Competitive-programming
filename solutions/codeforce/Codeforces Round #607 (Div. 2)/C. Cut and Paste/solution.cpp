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

const int mod = 1e9 + 7;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int x;
        string s;
        cin >> x >> s;
        ll t = sz(s);
        fore(i,1,x) {
            int y = s[i-1]-'0'-1;
            if(sz(s) < x) {
                string tmp = s.substr(i);
                fori(i,0,y) s += tmp;
            }
            t = (t + ((t-i)*y)%mod) % mod;
        }
        t = (t + mod) % mod;
        cout << t << endl;
    }
    return 0; 
}