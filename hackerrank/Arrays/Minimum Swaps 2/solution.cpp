#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1e5 + 5;
int tmp[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    pair<int,int> a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i; 
    }
    sort(a, a + n);
    vector<bool> vis(n, 0);
    int swaps = 0;
    for(int i = 0; i < n; i++){
        if(vis[i] || a[i].second == i)continue;
        int ans = 0;
        int j = i;
        while(!vis[j]){
            vis[j] = 1;
            j = a[j].second;
            ans++;
        }
        if(ans)swaps += (ans - 1);
    }
    cout << swaps << endl;
    return 0;
}

/*
5
2 3 4 1 5
0 1 2 3 4

0 1 2 3 4
1 2 3 4 5
3 0 1 2 4

*/