
#include <iostream>
using namespace std;

void SwapValue(int num1, int num2)
{
int tmp;
tmp =num1;
num1= num2;
num2=tmp;
}

void SwapReference(int *ptr1, int *ptr2)
{
    int tmp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=tmp;
}

int main(void)
{
    int num1=20;
    int num2=30;
    SwapValue(num1,num2);
    printf("%d %d", num1, num2);
    
    SwapReference(&num1, &num2);
    printf("%d %d",num1, num2);
    return 0;
}



#include <stdio.h>
#include <iostream>
using namespace std;
int foo()
{
    int i=0, j;
        j=i+2;
    return j;
}
int main()
{   
    for(int i =0; i<10; i++){
        printf("result #%d: %d\n",i, foo());
    }
    char x, y;
    x = -128;
    y = -x;
    //printf("%s", x);
    if(x==y) printf("1");
    if((x -y)==0)  printf("2");
    if((x+y)==2*x) printf("3");
    if(x!=y) printf("4");
    
    int a=23, r=0;
    a=214748367;
    r=a+1;
    std::cout<<a<<"+1="<<r<<std::endl;
    
    bool a=true;
    cout<<"a="<<a<<endl;
    a=false;
    cout<<"a="<<a<<endl;
    a=98;
    cout<<"a="<<a<<endl;
    a=0;
    cout<<"a="<<a<<endl;
    return 0;
    
}