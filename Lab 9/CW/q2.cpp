#include<iostream>
#include<vector>
#include<ctime>
#include<cstring>
using namespace std;

string currenttime(){
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt) - 1] = '\0';
    return string(dt);
}

class Logger{
private:
    const size_t MAX_LOGS = 1000;
    vector<string> logs;

    void addLog(const string& severity, const string& module, const string& mes){
        string formatted = "[" + currenttime() + "] [" + severity + "] [" + module + "] " + mes;
        if(logs.size() >= MAX_LOGS){
            logs.erase(logs.begin());
        }
        logs.push_back(formatted);
    }
public:
    void logInfo(const string& module, const string& message) {
        addLog("INFO", module, message);
    }

    void logWarning(const string& module, const string& message) {
        addLog("WARNING", module, message);
    }

    void logError(const string& module, const string& message) {
        addLog("ERROR", module, message);
    }
    friend class Auditor;
};

class Auditor{
private:
    bool isAuthenticate;
public:
    Auditor(): isAuthenticate(false) {}
    void authenticate(const string& password){
        if(password == "audit123") {
            isAuthenticate = true;
            cout<<"Auditor authentication successful.\n";
        } else cout<<"Auditr access denied.\n";
    }
    vector<string> retrieveLogs(const Logger& logger) const {
        if(!isAuthenticate){
            cout<<"Auditor not  authenticated. Cannot retrieve logs.\n";
            return {};
        }
        return logger.logs;
    }
};

int main() {
    Logger logger;

    // Simulate different modules logging
    logger.logInfo("Network", "Connection established");
    logger.logWarning("Database", "Query took too long");
    logger.logError("UI", "Button failed to render");

    // Auditor access
    Auditor auditor;

    // Attempt without authentication
    auto logs = auditor.retrieveLogs(logger); // should print error

    // Authenticate
    auditor.authenticate("audit123");

    // Retrieve and display logs
    logs = auditor.retrieveLogs(logger);
    cout << "\n--- Retrieved Logs ---\n";
    for (const auto& log : logs) {
        cout << log << endl;
    }

    return 0;
}
