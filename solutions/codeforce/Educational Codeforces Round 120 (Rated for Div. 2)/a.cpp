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

bool check(int a, int b, int c, int d) {
    return a == c && b == d;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int l[3];
        fori(i,0,3) cin >> l[i];
        int p[3] = {0, 1, 2};
        bool ok = 0;
        do {
            int x[3];
            fori(i,0,3) x[i] = l[p[i]];
            int a = x[1], b = x[0]-x[1];
            int c = x[2], d = x[0]-b;
            if(check(a,b,c,d) || check(a,b,d,c)) { ok = 1; break; }
            if(x[0] % 2 == 0 && x[1] == x[2]) { ok = 1; break; }
        } while(next_permutation(p, p+3));
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}