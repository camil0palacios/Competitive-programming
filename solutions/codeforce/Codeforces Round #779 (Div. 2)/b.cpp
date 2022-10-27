#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a, b) for (int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

// typedef __int128_t i128; // only for extreme cases
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int mod = 998244353;
const int Mxn = 1010;
ll f[Mxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f[0] = 1;
    fori(i, 1, Mxn) f[i] = (f[i - 1] * i) % mod;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n & 1)
            cout << 0 << endl;
        else
            cout << (f[n / 2] * f[n / 2]) % mod << endl;
    }
    return 0;
}