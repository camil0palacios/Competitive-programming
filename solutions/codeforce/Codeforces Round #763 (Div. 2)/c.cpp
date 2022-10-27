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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 2e5 + 5;
int n;
ll h[N], t[N];

bool check(int x) {
    fori(i,0,n) t[i] = h[i];
    forr(i,n-1,2) {
        if(t[i] < x) return 0;
        int d = min(h[i], t[i] - x) / 3;
        t[i-1] += d;
        t[i-2] += 2*d;
    }   
    return t[0] >= x && t[1] >= x;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fori(i,0,n) cin >> h[i];
        int l = 1, r = 1e9;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(check(m)) l = m+1;
            else r = m-1;
        }
        cout << l-1 << endl;
    }
    return 0; 
}