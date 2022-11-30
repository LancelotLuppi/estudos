#include <stdio.h>

double calculate_column_sum(double matriz[12][12], int column) {
    double sum;
    int i;
    for(i=0 ; i<12 ; i++) {
        sum += matriz[i][column];
    }
    return sum;
}

int main() {
    double matriz[12][12];
    int column;
    int i, k;
    char operation[5];
    double sum = 0.0;

    scanf("%d", &column);
    scanf("%s", &operation);

    for(i=0 ; i<12 ; i++) {
        for(k=0 ; k<12 ; k++) {
            scanf("%lf", &matriz[i][k]);
        }
    }

    sum = calculate_column_sum(matriz, column);

    if(operation[0] == 'M') {
        sum = sum/12;
    } 

    printf("%.1lf\n", sum);

    return 0;
}