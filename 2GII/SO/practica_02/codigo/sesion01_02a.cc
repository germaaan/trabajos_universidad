#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    char c = *argv[1];

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {

        for (int i = 0; i < 30; i++)
            cout << c << " ";
    } else {
        cout << "Error: se esperaba un carácter alfabético.";
    }

    cout << endl << flush;

    return 1;
}
