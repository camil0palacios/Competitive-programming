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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2e5 + 5;
int a[Mxn];
ll cnt[Mxn], p[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fore(i,1,n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    fori(i,1,Mxn) p[i] = p[i-1] + (cnt[i] ? i*cnt[i] : 0);
    int ans = 0;
    fori(i,1,Mxn) {
        int ev = cnt[i] / 2;
        ll x = p[i-1] + ev;
        ll y = p[Mxn-1] - p[i] + ev;
        if(x == y) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0; 
}