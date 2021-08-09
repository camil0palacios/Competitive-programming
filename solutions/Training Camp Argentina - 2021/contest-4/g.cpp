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

int p[26];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        memset(p, 0, sizeof p);        
        fori(i,0,n) {
            string s;
            cin >> s;
            fori(j,0,sz(s)) p[s[j]-'a']++;
        }
        bool ok = 1;
        fori(i,0,26) ok &= p[i] % n == 0;
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}