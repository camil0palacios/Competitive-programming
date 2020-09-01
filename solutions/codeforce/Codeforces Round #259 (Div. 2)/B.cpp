#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,occ=0,idx=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i < n ;i++)
        cin>>arr[i];
    for(int i=0; i < n-1 ; i++){
        if(arr[i] > arr[i+1]){
            occ++;
            idx=i+1;
        }
    }
    if(occ == 1){
        vector<int> v,s;
        for(int i=idx; i < n ; i++)
            v.push_back(arr[i]);
        for(int i=0; i < idx ; i++)
            v.push_back(arr[i]);
        s=v;
        sort(s.begin(),s.end());
        if(s==v)cout<< (n-idx);
        else cout<< -1;
    }
    else if(occ == 0) cout<<0;
    else cout<<-1;
}
