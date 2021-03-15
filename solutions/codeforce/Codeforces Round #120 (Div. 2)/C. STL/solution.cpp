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

int t;
string s, ans;

void f() {
    if(cin >> s) {
        ans += s;
        if(s == "pair") {
            ans += "<";
            f();
            ans += ",";
            f();
            ans += ">";
        }
    } else t = 1;
}

int main() { 
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    f();
    if(t || cin >> s) cout << "Error occurred" << endl;
    else cout << ans.c_str() << endl;
    return 0; 
}