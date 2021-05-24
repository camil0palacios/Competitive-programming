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

const int Mxn = 2e5 + 5;
int a[Mxn];
pair<ll,int> s[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    fori(i,0,n) cin >> a[i];
    ll acc = 0;
    fori(i,0,k) acc += a[n-i-1];
    s[n-k] = mp(acc, n-k);
    forr(i,n-k-1,0) {
        acc -= a[i+k];
        acc += a[i];
        if(acc < s[i+1].ft) s[i] = s[i+1];
        else s[i] = mp(acc, i);
    }
    acc = 0;
    fori(i,0,k) acc += a[i];
    ii ans = {0, s[k].sd};
    ll mx = acc + s[k].ft;
    fori(i,k,n) {
        acc -= a[i-k]; 
        acc += a[i];
        if(mx < acc + s[i+1].ft) {
            mx = acc + s[i+1].ft;
            ans = mp(i-k+1, s[i+1].sd);
        }
    }
    cout << ans.ft+1 << ' ' << ans.sd+1 << endl;
    return 0;
}