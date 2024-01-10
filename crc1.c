#include <stdio.h>

int main() {
    char msg[10];
    int N;
    int k, i;
    char enmsg[10];

    printf("Enter the number of message chars: ");
    scanf("%d", &N);

    printf("Enter the key element: ");
    scanf("%d", &k);

    printf("Enter the message data:\n");
    for (i = 0; i < N; i++) {
        scanf(" %c", &msg[i]);
    }

    printf("Encrypted msg:\n");
    for (i = 0; i < N; i++) {
        printf("%c", msg[i] + k);
    }
    printf("\n");

    printf("Type the  encrypinput msg:\n");
    for (i = 0; i < N; i++) {
        char ch;
        scanf(" %c", &ch);
        enmsg[i] = ch;
    }

    printf("Decrypted msg:\n");
    for (i = 0; i < N; i++) {
        printf("%c", enmsg[i] - k);
    }
    printf("\n");

    return 0;
}
