#include<stdio.h>
int main()
{
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
        //go through all the characters that are until it's not inbetween 0-9
        else if ((exp[i]>='0') && (exp[i]<='9'))
        {
            current_num = current_num*10 + (exp[i]-'0');
            i=i+1;
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {   
            //Combining temp result, current op and current number
            if (current_op == '+')
            {
                temp_result = temp_result + current_num;
            }
            else if (current_op == '-')
            {
                temp_result = temp_result - current_num;
            }
            else if (current_op == '*')
            {
                temp_result = temp_result * current_num;
            }
            else if ((current_op == '/') && current_num != 0)
            {
                temp_result = temp_result / current_num;
            }
            else
            {   printf("Undefined");
                return 0;
            }
        }
        // let's store the next operator
        current_op = exp[i];
        i=i+1;
        current_num=0;
    }
    
    // When the program reaches the the last character \0 , the loop ends, leaves with the result value at temp result 
    result=temp_result;
    printf("Result: %.4f\n", result);
    
    

    

    return 0;
}