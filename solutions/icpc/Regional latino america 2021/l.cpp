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

const int Mxn = 3e5 + 5;
int p[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    fori(i,0,n) { 
        int s, d;
        cin >> s >> d;
        fore(i,s,s+d) p[i] = 1;
    }
    forr(i,Mxn-x-1,0) p[i] += p[i+x];
    int T = 1e9, C = 1e9;
    fore(i,0,480) {
        if(p[i] < C) {
            T = i;
            C = p[i];
        }
    }
    cout << T << ' ' << C << endl;
    return 0; 
}