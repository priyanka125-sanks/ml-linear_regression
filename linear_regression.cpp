
#include <stdio.h>
#include <conio.h>

void regression(float[], float[], int, float[]);
int main() {
    // float x1[] = {1,2,3,4,6,8};
    // float y1[] = {2.4, 3, 3.6, 4, 5, 6};
    // int n1 = 6;
    
    // float x2[] = {0, 1, 2, 3, 4};
    // float y2[] = {1, 1.8, 3.3, 4.5, 6.3};
    // int n2 = 5;
    int n, i=1;
    printf(" Enter the no of samples: ");
    scanf("%d",&n);
    float x[]={};
    float y[]={};
    printf("Enter the samples");
    for(i=1;i<=n;i++){
       scanf("%f",&x[i]);
       scanf("%f",&y[i]);
    }
    printf("The samples are: \nX\t\tY\n");
    for(i=1;i<=n;i++){
        printf("%f\t\t%f\n",x[i],y[i]);

    }

    float xval;
    printf("Enter the unknown value-");
    scanf("%f",&xval);
    // float xval2 = 2.5;
    
    float yval;
    
    float regcoeff[2];
    regression(x, y, n, regcoeff);
    // regression(x2, y2, n2, regcoeff2);
    
    yval = regcoeff[0] + regcoeff[1]*xval;
    // yval2 = regcoeff2[0] + regcoeff2[1]*yval2;
    
    printf("For dataset, for x = %f, y = %.3f\n",xval, yval);
    // printf("For second dataset, for x = 2.5, y = %.3f\n", yval2);
    
    return 0;
}

void regression(float x[], float y[], int n, float regcoeff[]) {
    float sum_x = 0, 
            sum_y = 0, 
            sum_x2 = 0, 
            sum_xy = 0;
    for(int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i]*x[i];
        sum_xy += x[i]*y[i];
    }
    
    regcoeff[0] = (sum_y*sum_x2 - sum_x*sum_xy)/(n*sum_x2 - sum_x*sum_x);
    regcoeff[1] = (n*sum_xy - sum_x*sum_y)/(n*sum_x2 - sum_x*sum_x);
       
}