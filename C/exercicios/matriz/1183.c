#include <stdio.h>

int main() {
    float M[12][12];
    int i, k;
    char operation[5];
    float sum = 0.0;

    scanf("%s", &operation);

    for(i=0 ; i<12 ; i++) {
        for(k=0 ; k<12 ; k++) {
            scanf("%f", &M[i][k]);
        }
    }

    for(i=0 ; i<12 ; i++) {
        for(k=i+1 ; k<12 ; k++) {
            sum += M[i][k];
        }
    }

    if(operation[0] == 'M') {
        sum = sum/66.0;
    }

    printf("%.1f\n", sum);

    return 0;
}