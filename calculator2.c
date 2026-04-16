//ask user for the input
// ex:22-3+(4*2)/6
// ex:22-6/2+(4*2)/6
// here we will declare functions before defining it, reason: we have to call it inside other functions that should come first
/*
Function 1: int skip spaces()
Function 2:doubl read_parts()=skip space() 
                        if isdigit()
                        if ( then i++ and use the fuction calculation  
                        if ) then i++
                        else print Missing brakets
                        return temp result;
Function 3: double mul_div_calculation()= 
Function 4: double add_sub_calulation()= it shoudl first call the mul_div_calculation(), so that this function forst parse before the +/- operation
Function 4: double calculation()=mul_div_calculation()
                            add_sub_calculation()
int main()=
        read_parts()    
        mul_div_calculation()
        calculation()

        result=temp result
                            

*/

# include <stdio.h>
# include <ctype.h>

void skip_space();
double read_parts();
double mul_div_calculations();
double add_sub_calculations();
double full_calculations();
char expr[200];
int i=0;

void skip_space()
{
    while (isspace(expr[i]))
    {
        i++;
    }
}

double read_parts() // this will only return current_num, only involves calculations inside the brakets
{
    double current_num=0;
    skip_space();
    if (expr[i]=='(')
    {
        i++;
        skip_space();
        current_num=full_calculations();
        if (expr[i]==')')
        {
            i++;
        }
        else 
        {
            printf("Error,there is a bracket missing.");
        }
        return current_num;
    }
    while (isdigit(expr[i]))
    {
        current_num=current_num*10+(expr[i]-'0');
        i++;
    }
    return current_num;
}

double mul_div_calculations()
{
    double result;
    double left = read_parts();
    double right;
    skip_space();
    if (expr[i]=='/')
    {
        i++;
        skip_space();
        right=read_parts();
        result=left/right;
    }
    else if (expr[i]=='*')
    {
        i++;
        skip_space();
        right=read_parts();
        result=left*right;
    }
    else
    {
        result=left;
    }
    return result;
}
double add_sub_calculations()
{
    double result;
    double left=mul_div_calculations();
    double right;
    skip_space();
    if (expr[i]=='+')
    {
        i++;
        skip_space();
        right=read_parts();
        result=left+right;
    }
    else if (expr[i]=='-')
    {
        i++;
        skip_space();
        right=read_parts();
        result=left-right;
    }
    return result;
}
double full_calculations() // combining callculations ??
{
    double result;
    return add_sub_calculations();
}
int main()
{
    double result;
    //user input
    printf("Enter your expression here: \n");
    fgets(expr,200,stdin);
    i=0;
    result=full_calculations();
    printf("Answer:%.2f\n",result);
    return 0;
}