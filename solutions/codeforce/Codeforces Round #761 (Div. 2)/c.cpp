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

const int Mxn = 2e5 + 5;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<int> s;
        fore(i,1,n) s.insert(i);
        vi res;
        fore(i,1,n) {
            cin >> a[i];
            if(s.find(a[i]) != s.end()) s.erase(a[i]);
            else res.eb(a[i]);
        }
        sort(all(res), greater<int>());
        bool ok = 1;
        int ans = 0;
        for(auto x : res) {
            int y = *s.rbegin();
            if((x-1)/2 < y) { ok = 0; break; }
            s.erase(y);
            ans++;
        }
        cout << (ok ? ans : -1) << endl;
    }
    return 0; 
}