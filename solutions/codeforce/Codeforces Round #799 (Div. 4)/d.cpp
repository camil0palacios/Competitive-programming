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

string newHour(int h, int m) {
    string s;
    if(h < 10) s += "0";
    s += to_string(h);
    s += ":";
    if(m < 10) s += "0";
    s += to_string(m);
    return s;
}

bool isPalindrome(string & s) {
    fori(i,0,5) {
        if(s[i] != s[5-i-1]) return 0;
    }
    return 1;
} 

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        int x;
        cin >> s >> x;
        set<string> vis;
        int ans = 0;
        while(!vis.count(s)) {
            if(isPalindrome(s)) ans++;
            vis.insert(s);
            int h = stoi(s.substr(0, 2));
            int m = stoi(s.substr(3, 2));
            h = (h + (m + x) / 60) % 24;
            m = (m + x) % 60;
            s = newHour(h, m);
        }
        cout << ans << endl;
    }
    return 0; 
}