#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = (int) s.size();
    int i;
    for(i = 0; i < n && s[i] == '1'; i++) {}
    if(i < n && s[i] == '0') {
        cout << s.substr(0,i) << s.substr(i+1) << endl;
    } else {
        cout << s.substr(0,n-1) << endl;
    }
    return 0; 
}