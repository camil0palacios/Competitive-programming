#include <bits/stdc++.h>
using namespace std;

class Stack{
	private:
		int id;
		int num;
		int size;
	public:
		void set_id(int id1){id=id1;}
		void set_num(int num1){num=num1;}
		void set_size(int size1){size=size1;}
		int get_id()const{return id;}
		int get_num()const{return num;}
		int get_size()const{return size;}
};


int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<Stack> stacks;
    Stack s;
    s.set_id(0);s.set_num(-1);s.set_size(0);
    stacks.push_back(s);
    int n;
    cin>>n;
    while(n--){
    	int id,op,num;
    	cin>>id>>op;
    	if(op==0){
    		cin>>num;
    		int newsize = stacks[id].get_size();
    		Stack a;
    		a.set_id(id);a.set_num(num);a.set_size(newsize+1);
    		stacks.push_back(a);
    		cout<<newsize+1<<endl;
    	}	
    	if(op==1){
    		int newid;
    		int newnum;
    		int newsize;
    		if(stacks[id].get_size()-1 < 0){
    			cout<<-1<<endl;
    			newid = 0;
    			newnum  = -1;
    			newsize = 0;
    		}
    		else if(stacks[id].get_size()-1 == 0){
    			cout<<stacks[id].get_num()<<endl;
    			newid = 0;
    			newnum  = -1;
    			newsize = 0;
    		}
    		else if(stacks[id].get_size()-1 > 0){
    			cout<<stacks[id].get_num()<<endl;
    			int midid = stacks[id].get_id();
    			newid = stacks[midid].get_id();
    			newnum  = stacks[midid].get_num();
    			newsize = stacks[midid].get_size();
    		}
    		Stack a;
    		a.set_id(newid);a.set_num(newnum);a.set_size(newsize);
    		stacks.push_back(a);
    	}
    }
	return 0;
}