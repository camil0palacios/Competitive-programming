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
typedef vector<ll> vl;

const int Mxn = 1e5 + 5;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    vi x({a[0]}), y;
    fori(i,1,n) {
        if(sz(x) && x.back() != a[i]) {
            if(i+1 < n && sz(y) && y.back() == a[i+1] && y.back() != a[i]) y.eb(a[i]);
            else x.eb(a[i]);
        }
        else if(y.empty() || (y.back() != a[i])) y.eb(a[i]);
    }
    cout << sz(x) + sz(y) << endl;
    return 0;
}