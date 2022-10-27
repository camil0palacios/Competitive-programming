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
    string s;
    getline(cin, s);
    int ans = 0;
    stack<string> st;
    for(auto & c : s) {
        if(c == ' ') continue;
        if(c == '(') { st.push("("); continue; }
        int mx = 0;
        while(!st.empty() && st.top() != "(") {
            mx = max(mx, stoi(st.top()));
            st.pop();
        }
        st.pop();
        st.push(to_string(mx+1));
        ans += mx+1;
    }
    cout <<  ans << endl;
    return 0; 
}