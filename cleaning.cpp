#include<bits/stdc++.h>
using namespace std;
int main() {
    std::ifstream inputFile("cfdict.txt"); // Replace "example.txt" with your file path

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }
    std::ofstream outputFile; // Create an output file stream object

    // Open the file with a given filename
    outputFile.open("output.txt"); // Replace "output.txt" with your desired filename

    // Check if the file was opened successfully
    if (!outputFile.is_open()) {
        std::cout << "Error: Failed to open the file." << std::endl;
        return 1; // Exit the program with an error code
    }

    map<string,string> mp;
    map<string,int> cnt;
    std::string line;
    while (std::getline(inputFile, line)) {
      int l=line.length();
      string linec="";
      // int flag=0;
      // string word,def;
      // for(int i=0;i<l;i++){
      //   if(flag==0 && line[i]==' ')  flag=1;
      //   if(line[i]==',')  break;
      //   if(flag==0) word+=line[i];
      //   else def+=line[i];
      // }

      outputFile<<" \" "<<line<<"\" ,\n";
    }
    std::cout << "Text written to the file successfully." << std::endl;

    // Close the file
    outputFile.close();
    inputFile.close();
    return 0;
}
