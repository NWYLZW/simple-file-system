#include <iostream>
#include <unistd.h>

#include "core/users.h"
#include "core/consoleColor.h"

using namespace std;

const char * curUsername() {
    string* username = getU();
    return username != nullptr ? username->c_str() : "?";
}

int main() {
    bool isRight = true;
    char hostname[1024];
    gethostname(hostname, 1024);

    string input;
    while (true) {
        cout << (isRight ? "" : RED) << curUsername() << "@[" << hostname << "]> " << RESET;
        getline(cin, input);
        if (input == "exit") {
            cout << "See you~" << endl;
            break;
        }
        if (!input.empty()) {
            isRight = system(
                ("./bin/" + input).c_str()
            ) == 0;
        } else {
            isRight = true;
        }
    }
    return 0;
}
