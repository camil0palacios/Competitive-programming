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

int a[10];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    cin >> k;
    fori(i,0,16) {
        char c; cin >> c;
        if(c != '.') a[c-'0']++;
    }
    bool ok = 1;
    fore(i,1,9) ok &= a[i] <= 2*k;
    cout << (ok ? "YES" : "NO") << endl;
    return 0; 
}