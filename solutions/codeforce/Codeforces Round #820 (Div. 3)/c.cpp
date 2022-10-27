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

queue<int> pos[26];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = sz(s);
        fori(i,0,26) while(!pos[i].empty()) pos[i].pop();
        fori(i,1,n-1) pos[s[i]-'a'].push(i);
        int l = s[0]-'a', r = s[n-1]-'a';
        int rev = 0;
        if(l > r) swap(l, r), rev = 1;
        vi ans;
        ans.eb(1);
        fore(i,l,r) {
            while(!pos[i].empty()) {
                ans.eb(pos[i].front()+1);
                pos[i].pop();
            }
        }
        if(rev) reverse(ans.begin()+1, ans.end());
        ans.eb(n);
        cout << r-l << ' ' << sz(ans) << endl;
        for(auto & i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0; 
}