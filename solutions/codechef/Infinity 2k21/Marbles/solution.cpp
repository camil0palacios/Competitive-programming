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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

bool is_vowel(char c) {
    int t[5] = {'a', 'e', 'i', 'o', 'u'};
    bool ok = 0;
    fori(i,0,5) ok |= c == t[i];
    return ok;
} 

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s, p;
        cin >> n >> s >> p;
        int ans = 1e9;
        fori(c,0,26) {
            char x = char(c + 'a');
            string st = s, pt = p;
            fori(i,0,n) {
                if(st[i] == '?') st[i] = x;
                if(pt[i] == '?') pt[i] = x;
            }
            int tmp = 0;
            fori(i,0,n) {
                if(st[i] == pt[i]) continue;
                tmp += (is_vowel(st[i]) == is_vowel(pt[i]) ? 2 : 1);
            }
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0; 
}