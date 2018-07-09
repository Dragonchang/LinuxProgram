#include <stdio.h>
int Test(int a, int b) {
   int i= 44;
   int j = 55;

    unsigned int* byte_pointer = &i;//遍历byte_pointer数组是向高地址进行遍历
    printf("&i = %.16x\n",&i);
    printf("&j = %.16x\n",&j);


    printf("&byte_pointer[7] = %.16x\n",&byte_pointer[7]);
    printf("byte_pointer[7] = %.8x\n",byte_pointer[7]);

    printf("&byte_pointer[6] = %.16x\n",&byte_pointer[6]);
    printf("byte_pointer[6] = %.8x\n",byte_pointer[6]);


    printf("&byte_pointer[5] = %.16x\n",&byte_pointer[5]);
    printf("byte_pointer[5] = %.8x\n",byte_pointer[5]);
    byte_pointer[7] = 0;
    byte_pointer[6] = 4197332;
    printf("&byte_pointer[4] = %.16x\n",&byte_pointer[4]);
    printf("byte_pointer[4] = %.8x\n",byte_pointer[4]);

    printf("&byte_pointer[3] = %.16x\n",&byte_pointer[3]);
    printf("byte_pointer[3] = %.8x\n",byte_pointer[3]);

    byte_pointer[4] = 4196676;

    printf("&byte_pointer[2] = %.16x\n",&byte_pointer[2]);
    printf("byte_pointer[2] = %.8x\n",byte_pointer[2]);

    printf("&byte_pointer[1] = %.16x\n",&byte_pointer[1]);
    printf("byte_pointer[1] = %.8x\n",byte_pointer[1]);

    printf("&byte_pointer[0] = %.16x\n",&byte_pointer[0]);
    printf("byte_pointer[0] = %.8x\n",byte_pointer[0]);


    printf("&byte_pointer[-1] = %.16x\n",&byte_pointer[-1]);
    printf("byte_pointer[-1] = %.8x\n",byte_pointer[-1]);


    printf("&byte_pointer[-2] = %.16x\n",&byte_pointer[-2]);
    printf("byte_pointer[-2] = %.8x\n",byte_pointer[-2]);


    printf("&byte_pointer[-3] = %.16x\n",&byte_pointer[-3]);
    printf("byte_pointer[-3] = %.8x\n",byte_pointer[-3]);


    printf("&byte_pointer[-4] = %.16x\n",&byte_pointer[-4]);
    printf("byte_pointer[-4] = %.8x\n",byte_pointer[-4]);

    printf("&byte_pointer[-5] = %.16x\n",&byte_pointer[-5]);
    printf("byte_pointer[-5] = %.8x\n",byte_pointer[-5]);


    printf("&byte_pointer[-6] = %.16x\n",&byte_pointer[-6]);
    printf("byte_pointer[-6] = %.8x\n",byte_pointer[-6]);


    printf("&byte_pointer[-7] = %.16x\n",&byte_pointer[-7]);
    printf("byte_pointer[-7] = %.8x\n",byte_pointer[-7]);
   i = a;
   j = b;
   return 1;
}

void Test2() {
    int a =1;
    int b =2;
    int c =3;
    int d =4;
    int e =5;
    int f =6;
    int t =7;
    int y =8;
    int i =9;
    int p =10;

printf("Test2222*********************************************************\n");

}
int main(int argc, char *argv[])
{

    int a =1;
    int b =2;
    unsigned int* byte_pointer = &a;//遍历byte_pointer数组是向高地址进行遍历
    printf("&a = %.16x\n",&a);
    printf("&b = %.16x\n",&b);
    printf("&byte_pointer[0] = %.16x\n",&byte_pointer[0]);
    printf("byte_pointer[0] = %.8x\n",byte_pointer[0]);


    printf("&byte_pointer[1] = %.16x\n",&byte_pointer[-1]);
    printf("byte_pointer[1] = %.8x\n",byte_pointer[-1]);


    printf("&byte_pointer[2] = %.16x\n",&byte_pointer[-2]);
    printf("byte_pointer[2] = %.8x\n",byte_pointer[-2]);


    printf("&byte_pointer[3] = %.16x\n",&byte_pointer[-3]);
    printf("byte_pointer[3] = %.8x\n",byte_pointer[-3]);


    printf("&byte_pointer[4] = %.16x\n",&byte_pointer[-4]);
    printf("byte_pointer[4] = %.8x\n",byte_pointer[-4]);

    printf("&byte_pointer[5] = %.16x\n",&byte_pointer[-5]);
    printf("byte_pointer[5] = %.8x\n",byte_pointer[-5]);


    printf("&byte_pointer[6] = %.16x\n",&byte_pointer[-6]);
    printf("byte_pointer[6] = %.8x\n",byte_pointer[-6]);


    printf("&byte_pointer[7] = %.16x\n",&byte_pointer[-7]);
    printf("byte_pointer[7] = %.8x\n",byte_pointer[-7]);

    Test(a, b);
    return 1;
}

