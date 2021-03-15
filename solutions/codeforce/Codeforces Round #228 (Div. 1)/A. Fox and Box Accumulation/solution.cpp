#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

const int MXN = 202;
int a[MXN];
bool vis[MXN];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i, 0, n) cin >> a[i];
    sort(a, a + n);
    int k = 0;
    fori(i, 0, n) {
        if(k * (a[i] + 1) <= i) k++;
    }
    cout << k << endl;
    return 0; 
}