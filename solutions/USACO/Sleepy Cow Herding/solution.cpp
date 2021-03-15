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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vi a(3);
    fori(i,0,3) cin >> a[i];
    sort(all(a));
    if(a[0] + 2 == a[2]) cout << 0;
    else if(a[0] + 2 == a[1] || a[1] + 2 == a[2]) cout << 1;
    else cout << 2;
    cout << endl << max(a[1]-a[0], a[2]-a[1])-1 << endl; 
    return 0; 
}