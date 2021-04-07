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
    int a[6], x[6] = {1,5,10,20,50,100};
    fori(i,0,6) cin >> a[i];
    int mx = 0;
    fori(i,0,6) mx = max(mx, a[i]*x[i]);    
    int ans = 0, c = 1e6;
    fori(i,0,6) {
        if(a[i]*x[i] == mx && a[i] < c) {
            ans = i;
            c = a[i];
        }
    }
    cout << x[ans] << endl;
    return 0; 
}