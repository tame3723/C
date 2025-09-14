#include <stdio.h>
float BMI(float, float);
int main(){
    float w; 
    float h;
    printf("Enter weight ");
    scanf("%f \n",w);
    printf("Enter height ");
    scanf("%f \n",h);
    printf("BMI is: %f ", BMI(w,h));
}
float BMI(float a, float b){
    return(a/(b*b));
}