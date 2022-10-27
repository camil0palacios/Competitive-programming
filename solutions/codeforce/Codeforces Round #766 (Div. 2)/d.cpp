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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e6;
int a[Mxn];
int b_gcd[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    int cnt = 0;
    fore(i,1,Mxn) {
        for(int j = i; j <= Mxn; j += i) {
            if(a[j]) b_gcd[i] = __gcd(b_gcd[i], j);
        }
        cnt += b_gcd[i] == i;
    }
    cout << cnt - n << endl;
    return 0; 
}