#include<bits/stdc++.h>
using namespace std;
//Dictionary Map
map<string,string> dictionary;

signed main()
{
  auto start = chrono::high_resolution_clock::now();
  //File Input
  std::ifstream inputFile("dict.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

	string line;
	while (std::getline(inputFile, line)){
		int l=line.length();
		int flag=0;
    string word,def;
    for(int i=0;i<l;i++){
      if(!flag && line[i]==' ')  {flag=1;continue;}
      if(!flag) word+=tolower(line[i]);
      else def+=line[i];
    }
		//Words stored in Map
    dictionary[word] = def;
	}
	//User Searching
  while(true){
		cout<<"Enter Words to search : ";
    string chk;cin>>chk;for(auto &ch:chk)	ch=tolower(ch);
    
    cout<<dictionary[chk]<<"\n";

		cout<<"Again ? y/n : ";char ch;cin>>ch;
		if(ch!='y' && ch!='Y')	break;
  }
	//Execution Time
  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  time_taken *= 1e-9; 
  cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
  cout << " sec" << endl;
}