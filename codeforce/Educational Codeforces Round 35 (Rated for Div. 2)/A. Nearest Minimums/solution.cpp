#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    int x = a[0], y = a[1];
    vector<int> dist;
    for(int i = 0; i < n; i++){
        if(b[i] == x || b[i] == y){
            dist.push_back(i);
        }
    }
    int mmin = 1e9;
    for(int i = 0; i < dist.size() - 1; i++){
        mmin = min(mmin, dist[i+1] - dist[i]);
    }
    cout << mmin << endl;
    return 0;
}