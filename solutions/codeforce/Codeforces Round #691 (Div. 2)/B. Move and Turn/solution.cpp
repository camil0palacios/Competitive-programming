#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
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
    int n;
    cin >> n;
    if(n % 2 == 0) {
        int p[n+1];
        p[2] = 4;
        for(int i = 4; i <= n; i += 2) p[i] = p[i-2] + i + 1;
        cout << p[n] << endl;    
    } else {
        int p[n+1];
        p[1] = 4;
        for(int i = 3, j = 2; i <= n; i += 2, j++) p[i] = p[i-2] + 4*j;
        cout << p[n] << endl;
    }
    return 0; 
}