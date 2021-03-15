#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Sq = 4005;
bool sieve[Sq];
vi p;

void cal() {
    memset(sieve, -1, sizeof sieve);
    p.eb(2);
    for(int i = 3; i < Sq; i += 2) {
        if(sieve[i]) {
            p.eb(i);
            for(int j = i*i; j < Sq; j += i) {
                sieve[j] = 0;
            }
        }
    }
}

map<int,int> mp;

void prime_fact(int x) {
    for(int i = 0; i < sz(p) && p[i]*p[i] <= x; i++) {
        if(x % p[i] == 0) {
            mp[p[i]]++;
            while(x % p[i] == 0) x /= p[i];
        }
    }
    if(x > 1) mp[x]++;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int n, m;
    cin >> n;
    fori(i,0,n) {
        int x; cin >> x;
        prime_fact(x);
    }
    vll pr, f;
    pr.eb(0), f.eb(0);
    for(auto & i : mp) {
        pr.eb(i.ft), f.eb(i.sd);
    }
    fori(i,1,sz(f)) f[i] += f[i-1];
    cin >> m;
    fori(i,0,m) {
        int l, r;
        cin >> l >> r;
        l = lower_bound(all(pr), l) - pr.begin();
        if(l == sz(pr)) { 
            cout << 0 << endl;
            continue;
        } 
        int t = lower_bound(all(pr), r) - pr.begin();
        if(t == sz(pr)) t = sz(pr)-1;
        if(pr[t] > r) r = t - 1;
        else r = t;
        l = min(sz(f)-1, l);
        r = min(sz(f)-1, r);
        cout << f[r] - f[l-1] << endl;
    }
    return 0; 
}