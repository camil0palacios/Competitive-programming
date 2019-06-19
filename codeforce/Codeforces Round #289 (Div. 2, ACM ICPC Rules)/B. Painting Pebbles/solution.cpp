#include <bits/stdc++.h>
using namespace std;

int a[101];
map<int,int> b[101];

int main(){
    int n, k;
    cin >> n >> k;
    int mmin = 1e9;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mmin = min(mmin, a[i]);
    }
    mmin++;
    bool flag = 1;
    for(int i = 0; i < n; i++){
        int val = min(mmin, a[i]);
        b[i][1] += val;
        if(val < a[i]){
            if(a[i] - val >= k){
                flag = 0;
                break;
            }
            int c = 2;
            for(int j = val; j < a[i]; j++){
                b[i][c]++;
                c++;
            }
        }
    }
    if(flag){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            for(int c = 1; c <= k; c++){
                for(int cnt = 0; cnt < b[i][c]; cnt++){
                    cout << c << " ";
                }
            }
            cout << endl;
        }
    }else{
        cout << "NO" << endl;
    }
    return 0;
}