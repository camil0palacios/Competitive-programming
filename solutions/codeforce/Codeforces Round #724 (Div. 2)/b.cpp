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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<string> st;
    fori(i,0,n) {
        string t;
        fori(j,i,n) {
            t += s[j];
            st.insert(t);
        }
    }
    fore(len,1,6) {
        string t = string(len, 'a');
        while(1) {
            if(!st.count(t)) {
                cout << t << endl;
                return; 
            }
            int idx = sz(t)-1;
            while(idx >= 0 && t[idx] == 'z') t[idx] = 'a', idx--;
            if(idx < 0) break;
            t[idx]++;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}