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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;


const int Mxn = 1e5 + 5;
int n;
int a[Mxn], tmp[Mxn];
ll inv;

void merge(int l, int r, int m) {
    int i = l, j = m+1, k = l;
    while(i <= m && j <= r) {
        if(a[i] <= a[j]) tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j], j++;
            inv += (m+1) - i;
        }
    }
    while(i <= m) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int i = l; i <= r; i++) a[i] = tmp[i];
}

void mergesort(int l, int r) {
    if(l == r) return;
    int m = (l + r) >> 1;
    mergesort(l, m);
    mergesort(m+1, r);
    merge(l, r, m);
}

int bit[Mxn];

void add(int i, int val) {
    while(i < Mxn) {
        bit[i] += val;
        i += i & -i;
    }
}

int sum(int i) {
    int ans = 0;
    while(i) {
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}

int query(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n, n) {
        fori(i,0,n) cin >> a[i];
        fore(i,1,n) bit[i] = 0; 
        inv = 0;
        // mergesort(0,n-1);
        forr(i,n-1,0) {
            inv += query(1, a[i]);
            add(a[i], 1);
        }
        cout << (inv & 1 ? "Marcelo" : "Carlos") << endl;
    }
    return 0; 
}