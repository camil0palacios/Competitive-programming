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

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int o = 0;
    fori(i,0,n) o += s[i] == '1';
    if(s[0] == '0' || s[n-1] == '0' || o & 1) { cout << "NO" << endl; return; }
    o /= 2;
    string a, b;
    bool t = 0;
    fori(i,0,n) {
        if(s[i] == '1') {
            if(o > 0) {
                a += '(', b += '(';
            } else {
                a += ')', b += ')';
            }
            o--;
        } else {
            if(t) {
                a += '(';
                b += ')';
            } else {
                a += ')';
                b += '(';
            }
            t ^= 1; 
        }
    } 
    cout << "YES" << endl;
    cout << a << endl << b << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}