#include<stdio.h>
int main(){
    //Variables
    char exp[100];
    double result;
    char current_op = '+';
    int i = 0;
    double temp_result = 0;
    double current_num = 0;

    //User input:
    printf("Enter your arethmatic expression here: \n");
    fgets(exp,100,stdin);

    // loop till the last character in exp \0
    while (exp[i] != '\0')
    {
        // if we scan a space we skip to the next character
        if (exp[i] == ' ')
        {
            i=i+1;
        }
        
        else if ((exp[i]>=0) && (exp[i]<=9))
        {
            current_num = current_num*10 + 'exp[i]'-'0';
            i=i+1;
        }
        
    }
    // current result
    
    

    return 0;
}