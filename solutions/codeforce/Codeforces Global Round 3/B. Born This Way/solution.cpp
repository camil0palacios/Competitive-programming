#include <bits/stdc++.h>
using namespace std;

const int NM = 2e5 + 5;
int a[NM], b[NM];

int main(){
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int j = 0; j < m; j++){
        cin >> b[j];
    }
    if(k >= n || k >= m){
        cout << -1 << endl;
    }else{
        int mmax = 0;
        int j = 0;
        for(int i = 0; i < n && i <= k; i++){
            while(j < m && b[j] < a[i] + ta)j++;
            int res = k - i;
            if(j + res >= m){
                mmax = -1;
                break;
            }else{
                mmax = max(mmax, b[j + res] + tb);
            }
        }   
        cout << mmax << endl;
    }
    return 0;
}