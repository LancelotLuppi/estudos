#include <stdio.h>

void intToString(int in, char out[]) {
    out = (char) in;
}

int main() {
    int input = 50;
    char output[5];

    intToString(input, output);

    printf("%s", output);
    return 0;
}