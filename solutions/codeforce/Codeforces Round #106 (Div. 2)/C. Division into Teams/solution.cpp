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
    int n;
    cin >> n;
    vii a(n);
    fori(i,0,n) {
        cin >> a[i].ft;
        a[i].sd = i+1;
    }
    sort(all(a), greater<ii>());
    int x = 0, y = 0;
    vector<int> a1, a2;
    fori(i,0,n) {
        if(abs((x + a[i].ft) - y) <= a[0].ft && sz(a1) + 1 <= n/2) x += a[i].ft, a1.eb(a[i].sd);
        else y += a[i].ft, a2.eb(a[i].sd);
    }
    cout << sz(a1) << endl;
    for(auto & i : a1) cout << i << ' '; cout << endl;
    cout << sz(a2) << endl;
    for(auto & i : a2) cout << i << ' '; cout << endl;
    return 0; 
}