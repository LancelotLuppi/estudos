#include <stdio.h>

int main() {
    double M[12][12];
    double calc = 0;
    int i, j;
    char op[5];
    
    scanf("%s", &op);
    
    for(i=0 ; i<12 ; i++) {
        for(j=0 ; j<12 ; j++) {
            scanf("%lf", &M[i][j]);
        }
    }
    
    for(i=0 ; i<=4 ; i++) {
        for(j=i+1 ; j<=10-i ; j++) {
            calc += M[i][j];
        }
    }
    
    if(op[0] == 'M') {
        calc = calc/((144-12-12)/4);
    }
    
    printf("%.1lf\n", calc);
}