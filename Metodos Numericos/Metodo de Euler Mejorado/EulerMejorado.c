#include <stdio.h>

double evalEcDiferencial (double , double);

int main() {   
    double x, y, y_actual, interA, interB, tamPaso, evalED;
    int i = 0, iter;
    
    
    printf("\nIntroduzca la y inicial: ");
    scanf(" %lf", &y);
    printf("\nIntroduzca el valor del intervalo izquierdo (a): ");
    scanf(" %lf", &interA);
    printf("\nIntroduzca el valor del intervalo derecho (b): ");
    scanf(" %lf", &interB);
    printf("\nIngrese el tamanyo de paso (h): ");
    scanf(" %lf", &tamPaso);
    
    iter = ((interB - interA)/tamPaso)+1;
    x = interA;
    
    do {
        //printf("X%d = %f \t Y%d = %f\n ", i, x, i, y);
        evalED = evalEcDiferencial(x,y);
        
        y_actual = y + tamPaso*evalED;
        
        printf("X%d = %f \t Y%d = %f\n ", i, x, i, y);
        
        y = y + (tamPaso/2)*(evalED + evalEcDiferencial(x+tamPaso,y_actual));
        
        x += tamPaso;
        i++;
        
        if (i==iter) printf("X%d = %f \t Y%d = %f\n ", i, x, i, y);
    } while (i!= iter);
    
    return 0;
}

double evalEcDiferencial (double x, double y) {
    return x+y*y;
}
