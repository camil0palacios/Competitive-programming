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

const int Mxn = 1e5 + 5;
// const int p = 65537
const int p = 31;
const int m1 = 39916801;
const int m2 = 479001599;
pair<ll,ll> h[Mxn];
pair<ll,ll> pow_p[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = sz(s);
    pow_p[0].ft = pow_p[0].sd = 1; 
    fori(i,0,n) {
        pow_p[i+1].ft = (pow_p[i].ft*p) % m1;
        pow_p[i+1].sd = (pow_p[i].sd*p) % m2;
    }
    fori(i,0,n) {
        h[i+1].ft = (h[i].ft + (s[i]-'a'+1)*pow_p[i].ft % m1) % m1;
        h[i+1].sd = (h[i].sd + (s[i]-'a'+1)*pow_p[i].sd % m2) % m2;
    }
    int len = 0;
    fori(i,1,n) {
        auto x = mp((h[n].ft - h[n-i].ft + m1) % m1, (h[n].sd - h[n-i].sd + m2) % m2);
        auto y = mp((h[i].ft*pow_p[n-i].ft) % m1, (h[i].sd*pow_p[n-i].sd) % m2);
        if(x == y) len = i;
    }
    if(len == 0) { 
        cout << "Just a legend" << endl;
        return 0;
    }
    int ans = 0;
    fori(i,len,n) {
        auto x = mp((h[i].ft - h[i-len].ft + m1) % m1, (h[i].sd - h[i-len].sd + m2) % m2);
        auto y = mp((h[len].ft*pow_p[i-len].ft) % m1, (h[len].sd*pow_p[i-len].sd) % m2);
        if(x == y && i != len && i != n) {
            // cout << i << endl;
            ans = 1;
        }
    }
    if(ans) cout << s.substr(0, len) << endl;
    else cout << "Just a legend" << endl;
    return 0; 
}