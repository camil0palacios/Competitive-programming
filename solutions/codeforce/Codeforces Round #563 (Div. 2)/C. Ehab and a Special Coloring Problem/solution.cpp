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

const int Mxn = 1e5 + 5;
int c[Mxn], col = 1;

int is_prime(int x) {
    if(x == 2) return -1;
    if(x % 2 == 0) return 2;
    for(int i = 3; i*i <= x; i += 2)
        if(x % i == 0) return i;
    return -1;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fore(i,2,n) {
        int r = is_prime(i);
        if(r == -1) c[i] = col++;
        else c[i] = c[r];
    }
    fore(i,2,n) cout << c[i] << ' ';
    cout << endl; 
    return 0;
}