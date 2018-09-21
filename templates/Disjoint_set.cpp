#include <bits/stdc++.h>
using namespace std;

class Disjoint_set{
    private:
        unordered_map<int,int> p;
        unordered_map<int,int> rank;
    public:
        Disjoint_set(): p(),rank(){}
        void make_set(int d){
            for(int i=1; i<=d ; i++){
                p.insert({i,i});
                rank.insert({i,0});
            }
        }
        int Find_set(int i){
            if(p[i]==i)return i;
            else p[i]=Find_set(p[i]);
        }
        void Union_set(int a, int b){
            int x = Find_set(a), y = Find_set(b);
            if(x == y){
                return;
            }
            else{
                if(rank[x] > rank[y]) p[y]=x;
                else{
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};

int main(){

    Disjoint_set s;
    s.make_set(10);
    s.Union_set(1,2);
    s.Union_set(3,4);
    s.Union_set(5,4);
    s.Union_set(7,8);
    s.Union_set(1,8);
    int x= s.Find_set(3), y= s.Find_set(5);
    cout<< x<<","<< y<<endl;

    return 0;
}
