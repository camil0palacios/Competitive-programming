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
int a[N];
int b[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) cin >> b[i];
        int mx = 0;
        set<int> s;
        fori(i,0,n) {
            if(!b[i]) mx = max(mx, a[i]);
            else s.insert(a[i]-b[i]);
        }
        if(sz(s) == 0) cout << "YES" << endl;
        else if(sz(s) == 1 && *s.begin() >= 0 && mx <= *s.begin()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0; 
}