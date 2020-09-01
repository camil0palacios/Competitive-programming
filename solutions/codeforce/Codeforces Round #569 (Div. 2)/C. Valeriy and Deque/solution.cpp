#include <bits/stdc++.h>
using namespace std;

pair<int,int> ans[100005];
int a[100005];

int main(){
    int n, q;
    cin >> n >> q;
    int mmax = 0, j = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(mmax < a[i]){
            mmax = a[i];
            j = i;
        }
    }
    vector<int> b;
    for(int i = j; i < n; i++){
        b.emplace_back(a[i]);
    }
    int xmax = a[0], idx = 0;
    for(int i = 1; i < j; i++){
        int ot = a[i];
        if(xmax < ot){
            swap(xmax, ot);
            idx = i;
        }
        ans[i].first = (idx < i ? xmax : ot);
        ans[i].second = (ans[i].first == xmax ? ot : xmax);
        b.emplace_back(ot);
    }
    ans[j].first = xmax;
    ans[j].second = mmax;
    b.emplace_back(xmax);/*
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    cout << endl;*/
    for(int i = 0; i < q; i++){
        long long x;
        cin >> x;
        if(x <= j)cout << ans[x].first << " " << ans[x].second << endl;
        else cout << mmax << " " << b[((x-(j+1))%(n-1))+1] << endl;
    }
}