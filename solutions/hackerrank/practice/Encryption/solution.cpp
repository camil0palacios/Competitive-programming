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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    getline(cin, s);
    int l = sz(s);
    int n = sqrt(l), m = n;
    if(n*m < l) m++;
    if(n*m < l) n++;
    char a[n][m];
    fori(i,0,n) fori(j,0,m) a[i][j] = ' ';
    int x = 0;
    fori(i,0,n) {
        fori(j,0,m) {
            if(x < l) a[i][j] = s[x++];
        }
    }
    fori(j,0,m) {
        fori(i,0,n) if(a[i][j] != ' ') cout << a[i][j];
        cout << ' ';
    }
    return 0; 
}