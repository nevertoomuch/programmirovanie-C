#include <stdio.h> 


double determinant2x2(double matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}


double determinant3x3(double matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}


void cramer(double A[][3], double B[], int size) {
    double detA, detX, detY, detZ;

    
    if (size == 2) {
        detA = determinant2x2(A);
        
        double A1[2][2] = {{B[0], A[0][1]}, {B[1], A[1][1]}};
        detX = determinant2x2(A1);
        
        
        double A2[2][2] = {{A[0][0], B[0]}, {A[1][0], B[1]}};
        detY = determinant2x2(A2);
        
    
        printf("x = %.2lf, y = %.2lf\n", detX / detA, detY / detA);
    } else if (size == 3) {
        detA = determinant3x3(A);
        
        
        double A1[3][3] = {{B[0], A[0][1], A[0][2]}, {B[1], A[1][1], A[1][2]}, {B[2], A[2][1], A[2][2]}};
        detX = determinant3x3(A1);
        
        
        double A2[3][3] = {{A[0][0], B[0], A[0][2]}, {A[1][0], B[1], A[1][2]}, {A[2][0], B[2], A[2][2]}};
        detY = determinant3x3(A2);
        
        
        double A3[3][3] = {{A[0][0], A[0][1], B[0]}, {A[1][0], A[1][1], B[1]}, {A[2][0], A[2][1], B[2]}};
        detZ = determinant3x3(A3);
        
        
        printf("x = %.2lf, y = %.2lf, z = %.2lf\n", detX / detA, detY / detA, detZ / detA);
    }
}

int main() {
    int size;
    
    printf("Размер матрицы: ");
    scanf("%d", &size);

    
    double A[3][3]; 
    double B[3]; 


    printf("Коэффициенты:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    
    printf("Свободные члены:\n");
    for (int i = 0; i < size; i++) {
        printf("B[%d]: ", i);
        scanf("%lf", &B[i]);
    }

    
    cramer(A, B, size);

    return 0; 
}
