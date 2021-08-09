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

const int Mxn = 1010;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    int d = n - a[0];
    fori(i,0,n) {
        if(i & 1) a[i] = (a[i] - d + n) % n;
        else a[i] = (a[i] + d) % n;
    }
    bool ok = 1;
    fori(i,0,n) ok &= a[i] == i;
    cout << (ok ? "Yes" : "No") << endl;
    return 0; 
}