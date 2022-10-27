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

// typedef __int128_t i128; only for extreme cases
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int x, d;
int tot;

void rec(int x, int lst)
{
    if (x % d == 0 && (x % (d * d) != 0))
    {
        tot++;
        return;
    }
    for (int i = lst; i * i <= x; i++)
    {
        if (x % i == 0 && i % d == 0 && (i % (d * d) != 0))
            rec(x / i, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> x >> d;
        tot = 0;
        rec(x, d);
        if (tot >= 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}