#include<stdio.h>

void upperString(char s1[], char s2[]) {
    int i = 0;
    while(s1[i] != '\0') {
        s2[i] = toupper(s1[i]);
        i++;
    }
    s2[i] = '\0';
}

int main() {
    char input[] = "hello world";
    char output[50];

    upperString(input, output);

    printf("%s", output);

    return 0;
}