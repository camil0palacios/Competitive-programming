#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int oo = 1e9;
const int Mxn = 1e5 + 5;
int a[Mxn];
int l[Mxn], r[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    fore(i,1,n) cin >> a[i];
    fore(i,1,n) l[i] = 1 + (a[i] <= a[i-1] ? l[i-1] : 0);
    forr(i,n,1) r[i] = 1 + (a[i] <= a[i+1] ? r[i+1] : 0);
    while(q--) {
        int x, y;
        cin >> x >> y;
        if(r[x] + l[y] > y - x + 1) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }
    return 0; 
}