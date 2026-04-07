#include <stdio.h>
int main(){
    //variables
    double num1;
    double num2;
    char operator;
    double result;
    

    //user input
    printf("Enter the expresion here: \n");
    scanf("%lf%c%lf",&num1,&operator,&num2);

    //calculations
    if(operator=='+'){
        result=num1+num2;
    }
    else if(operator=='-'){
        result=num1-num2;
    }
    else if(operator=='*'){
        result=num1*num2;
    }
    else if(operator=='/' && num2 != 0){
        result=num1/num2;
    }
    else if (operator=='/' && num2 == 0){
        printf("Undefined");
        return 0;
    }
    else{
        printf("Undefined");
        return 0;

    }
    
    //print the result
    printf("Result: %.4f\n",result);



    return 0;
}   
