#include <bits/stdc++.h>
using namespace std;

int operator<(pair<int,int>& a, pair<int,int>& b){
    return a.first < b.first;
}

int main(){
    int n,t,a,cont=0,cupo=0;
    vector<pair<int,int>> s;
    vector<int> aux;
    scanf("%d %d",&n,&t);
    for(int i=0; i < n ; i++){
        cin>>a;
        s.push_back({a,i});
    }
    sort(s.begin(),s.end());
    for(int i=0; i < s.size() ; i++){
        if(cupo+s[i].first <= t){
            cupo+=s[i].first;
            cont++;
            aux.push_back(s[i].second+1);
        }
    }
    sort(aux.begin(),aux.end());
    cout<<cont<<"\n";
    for(int i=0; i < aux.size() ; i++){
        cout<<aux[i]<<" ";
    }
}
