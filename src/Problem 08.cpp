#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidPart(const string& s) {
    // A part is valid if it's not empty and its value is between 0 and 255
    if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) // Leading zeros are not allowed
        return false;
    int num = stoi(s);
    return num >= 0 && num <= 255;
}

void generateIPAddresses(const string& s, int start, int parts, string ip, vector<string>& result) {
    // Base case: If we have used all parts and reached the end of the string
    if (start == s.size() && parts == 4) {
        ip.pop_back(); // Remove the extra '.' at the end
        result.push_back(ip);
        return;
    }

    // If we have used all parts but not reached the end of the string
    if (parts == 4 || start == s.size())
        return;

    string part;
    for (int i = start; i < s.size(); i++) {
        part += s[i];
        if (isValidPart(part)) {
            generateIPAddresses(s, i + 1, parts + 1, ip + part + '.', result);
        }
        else {
            break; // Stop if the current part is not valid
        }
    }
}

vector<string> genIp(string s) {
    vector<string> result;
    generateIPAddresses(s, 0, 0, "", result);
    return result.empty() ? vector<string>(1, "-1") : result;
}

int main() {
    // Example usage
    string s1 = "1111";
    vector<string> result1 = genIp(s1);
    for (const string& ip : result1) {
        cout << ip << " ";
    }
    cout << endl;

    string s2 = "55";
    vector<string> result2 = genIp(s2);
    for (const string& ip : result2) {
        cout << ip << " ";
    }
    cout << endl;

    return 0;
}
