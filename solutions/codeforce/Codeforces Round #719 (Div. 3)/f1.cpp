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

int query(int l, int r) {
    cout.flush();
    cout << "? " << l << ' ' << r << endl;
    int s;
    cin >> s;
    return s;
}

int main() { 
    int n, t, k;
    cin >> n >> t >> k;
    int l = 1, r = n, ans;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(mid - query(1,mid) >= k) r = mid;
        else l = mid+1;
    }
    cout << "! " << r << endl;
    return 0; 
}