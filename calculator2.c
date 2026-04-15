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
Function 4: double add_sub_calulation()=
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
char exp[100];
int i=0;

void skip_space()
{
    while (isspace(exp[i]))
    {
        i++;
    }
}

double read_parts() // this will only return current_num, only involves calculations inside the brakets
{
    double current_num=0;
    if (exp[i]=='(')
    {
        i++;
        skip_space();
        current_num=full_calculations();
        if (exp[i]==')')
        {
            i++;
        }
        else 
            printf("Error,there is a bracket missing.");
            return current_num;
    }
    while (isdigit(exp[i]))
    {
        current_num=current_num*10+(exp[i]-'0');
        i++;
    }
    return current_num;
}

double mul_div_calculations()
{
    double result;
    if (exp[i]=='/')
    {
       result=read_parts(exp[i])/read_parts(exp[i+1]); 
    }
    else if (exp[i]=="*")
    {
        result=read_parts(exp[i])*read_parts(exp[i+1]);
    }
    return result;
}
double add_sub_calculations()
{
    double result;
    if (exp[i]=='+')
    {
        result=read_parts(exp[i])+read_parts(exp[i+1]);
    }
    else if (exp[i]=="-")
    {
        result=read_parts(exp[i])-read_parts(exp[i+1]);
    }
    return result;
}
double full_calculations() // combining callculations ??
{
    double result;
    while (ischar(exp[i]) && exp[i]!='(' && exp[i]!=')')
    {
        if (mul_div_calculations())
        {
            result=mul_div_calculations();
        }
        else if(add_sub_calculations())
        {
            result=add_sub_calculations();
        }
        return result;
    }
}
int main()
{
    double result;
    //user input
    printf("Enter your expression here: \n");
    fgets(exp,200,stdin);
    while (exp[i]!='\0')
    {
        read_parts();
        full_calculations();
        mul_div_calculations();
        add_sub_calculations();
        result=full_calculations();
    }
    printf("Answer:%.2f\n",result);
    return 0;
}