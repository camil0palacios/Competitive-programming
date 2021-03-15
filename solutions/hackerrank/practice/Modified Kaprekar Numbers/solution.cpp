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

bool Kaprekar(int x) {
    string s = to_string(1ll*x*x);
    int n = sz(s);
    ll a = 0, b = 0;
    fori(i,0,n/2) a = a*10 + (s[i]-'0');
    fori(i,n/2,n) b = b*10 + (s[i]-'0');
    return a + b == x;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int p, q;
    cin >> p >> q;
    bool ok = 0;
    fore(i,p,q) {
        if(Kaprekar(i)) {
            cout << i << ' ';
            ok = 1;
        }
    }
    if(!ok) cout << "INVALID RANGE";
    cout << endl;
    return 0; 
}