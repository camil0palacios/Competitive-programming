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
    ll p = 1;
    while(p <= n) p *= 10; 
    p /= 10;
    ll ans = 0;
    fore(i,1,9) {
        ll y = p*i;
        if(y > n) {
            ans = y - n;
            break;    
        }
    } 
    if(ans) cout << ans << endl;
    else cout << p*10 - n << endl;
    return 0; 
}