#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {

    int i = atoi(argv[1]);

    if (i > 0 && i <= 9) {

        for (int j = 0; j < 30; j++)
            cout << i << " ";
    } else {
        cout << "Error: se esperaba un valor numérico.";
    }

    cout << endl << flush;

    return 2;
}
