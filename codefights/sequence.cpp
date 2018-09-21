#include<iostream>
#include<vector>


void print(std::vector<int> v){
	for(int i=0; i<v.size();i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
}

bool almostIncreasingSequence(std::vector<int> sequence) {
    std::vector<int> seq1,seq2;
    for(int i=0; i < sequence.size()-1 ; i++){
        if(sequence[i]<sequence[i+1]){
            if(seq1.size()==0 && seq2.size()== 0){
                seq1.push_back(sequence[i]);
                seq2.push_back(sequence[i]);
                print(seq1);
                print(seq2);
            }
            else{ 
                if(i == sequence.size()-2){
                	//std::cout<<"hola hptas";
                	if(seq1.back()<sequence[i])
	                    seq1.push_back(sequence[i]);
	                if(seq1.back()<sequence[i+1])
	                    	seq1.push_back(sequence[i+1]);
                    if(seq2.back()<sequence[i])
                        seq2.push_back(sequence[i]);
                    if(seq2.back()<sequence[i+1])
	                    seq2.push_back(sequence[i+1]);
                    print(seq1);
                	print(seq2);
                }
                if(seq1.back()<sequence[i])
                    seq1.push_back(sequence[i]);
                if(seq2.back()<sequence[i])
                    seq2.push_back(sequence[i]);
                print(seq1);
                print(seq2);
            }
        }
        else{
            if(seq2.size()== 0){
                seq1.push_back(sequence[i]);
                seq2.push_back(sequence[i+1]);
                print(seq1);
                print(seq2);
            }
            else{
                if(seq1.back()<sequence[i])
                    seq1.push_back(sequence[i]);
                if(seq2.back()<sequence[i+1])
                    seq2.push_back(sequence[i+1]);
                else
                    if(seq2.back()<sequence[i])
                        seq2.push_back(sequence[i]);
                print(seq1);
                print(seq2);
            }
        }
    }
    if(seq1.size() == sequence.size()||seq1.size() == sequence.size()-1) 
        return true;
    if(seq2.size() == sequence.size()||seq2.size() == sequence.size()-1) 
        return true;
    return false;
}


int main(){
	int m[] = {1,2,1,2};
	std::vector<int> v(m,m+4);
	std::cout<<almostIncreasingSequence(v);
}
