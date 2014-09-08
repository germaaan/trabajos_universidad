#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {
    pid_t pid_1, pid_2;
    int cauce_1[2], cauce_2[2], cauce_3[2], estado_1, estado_2, valor_1, valor_2, valor_3;
    char bufer[20];

    if (pipe(cauce_1) == -1) perror("cauce_1"), exit(1); /*creamos el cauce_1 */

    if (pipe(cauce_2) == -1) perror("cauce_2"), exit(2); /*creamos el cauce_2 */

    if (pipe(cauce_3) == -1) perror("cauce_2"), exit(3); /*creamos el cauce_3 */

    cout << "El padre debe leer un valor desde teclado: ";
    cin >> valor_1;

    sprintf(bufer, "%d", valor_1);
    write(cauce_1[1], bufer, sizeof (bufer));
    close(cauce_1[1]);

    switch (pid_1 = fork()) {
        case -1:
            perror("fork");
            exit(4);

        case 0:
            close(cauce_1[1]);

            read(cauce_1[0], bufer, 20);

            valor_2 = atoi(bufer) * 2;

            sprintf(bufer, "%d", valor_2);
            write(cauce_2[1], bufer, sizeof (bufer));
            close(cauce_2[1]);
            break;

        default:
            switch (pid_2 = fork()) {
                case -1:
                    perror("fork");
                    exit(5);

                case 0:
                    close(cauce_2[1]);

                    read(cauce_2[0], bufer, 20);

                    valor_3 = atoi(bufer) * 3;

                    sprintf(bufer, "%d", valor_3);
                    write(cauce_3[1], bufer, sizeof (bufer));
                    close(cauce_3[1]);
                    exit(0);
            }

            exit(0);
    }

    close(cauce_3[1]);

    read(cauce_3[0], bufer, 20);
    cout << "Padre: \"Mi segundo hijo ha escrito " << bufer << "\"" << endl;

    if (waitpid(pid_1, &estado_1, 0) == pid_1 && WIFEXITED(estado_1))
        if (waitpid(pid_2, &estado_2, 0) == pid_2 && WIFEXITED(estado_2))
            return WEXITSTATUS(estado_2);

    return 6;
}
