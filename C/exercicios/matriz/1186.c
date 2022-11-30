#include <stdio.h>

int main() {
    float M[12][12];
    char op[5];
    int i, k;
    float calc = 0.0;

    scanf("%s", &op);

    for(i=0 ; i<12 ; i++) {
        for(k=0 ; k<12 ; k++) {
            scanf("%f", &M[i][k]);
        }
    }
    for(i=1 ; i<=11 ; i++) {
        for(k=11 ; k>11-i ; k--) {
            calc += M[i][k];
        }
    }
    if(op[0] == 'M') {
        calc = calc/66.0;
    }

    printf("%.1f\n", calc);
    return 0;
}