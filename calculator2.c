//ask user for the input
// ex:22-3+(4*2)/6
// ex:22-6/2+(4*2)/6
// we process the expression lest to right, one char at a time fgets
// we start with , temp_result=0, current_op ='+', current_num=0
/* -if sapce skip
    - if number = build the current_num
    -if operation 
        -temp_result = current_number current_op temp_result
        -store the exp[i] in current_op
        -current_num=0
    -if '('
        -if number = build the current_num
        -if operation
            -temp_result = current_number current_op temp_result
            -store the exp[i] in current_op
            -current_num=0
            -return double temp_result
            if ) -return 0
    current_number= result from function '('
    goal result=temp result

*/
# include <stdio.h>
int main()
{

}