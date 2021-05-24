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
const int Mxa = 5010;
int a[Mxn], p[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    fori(i,0,n) {
        cin >> a[i];
        p[a[i]]++;
    }
    fore(i,1,Mxa-1) p[i] += p[i-1];
    int mx = 0;
    fore(i,1,Mxa) 
        fore(j,i,min(i*2, Mxa-1))
            mx = max(mx, p[j] - p[i-1]);
    cout << n - mx << endl;    
    return 0; 
}