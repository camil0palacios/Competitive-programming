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

const int  N = 2e5 + 5;
int a[N];

bool check(int l, int r) {
    set<int> s;
    fore(i,1,r-l+1) s.insert(i);
    fore(i,l,r) s.erase(a[i]);
    return s.empty();
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        set<ii> ans;
        set<int> s;
        fori(i,0,n) {
            if(s.count(a[i])) {
                if(check(0, i-1) && check(i, n-1)) ans.insert({i, n-i});
                break;
            }
            s.insert(a[i]);
        }
        s.clear();
        forr(i,n-1,0) {
            if(s.count(a[i])) {
                if(check(0, i) && check(i+1, n-1)) ans.insert({i+1, n-i-1});
                break;
            }
            s.insert(a[i]);
        }
        cout << sz(ans) << endl;
        for(auto p : ans) {
            cout << p.ft << ' ' << p.sd << endl;
        }
    }
    return 0; 
}