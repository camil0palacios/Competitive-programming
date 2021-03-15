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

const int oo = 1e9;
const int Mxn = 2e5 + 5;
vi pos[26];
int Left[Mxn], Right[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    string s, t;
    cin >> n >> m;
    cin >> s >> t;
    int j = 0;
    fori(i,0,n) if(j < m && s[i] == t[j]) Left[j++] = i;
    j = m-1;
    forr(i,n-1,0) if(j >= 0 && s[i] == t[j]) Right[j--] = i;
    int ans = 0;
    fori(i,0,m-1) ans = max(ans, Right[i+1] - Left[i]);
    cout << ans << endl;
    return 0; 
}