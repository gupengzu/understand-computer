#include <stdio.h>
#include <string.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, int len) 
{
    for (int i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(x));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(x));
}

void show_pointer(void* x)
{
    show_bytes((byte_pointer)&x, sizeof(x));
}

void replace_swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void X_change(int* x)
{
    *x = *x & 0xFF;
    *x = *x | (~0 << 8); // 使用无符号整数常量 0U 代替 0
    printf("%d", *x);
}

int main()
{
    //char* s = "ABCEDF";
    //show_bytes((byte_pointer)s, strlen(s) + 1);

    int a = 10;
    int b = 20;
    int* swap1 = &a;
    int* swap2 = &b;
    replace_swap(swap1, swap2);
    printf("%d ", a);
    printf("%d \n", b); // 应看到 a 和 b 的值交换了

    //int c = 100045;
    //X_change(&c);



    //short int x = 12345;
    //short int mx = -x;
    //show_int(x);
    //show_int(mx);


    short sx = -12345;  // 有符号短整型
    unsigned short usx = sx;  // 无符号短整型
    int x = sx;  // 有符号整型
    unsigned ux = usx;  // 无符号整型

    // 打印变量的十进制值和字节表示
    printf("sx = %d:\t", sx);
    show_bytes((byte_pointer)&sx, sizeof(short));

    printf("usx = %u:\t", usx);
    show_bytes((byte_pointer)&usx, sizeof(unsigned short));

    printf("x = %d:\t", x);
    show_bytes((byte_pointer)&x, sizeof(int));

    printf("ux = %u:\t", ux);
    show_bytes((byte_pointer)&ux, sizeof(unsigned));


    return 0;
}