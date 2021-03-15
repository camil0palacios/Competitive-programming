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

bool is_palindrome(string & s) {
    string t = s;
    reverse(all(t));
    return s == t;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = sz(s);
    int i;
    for(i = 0; i < n/2; i++) {
        if(s[i] != s[n-i-1]) break; 
    }
    bool ok = 0;
    if(i == n/2) s.insert(s.begin()+i, s[i]), ok = 1;
    else {
        string t = s;
        if(i > 0) t.insert(t.begin()+i-1, s[n-i-1]);
        else t = string(1, s[n-i-1]) + s;
        if(is_palindrome(t)) s = t, ok = 1;
        t = s;
        t.insert(t.begin()+i, s[n-i-1]);
        if(!ok && is_palindrome(t)) s = t, ok = 1;
        t = s;
        t.insert(t.begin()+n-i, s[i]);
        if(!ok && is_palindrome(t)) s = t, ok = 1;
        t = s;
        t.insert(t.begin()+n-i-1, s[i]);
        if(!ok && is_palindrome(t)) s = t, ok = 1;
    }
    if(!ok) s = "NA";
    cout << s << endl;
    return 0; 
}