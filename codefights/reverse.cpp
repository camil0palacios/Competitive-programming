#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void print(string str){
	for(int i=0; i < str.size(); i++)
		cout<<str[i]<<" ";
	cout<<endl;
}

std::string reverseParentheses(std::string s) {
    
    for(int f, l; (f = s.rfind(40, l = s.find(41))) > s.size();
        reverse( & s[f], & s[l] ),
        s.erase( l-1, 2 )
    ){
    	system("pause");
        print(s);
	}
    return s;
}
/*
std::string reverseParentheses(std::string s) {
	for(int i=0 ; i< s.size(); i++){
	//	print(s);
		if( s[i] == '('){
			s.erase(s.begin()+i);
		//	print(s);
			int aux=1,b=i; 
			while(aux!=0){
			//	system("pause");
			//	cout<<s[b]<<endl;
				if(s[b]=='('){
					aux++;
					s[b]=')';
					b++;
				}
				if(s[b]==')'){
					aux--;
					if(aux == 0)
						break;
					s[b]='(';
					b++;
				}
				//cout<<"aux: "<<aux<<endl;
				if(s[b] != '(' || s[b] != ')')
					b++;
				//print(s);
			}
			s.erase(s.begin()+b);
			std::reverse(s.begin()+i,s.begin()+b);
			//print(s);
		}	
	} 
	return s;
} */

int main(){
	
	string str="abc(cba)ab(bac)c";
	print(reverseParentheses(str));
}
