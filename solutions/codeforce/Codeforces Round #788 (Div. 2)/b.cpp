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

const int K = 26;
int a[K];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> s >> k;
        fori(i,0,K) a[i] = 0;
        fori(i,0,k) {
            char c; cin >> c;
            a[c-'a'] = 1;
        }
        int ans = 0;
        stack<int> st;
        fori(i,0,n) {
            if(a[s[i]-'a']) {
                ans = max(ans, sz(st));
                while(!st.empty()) st.pop();
            }
            st.push(s[i]);
        } 
        cout << ans << endl;
    }
    return 0; 
}