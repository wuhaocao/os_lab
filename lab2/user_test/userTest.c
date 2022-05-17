#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

long cwh_oper_u(int* result, int num1, int num2, char* op)
{
        if(op)
        {
                if(*op == '+')
                        *result = num1 + num2;
                else if(*op == '-')
                        *result = num1 - num2;
                else if(*op == '*')
                        *result = num1 * num2;
                else if(*op == '/')
                {
                        if(num2 != 0)
                                *result = num1 / num2;
                        else
                                printf("divided number can't be zero.\n");
                }
        }
        else
        {
                printf("operator is empty.\n");
        }
        return 0;
}

int main()
{
	int count = 10000 * 10000;
	struct timeval tstart, tend;
	struct timezone tz;
        gettimeofday(&tstart, &tz);
        int i;
        int result;
        int times = count / 4;
        for(i = 0; i < times; ++i)
        {
                char op_add = '+';
                cwh_oper_u(&result, 10, 10, &op_add);
        }
        printf("cwh_func op_add is ok. op_add count is: %d\n", i);

        for(i = 0; i < times; ++i)
        {
                char op_sub = '-';
                cwh_oper_u(&result, 20, 10, &op_sub);
        }
        printf("cwh_func op_sup is ok. op_sup count is: %d\n", i);

        for(i = 0; i < times; ++i)
        {
                char op_mul = '*';
                cwh_oper_u(&result, 10, 10, &op_mul);
        }
        printf("cwh_func op_mul is ok. op_mul count is: %d\n", i);

        for(i = 0; i < times; ++i)
        {
                char op_div = '/';
                cwh_oper_u(&result, 20, 10, &op_div);
        }
        printf("cwh_func op_div is ok. op_div count is: %d\n", i);

        gettimeofday(&tend, &tz);
        printf("cwh_func running time is %ld usec\n", 1000000 * (tend.tv_sec - tstart.tv_sec) + (tend.tv_usec - tstart.tv_usec));

        return 0;
	
}

