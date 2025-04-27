#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace std;

const string BASE_LOG = "log.txt";
const size_t MAX_SIZE = 1 *1024 * 1024; //1MB = 1024 KB and 1KB = 10244 Bytes

string getNextFile(){
    int index = 1;
    string newFile;
    do{
        newFile = "log" + to_string(index++) +".txt";
    } while(fs::exists(newFile));
    return newFile;
}

void rotateLog(){
    if(fs::exists(BASE_LOG)){
        size_t fileSize = fs::file_size(BASE_LOG);
        if(fileSize >= MAX_SIZE){
            string newName = getNextFile();
            fs::rename(BASE_LOG, newName);
            cout<<"Log rotated to "<<newName<<endl;
        }
    }
}

void logMessage(const string& msg){
    rotateLog();
    ofstream logFile(BASE_LOG, ios::app);
    if(logFile.is_open()){
        logFile << msg <<endl;
    }
    logFile.close();
}

int main() {
    for (int i = 0; i < 50000; ++i) { // Many messages to trigger rotation
        logMessage("Logging message number: " + to_string(i));
    }

    cout << "Logging completed." << endl;
    return 0;
}
