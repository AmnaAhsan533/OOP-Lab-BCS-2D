#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//ofstream creates a file if not exist and open it in write mode

int main(){
    string code;
    cout<<"Enter string: ";
    getline(cin, code);
    cout<<"Normal text: "<<code<<endl;
    ofstream outputFile("File.txt");
    if(!outputFile){
        cout<<"Error: File could not be created!"<<endl;
        return 1;
    }

    for(int i=0; i<code.size(); i++){
        code[i] += i+1;
    }

    outputFile<<code;
    cout<<"Encrypted text: "<<code<<endl;
    outputFile.close();

    ifstream inFile("File.txt");
    if(!inFile.is_open()){
        cout<<"Unable to open file!"<<endl;
        return 1;
    }
    while(getline(inFile, code)){
        for(int i=0; i<code.size(); i++){
            code[i] -= i+1;
        }
        cout<< "Decrypted text: "<< code <<endl;
    }
    inFile.close();

    return 0;
}
