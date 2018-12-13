#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& v, int l, int r){
    if(l >= r)return;
    int i = l, j = r, piv = v[(l + r)/2];
    while(i < j){
        
        getchar();
        while(v[i] < piv){
            i++;
        }
        while(v[j] > piv){
            j--;
        }
        if(i <= j){
            swap(v[i],v[j]);
            i++; j--;
        }
        
    }
    if(l < j)quick_sort(v,l,j);
    if(r > i)quick_sort(v,i,r);
    
}

int main(){

    vector<int> v = {8, 1, 7, 4 , 5, 2, 3};
    quick_sort(v,0,v.size()-1);
    for(auto i: v)cout << i << " ";
    cout << endl;
    return 0;
}