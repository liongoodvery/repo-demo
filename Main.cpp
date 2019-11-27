#include<fstream>
#include<iostream>
#include <sstream>

int main(int argc, char *argv[]) {
    using namespace std;
    if (argc <= 1) {
        cerr << "config file missing" << endl;
        return 1;
    }
    string configFile = argv[1];

    ifstream in(configFile);
    if (!in) {
        cout << configFile << " not readable" << endl;
        return 1;
    }

    string logFile;
    string dataFile;

    string line;
    while (getline(in, line)) {
        istringstream ins(line);
        string key;
        string value;
        ins >> key >> value;
        if (key == "log") {
            logFile = value;
        }

        if (key == "data") {
            dataFile = value;
        }
    }
    in.close();

    if (logFile == "") {
        cerr << "log file is empty" << endl;
        return 1;
    }
    if (dataFile == "") {
        cerr << "data file is empty" << endl;
        return 1;
    }
    ofstream out;
    out.open(logFile, ios_base::app);
    if (out) {
        out << "this a log file" << endl;
    } else {
        cerr << logFile << "logFile not writeable !" << endl;
    }
    out.close();

    out.open(dataFile, ios_base::app);
    if (out) {
        out << "this a data file" << endl;
    } else {
        cerr << logFile << "dataFile not writeable !" << endl;
    }
    out.close();

    return 0;
}
