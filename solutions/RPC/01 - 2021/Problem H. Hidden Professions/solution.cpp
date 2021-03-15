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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

struct Node {
    map<char, Node> m;
    int msk, cnt;
    void add(string & s, int idx, int id) {
        if(idx == sz(s)) msk |= (1 << id);
        else {
            m[s[idx]].add(s, idx + 1, id);
            msk |= m[s[idx]].msk;
        }
        cnt = __builtin_popcount(msk);
    }
    int find(string & s, int idx) {
        if(idx == sz(s)) return cnt == 1 ? msk : -1;
        else if(m.count(s[idx])) return m[s[idx]].find(s, idx + 1);
        return -1;
    }
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        Node root;
        int p, r;
        cin >> p >> r;
        fori(i,0,p) {
            int n; cin >> n;
            fori(j,0,n) {
                string t; cin >> t;
                root.add(t,0,i);
            }
        }
        fori(i,0,r) {
            int n; cin >> n;
            int msk = 0;
            fori(j,0,n) {
                string t; cin >> t;
                int par = root.find(t, 0);
                if(par != -1) msk |= par;
            }
            cout << __builtin_popcount(msk) << endl;
        }
        
    }
    return 0;
}