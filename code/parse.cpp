#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::isalpha;
using std::ofstream;
using std::string;
using std::vector;

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        cout << "error!" << endl;
        return 1;
    }
    ifstream fin;
    ofstream fout;
    puts(argv[1]);
    puts(argv[2]);
    bool flag = true;
    fin.open(argv[1]);
    fout.open(argv[2]);
    while (flag) {
        flag = false;
        string line, scope, name, settings;
        while (getline(fin, line)) {
            flag = true;
            cout << line << endl;
            if (*line.rbegin() == '{') {
                scope += '\"' + line.substr(0, line.length() - 2) + '\"';
                name += line.substr(0, line.length() - 2);
                break;
            } else {
                scope += '\"' + line.substr(0, line.length() - 1) + '\"' + ',';
                name += line;
            }
        }
        if (!flag) break;
        for (int i = 0; i < name.length(); ++i) {
            if (name[i] == '.')
                name[i] = ' ';
            else if (isalpha(name[i]) && (!i || !isalpha(name[i - 1])))
                name[i] = toupper(name[i]);
        }
        while (!fin.eof()) {
            string val1, val2;
            fin >> val1;
            if (val1 == "}") {
                getline(fin, val2);
                settings.erase(settings.end() - 1);
                break;
            } else {
                fin >> val2;
                settings += '\"' + val1.substr(0, val1.length() - 1) + '\"' +
                            ':' + '\"' + val2.substr(0, val2.length() - 1) +
                            '\"' + ',';
            }
        }
        fout << '{' << "\"name\":" << '\"' << name << '\"' << ',' << "\"scope\""
             << ':' << '[' << scope << ']' << ',' << "\"settings\"" << ':'
             << '{' << settings << '}' << '}' << ',';
    }
    return 0;
}
