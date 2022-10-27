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

int lis(vi & a) {
    vi v;
    fori(i,0,sz(a)) {
        int j = upper_bound(all(v), a[i]) - v.begin();
        if(j >= sz(v)) v.eb(a[i]);
        else v[j] = a[i];
    }
    return sz(v);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n) {
        vi a(n), b(n);
        fori(i,0,n) cin >> a[i], b[i] = a[i];
        reverse(all(b));
        int x = lis(a), y = lis(b);
        cout << (x == y ? "Caution. I will not intervene." : "Don't worry. I must intervene.") << endl;
    }
    return 0; 
}