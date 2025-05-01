#include <stdio.h>
struct data
{
    int d1;
    double d2;
    char d3;
}Data;

union u_data
{
    int d1;
    double d2;
    char d3;
}U_data;

int main(void)
{
    printf("%d\n", sizeof(Data));
    printf("%d", sizeof(U_data));
    return 0;
}
