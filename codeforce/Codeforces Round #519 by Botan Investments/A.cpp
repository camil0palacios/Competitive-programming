#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0, mmax = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
        mmax = max(mmax, v[i]);
    }
    int k = 1;
    while(true){
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += k - v[i];
        }
        if(ans > sum && k >= mmax)break;
        k++;
    }
    cout << k << endl;
    return 0;
}