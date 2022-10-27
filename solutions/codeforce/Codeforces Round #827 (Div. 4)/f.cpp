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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int q;
        cin >> q;
        bool still_a[2] = {1, 1};
        ll cnt_a[2] = {1, 1};
        fori(r,0,q) {
            int p, k; string x;
            cin >> p >> k >> x;
            p--;
            for(auto c : x) {
                still_a[p] &= c == 'a';
                cnt_a[p] += c == 'a' ? k : 0;
            }
            if(still_a[0] && still_a[1]) cout << (cnt_a[0] < cnt_a[1] ? "YES" : "NO") << endl;
            else if(!still_a[1]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0; 
}