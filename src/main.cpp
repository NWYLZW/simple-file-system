#include <iostream>

using namespace std;

int main() {
    string input;
    while (true) {
        cout << "username@host-name >> ";
        getline(cin, input);
        cout << input << endl;
        if (input == "exit") { break; }
    }
    return 0;
}
