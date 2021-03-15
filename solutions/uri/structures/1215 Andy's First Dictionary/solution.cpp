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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    set<string> s;
    string t;
    while(getline(cin, t)) {
        string tmp;
        int n = sz(t);
        fori(i,0,n) {
            if(isalpha(t[i])) tmp += tolower(t[i]);
            else {
                if(sz(tmp)) s.insert(tmp);
                tmp = "";
            }
        }
        if(sz(tmp)) s.insert(tmp);
    }
    for(auto & t: s) {
        cout << t << endl;
    }
    return 0; 
}