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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    string s;
    cin >> n >> q >> s;
    int r = 0;
    fori(i,0,n-2) {
        r += s.substr(i, 3) == "abc";
    }
    fori(i,0,q) {
        int p; char c;
        cin >> p >> c;
        p--;
        int tmp = 0;
        if(s[p] == 'a' && p+2 < n && s.substr(p, 3) == "abc" && c != 'a') tmp--;
        if(s[p] == 'b' && p-1 >= 0 && p+1< n && s.substr(p-1, 3) == "abc" && c != 'b') tmp--;
        if(s[p] == 'c' && p-2 >= 0 && s.substr(p-2, 3) == "abc" && c != 'c') tmp--;
        if(c == 'a' && p+2 < n && s.substr(p+1, 2) == "bc" && s[p] != 'a') tmp++;
        if(c == 'b' && p-1 >= 0 && p+1 < n && s[p-1] == 'a' && s[p+1] == 'c' && s[p] != 'b') tmp++;
        if(c == 'c' && p-2 >= 0 && s.substr(p-2, 2) == "ab" && s[p] != c) tmp++;
        r += tmp;
        cout << r << endl;
        s[p] = c;
    
    }
    return 0;
}