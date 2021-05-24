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
    int n;
    cin >> n;
    vi ans;
    ll p = 1;
    fore(i,1,n-1) {
        if(__gcd(i, n) == 1) ans.eb(i), p = (p * i) % n;
    }
    if(p != 1) ans.pop_back();
    cout << sz(ans) << endl;
    for(auto & i : ans) cout << i << ' ';
    cout << endl;
    return 0; 
}