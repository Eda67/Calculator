#include<stdio.h>
//should check is c is one of the operations 
int expressions(is_operation)
{
    
}


int is_operation(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    return 1;
    
    else
    return 0;
}

// def perofmOp(left, op, right)
//     return result 
double performOp(double left, char op, double right)
{
    if (op == '+')
    {
        return left + right;
    }
    if (op == '-')
    {
        return left - right;
    }
    if (op == '*')
    {
        return left * right;
    }
    else if ((op == '/') && op != 0)
    {
        return left / right;
    }
    else
    {   printf("Undefined");
        return 0;
    }
}

int main()
{
    //Variables
    char exp[100]; // char• exp
    double result;
    char current_op = '+';
    int i = 0;
    double temp_result = 0;
    double current_num = 0;

    /*
    0 + 4 - 1


    4 - 1 * 2 + 5
    3 * 2 + 5
    6 + 5

    we process expression left to right (1 char at a time)
        - if spaces -> skip/ ignore them 
        - if number -> store in current_num (the last number)
        - temp_result -> result so far
        - if isOperator(+-* /) -> 
            - do the operation
                - temp_result = (temp_resutlt current_op curent_num)
            - store current_op = exp[i]
    */
    //User input:
    printf("Enter your arethmatic expression here: \n");
    fgets(exp,100,stdin);

    // loop till the last character in exp \0
    // "4 - 1"
    // "4 - 1\n"
    while (exp[i] != '\0')
    {
            
        // if we scan a space we skip to the next character
        if (exp[i] == ' ')
        { } 
        //go through all the characters that are until it's not inbetween 0-9
        else if ((exp[i]>='0') && (exp[i]<='9'))
        {
            current_num = current_num*10 + (exp[i]-'0');  // -'0' changes the char to int
        }
        else if(is_operation(exp[i]))
        {   
            //Using the function performOp to get the result for the previous operation
            temp_result = performOp(temp_result, current_op, current_num);

            // let's store the next operator
            current_op = exp[i];
            current_num=0;
        }
        else { // ignore any other characters
        }
        ++i;// i+=1
    }       
    //Using the function performOp to get the result for the current operation
    result = performOp(temp_result,current_op,current_num);
    // When the program reaches the the last character \0 , the loop ends, leaves with the result value at temp result 
    
    printf("Result: %.4f\n", result);
    return 0;
}