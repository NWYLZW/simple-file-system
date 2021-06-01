#include <iostream>
#include <unistd.h>
#include "core/consoleColor.h"

using namespace std;

int main() {
    bool isRight = true;
    char hostname[1024];
    gethostname(hostname, 1024);

    string input;
    while (true) {
        cout << (isRight ? "" : RED) << "username@" << hostname << " > " << RESET;
        getline(cin, input);
        if (input == "exit") { break; }
        if (!input.empty()) {
            isRight = system(
                ("./bin/" + input).c_str()
            ) == 0;
        }
    }
    return 0;
}
