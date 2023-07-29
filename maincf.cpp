#include<bits/stdc++.h>
using namespace std;

const int alphabet_size = 26;

struct Node {
	Node *links[alphabet_size];
	string meaning="";
	bool flag = false;
	
	bool ispresent(char ch){
		return (links[ch-'a']!=NULL);
	}
	void put(char ch,Node *node){
		links[ch-'a']=node;
	}
	Node* get(char ch){
		return links[ch-'a'];
	}
	void setend(){
		flag=true;
	}
	bool isend(){
		return flag;
	}
	void setmeaning(string def){
		meaning=def;
	}
	string getmeaning(){
		return meaning;
	}
};

class Trie {
	private:	Node *root;
	public:
		Trie(){
			root = new Node();
		}
		void insert(string word,string def){
			Node *node = root;
			for(auto &ch:word){
				if(!node->ispresent(ch)){
					node->put(ch,new Node());
				}
				node=node->get(ch);
			}
			node->setend();
			node->setmeaning(def);
		}
		string search(string word){
			Node *node = root;
			for(auto &ch:word){
				if(!node->ispresent(ch))	return "No word found\n";
				node=node->get(ch);
			}
			bool flag = node->isend();
			if(flag==0){
				return "No word found\n";
			}
			else{
				return node->getmeaning();
			}
		}
};

int main()
{
  auto start = chrono::high_resolution_clock::now();
	Trie trie;
	string line;
  vector<string> v = {
      
  };
	for(auto x:v){
    string line =x;
		int l=line.length();
		int flag=0;
      	string word,def;
      	for(int i=0;i<l;i++){
	        if(flag==0 && line[i]==' ')  {flag=1;continue;}
	        if(flag==0) word+=tolower(line[i]);
	        else def+=line[i];
     	 }
    trie.insert(word,def);
	}
  cout<<"Correctly Entered\n";
  int t=10;
  while(t--){
    string chk;cin>>chk;
    for(auto &ch:chk)	ch=tolower(ch);
    cout<<trie.search(chk)<<"\n";
  }
  cout<<"Output\n";

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  time_taken *= 1e-9; 
  cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
  cout << " sec" << endl;

}