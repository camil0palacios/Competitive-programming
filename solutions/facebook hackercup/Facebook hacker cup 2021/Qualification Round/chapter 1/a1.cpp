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

int p[26];

bool is_vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'; 
}

int solve() {
    string s;
    cin >> s;
    int n = sz(s);
    fori(i,0,26) p[i] = 0;
    fori(i,0,n) p[s[i]-'A']++;
    int ans = 1e9;
    fori(i,0,26) {
        int v = 0, c = 0;
        fori(j,0,26) { 
            if(is_vowel(char(j + 'A'))) v += p[j];
            else c += p[j];
        }
        if(is_vowel(char(i + 'A'))) {
            v -= p[i];
            ans = min(ans, v*2 + c);
        } else {
            c -= p[i];
            ans = min(ans, v + 2*c);
        }
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0; 
}