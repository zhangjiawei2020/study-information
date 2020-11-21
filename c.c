==数组

int a[10]={1,2,4,6};
%未被赋值的自动化为0;
int a[10]={0};
%数组全部初始化为0;
int a[10]={[4]=4,[5]=5};
%数组可以设置特定的位数;

%c 字符 %d 数字 %f小数
scanf("%d",&n);
printf("%s\n",i);

字符串数组的末尾必须为/0;
getchar() 每次从缓冲区中拿出一个字符;

==字符串

char s[10]={"fish!"};
char s[]="fish!"; %最好用

处理字符串的函数

strlen() 获取字符串长度，不包含\0
sizeof   计算字符串时包含\0

#include<strings.h>
//使用字符串函数时需要声明相关的头文件
strcpy :拷贝字符串 
strcpy(a,b) 将字符串b赋值给字符数组a
strcpy(a,"are you ok?") 拷贝的过程中也会拷到\0;
strncpy(a,b,5);限制将5个字符给a,但是要追加一个"\0";
a[5]="\0";
strcat(str1,str2),连接字符串
strcatn(str1,str2,5);会自动追加\0==截取字符串

strcmp(st1,str2) %逐次比较两个字符串的ascii码
一样返回0 <返回1 >返回-1
strcmp()==0;

==二维数组
int a[6][6]; 6*6 二维数组
char b[6][6];
double c[13][13];
通过下表来访问数组;
int a[3][4]={ 1,2,3,4,4,5,5,6,4,5,6,7};
int a[3][4]={0}; 全部初始化为0;	   
int a[3][4]={{0},{4},{9}};

==二维矩阵的转置
int a[3][4],b[4][3];
for(int i=0;i<3;i++)
{
	for(int j=0;j<4;j++)
	{
		b[j][i]=a[i][j];
	}
}

===指针 
char *pa 定义了一个char型的指针变量
int *pf  定义了一个int型的指针变量
指针变量里面存的是地址, *叫做地址运算符
char *pa=&a;  保存的是a的地址  &取址运算符
printf("%c\n",*pa);
*叫做取址运算符，*pa是这个地址里面存放的内容
pa是地址，

%p 表示打印地址类型的数据
=====指针一定要初始化，要赋值地址
char b='z';   字符数组
char b[]="zhang";   字符串数组
char *p=&a;

===指针与数组
scanf("  ",p)  #地址
！！数组名是数组的第一个元素的地址
数组是同类型连续的地址
int a[10];
int *p;
p=a; // p=&a[0] 两者等价

*(p+1) 指向下一个元素
printf("%d %d\n",*a,*(a+1));
p[i] 指针数组可以访问下一个元素

===指针数组和数组指针
*p++          p++  然后取地址，可以改变
*a++   错误，数组名只是个地址，不能改变

int *p1[5]   int *(p1[5])    括号的运算级别更高  
里面存放的是指针变量，存放的是地址


指针数组的例子
char *p[3]  就是利用指针数组来记录字符串
include<stdio.h>
int main()
{
	char *p[3]={
		"ni hao shi jie!",
		"are you ok?",
		"let's do it！"
	}
	int i;
	for(i=0;i<3;i++)
	{
		printf("%s\n",p[i]);  //这里要的是首地址
	}

	return 0;
}
printf("%s",p[0]);  每次输出的是字符串，\0结尾
printf("%c",*p[0]); 这个是取的字符串的首字符


数组指针是个指针，指向一个数组, 里面存放的是指针，是数组元素的地址
   0   1   2    3    4     5
  int int  int  int  int   int
#include<stdio.h>
int main()
{
	int a[5]={1 2 3 4 5};
	int (*p)[5]=a;  //这里取了数组的地址给p ！！！！
	int i;
	for(i=0;i<5;i++)
	{
		printf("%d\n",*(*p+i));  //*p是个地址 *p+i 是个地址
 	} 
 	return 0;

}

int main (int argc,char *argv[])
argc 参数指定的是程序的参数数量（包括程序名本身）
而 argv 这个数组指针指向的则是每个参数的名字（字符串）
atoi("1123")   将字符型转为整形

int a[]4[5]
array 首地址   array+1 第二行的首地址
*(array+1)=array[1]  地址 


https://www.zhihu.com/search?type=content&q=c%E8%AF%AD%
E8%A8%80%20%20%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84%20%E6%8C%87%E9%92%88

https://blog.csdn.net/wuyuzun/article/details/82778553


int * p[n] 就是一个指针数组,数据类型为int *，元素为地址
p有自己的地址，*p[4]={&a,&b,&c,&d};
！！！！================赋值的时候要当成数组
p 是自己的地址   *p是 a的地址   **P 才是a的值
        int a[3][4]={0};
        int *p[3]={a[0],a[1],a[2]};   
        printf("a       =       %d\n",a);
        printf("&a      =       %d\n",&a);
        printf("a+1     =       %d\n",a+1);
        printf("&a+1    =       %d\n",&a+1);
        printf("*p      =       %d\n",*p); 
        printf("*p+1    =       %d\n",*p+1);
        printf("*(p+1)  =       %d\n",*(p+1));               
        printf("*(P+1)+1=       %d\n",*(p+1)+1);
        printf("p       =       %d\n",p);
        printf("p[1]    =       %d\n",p+1);




int (*p)[n] 就是一个数组指针，数据类型为int ()[n]； p是二维数组的数组名
*p是首地址 a=p=*a=*p=&a[0][0]=&p[0][0]

int (*p)[4]=a;
！！！！=================赋值的时候当成指针 int(*p)=a;
*p 是a的地址 相当于&a;
*(p+1)==相当于&(a+1)==a[1]  
*(p+1)+j  加来加去还是地址 
*(*(p+1)+j)  这才是元素值
         a+1 是直接为下一个数组的首地址

        int b[3][4]={0};
        int (*q)[4]=b;   //一维数组指针，数组元素要对应
        printf("b       =       %d\n",b);
        printf("*q      =       %d\n",*q);
        printf("b+1     =       %d\n",b+1);
        printf("&b+1    =       %d\n",&b+1);
        printf("*q+1    =       %d\n",*q+1);
        printf("*(q+1)  =       %d\n",*(q+1));
        printf("**q     =       %d\n",**q);

==================void 指针
void *p;
 
通用指针 可以指向任意类型 的数据
强制类型转化 可以将 void 指针指向其他类型
  *(int *)p  p是一个指针, (int *) 强制转换
  #include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int main()
{
        int a=10;
        char b[]="zhang";  //字符串需要char数组
        int *p=&a;
        char *q=b;
        void *p1;
        
        p1=p;
        
        printf("a       =       %d\n",a);
        printf("*p      =       %d\n",*p);
        printf("*p1     =       %d\n",*(int *)p1);
        printf("sizeof(*p1)=    %d\n",sizeof(*(int *)p1)); //强制转换
        p1=q;

        printf("b       =       %s\n",b);
        printf("*q      =       %s\n",q); //首地址
        printf("*p1     =       %s\n",(char *)p1);


        return 0;
}

==========NULL指针
#define NULL ((void *)0) //地址0 一般不存储数据

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int main()
{
        int *p1;
        int *p2=NULL;
        printf("*p1     =       %d\n",*p1);
        printf("*p2     =       %d\n",*p2);  //空指针 报错
        return 0;
}
===========**p 指向指针的指针====================
int a    =	10;
int *p   =	&a;
int **pp =	&p;

#include <stdio.h>
int main()
{	
	char *p[]={
                "ni hao ya?",
                "wo hen hao.",
                "ni zai shuo sha?",
                "ni cai ya!"};
        char **p1;
        p1=&p[0];   //地址的地址
        char **p2;
        printf("*p[1]   =      %s\n",p[0]);
        printf(" %d     \n",&p[0]);
        printf(" %d     \n",p1);  //p1=&p[0];
        printf(" %d     \n",*p1);
        printf(" %d     \n",p[0]);//*p1=p[0]
        printf(" %s     \n",*p1);  //打印字符串只需要地址，int型就需要值
        
	return 0;
}

int a[3][4];
int **p  p+1 	跨过四个字节，因为是int 型
int (*p)[4]		数组指针  跨过的是4*4个字节，这就是为什么要写明 二维数组的列,一维数组每次跨4 int 
	*(p+i)+j = &a[i][j];
	*(*(p+i)+j) = a[i][j];

====变量和常量  常量指针=========================== 
const int a=4; 只读 不可写入
const int *p=&a; 指向常量的指针
int* const p;常量指针 
 
#include <stdio.h>
int main()
{	
        int a=4,b=10;
        int * const p=&a;
        *p=5;
        printf("p=      %p\n",p);
        printf("a=      %d\n",*p);
	
        *p=&b; //error! cause p是一个指针常量，不能被修改
     	return 0;
}

const int a=5;
int * const  p 	 =   &a;  //指向常量的常量指针
int * const *pp  =	 &p;

==========函数====================================
void 不返回数据
int 函数名();   //函数声明 可以将子函数写在后面
int 函数名(参数列表)  //没有参数写()
{
	函数体
}


#include <stdio.h>
void print_c();   //函数的声明

int main()
{	
        print_c();
        return 0;
}

void print_c()    //函数的定义
{
        printf(" #########\n");
        printf(" ##     ##\n");
        printf(" ##       \n");
        printf(" ##       \n");
        printf(" ##       \n");
        printf(" ##     ##\n");
        printf(" #########\n");       
}

==函数的参数和返回值 也可以返回是否运行成功
#include <stdio.h>
int sum(int n);
int sum(int n)
{
        int j = 0;
        int i;
        for (i=1;i<=n;i++)
        {
                j+=i;
        }
        return j;
}
int main()
{	
        int n,result;
        printf(" input the number n:   \n");
        scanf("%d",&n);//scanf("%d\n",&n) is wrong 没有/n
        printf("\n");
        printf("n=      %d      \n",n);
        printf("the result is %d \n",sum(n));
        return 0;
}

#include <stdio.h>
int maxx(int i,int j);
int maxx(int i,int j)
{
        int num1,num2;
        num1=i;num2=j;
        if (num1>num2)
                return num1;
        else    
        		return num2;
}
int main()
{	
        int i,j;
        printf("please input two number:  \n");
        scanf("%d %d",&i,&j);
        printf("\n");
        printf("the larger number is %d \n",maxx(i,j));
}

=======函数参量为指针 地址
#include <stdio.h>
void swap(int *x,int *y); //输入为指针int * 类型的变量
void swap(int *x,int *y)  
{
        int z;
        z=*x;
        *x=*y;
        *y=z;
}
int main()
{
        int x=3,y=4;
        swap(&x,&y);  //这里要传入地址
        printf("x= %d, y= %d",x,y);
        return 0;
}
=======传递array  传递数组
	void getarray_c(int a[10])

	int a[10]={1,2,3,4,5,6,7,8,9,0};
	getarray_c(a)  //
	/*这里传递的只是首地址，在子函数里面变了之后会对
	原位置的数组也改变*/

#include <stdio.h>
#include <strings.h>
void getarray_c(int b[10]);
void getarray_c(int b[10])
{
	printf("b       =     %d\n",sizeof(b[0]));
}	
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,0};
	printf("a       =       %d\n",sizeof(a));
	getarray_c(a);
	return 0;
}

=======可变参数
#include <stdarg.h>
va_list 

-va  variable-argument 可变参数


============指针函数，常用于字符串

char *getword(char c)
/*为什么用指针函数 ，主要是返回字符串，因为字符串没有
对应的数组，我们用char *来定义字符串，这样在main函数里面
调用时就相当于printf("%s \n",*getword()),*getword得到的
是子函数里面字符串的首地址，%s默认字符串在\0位置结束！！！*/


char a='b';
switch(a)
{
	case 	'a'		:return() or printf( ); break; //如果加了break，则进入对应的case之后直接结束
	case 	'b'		:return() or printf( ); break; //否则就会继续往下进行判断
	case  


	default : printf( );
}
==============
不要返回局部变量的指针     //a1 a2相当于返回局部变量，这种错误，直接return "apple"
the wrong example:
#include <stdio.h>
char *getch(char a);
char *getch(char a)
{		
	char a1[]="apple";
	char a2[]="banana";
	char a3[]="cat";
	char a4[]="dog";
	char a5[]="none";
       switch (a)
       {
       case 'a':return a1;
       case 'b':return a2;
       case 'c':return a3;
       case 'd':return a4;
       default : return a5;
       } 
}

int main()
{
        char a;
        printf("please input zimu: \n");
        scanf("%c",&a);   //!!!!!!!!注意加&,这个编译器不会检查出来
        printf("\n");
        printf("%s \n ",getch(a));
        return 0;
}

===============函数指针 本质是指针，指向函数
int (*p)()   函数指针
int *p()     指针函数
int sequare(int num)  /*函数名相当于函数的首地址,和数组名一样,所以指针
 *p=sequare就可以,*p=&sequare 也可以*/

#include <stdio.h>
int cheng(int num);
int cheng(int num)
{
        return num*num;
}

int main()
{
        int num;
        int (*pin)(int);
        pin=&cheng;              //这里要保证函数指针和要指向的函数一致，包括返回类型和参数
        						//当然这里也可以是 pin=cheng 因为函数名就是首地址 466行 
        printf("please input a number: \n");
        scanf("%d",&num);
        printf("\n");
        printf("%d * %d = %d ",num,num,(*pin)(num));
        return 0;
}
=====函数指针作为参数

int cala(int (*pin)(int,int),int,int);
int cala(int (*pin)(int,int),int num1,int num2)
{
	return (*pin)(num1,num2);
}
 这里的int (*pin)(int,int) 可以指向很多的函数名
 cala(add,5,3);
 cala(sub,5,3);   add和sub都是 int *** (int,int)的函数

switch()语句

#include <stdio.h>

//函数指针
int add(int num1,int num2);
int jian(int num1,int num2);
int cac(int (*fp)(int ,int),int,int);
int (*select(char f))(int ,int );
int add(int num1,int num2)
{
    return num1+num2;
}

int jian(int num1,int num2)
{
    return num1-num2;
}

int cac(int (*fp)(int ,int),int num1,int num2)
{
    return (*fp)(num1,num2);
}

int (*select(char f))(int ,int)   //函数指针，返回带有两个int型的函数名
//int      ( * )(int ,int)  
{
    switch(f)
    {
        case '+': return add;
        case '-': return jian;
        
    }
}
int main()
{
    int num1,num2;
    char f;
    int (*fp)(int,int);   //函数指针
    printf("please input biao da shi:  '1+2' \n");
    scanf("%d%c%d",&num1,&f,&num2);
    fp=select(f);
    printf("%d%c%d=%d",num1,f,num2,cac(fp,num1,num2));
}
====局部变量和全局变量
for语句里面的int 定义是局部变量 作用域为for{  }


include <stdio.h>

int count = 0 ;  全局变量

int main()
{	
	int count = 2;   //局部变量会屏蔽掉全局变量
	return 0;
}

========extern 关键字 告诉编译器我会在后边来定义这个变量，先不要报错

#include <stdio.h>
void fun();
void fun()
{
	extern int count;
	count++;
}
int count = 0;
int main()
{
	fun();  //调用函数
	printf("%d \n",count);
	return 0;
}

========作用域
========文件作用域

声明：变量已经存在，不用再为此申请内存空间
定义：申请内存空间

===链接属性 调用的库

.lib是常用的库

extern  变量被所有的.c文件可以调用
static 作用域只限于本身的.c文件，其他文件不可调用该变量
static int b=0;  只限于本.c文件       internal
extern int c=0;  可以多个.c文件使用   external

#include <stdio.h>
#include "a.c"  
//extern int count;   全局变量 count
// void a(void)
// {
//      count++;
//}
#include "b.c"
#include "c.c"

void a(void);
void b(void);
void c(void);
//其他地方有定义了这个函数,原定义
int count = 0;

int main(void)
{
    a();
    b();
    c();
    printf("%d \n",count);
    return 0;
}

====生存期
静态存储期：全局变量   //一直占据空间，直到程序关闭才释放
自动存储器：形式参数，局部变量   //代码块结束，存储会被释放
===存储类型
auto       自动变量//
register   寄存器变量//把这个变量存放在cpu的寄存器里，没有办法用取址运算符
//来取变量的地址  register int i = 1;      &i错误

static 静态局部变量//改为内部变量，单文件独享
static int i=0 ; //值不会被释放//会保留到文件运行的最后
extern 在外部已经声明过了，可以去找找，

=====递归
1.调用函数本身
2.设置正确的结束条件  //普通的hhhh
=====汉诺塔   神奇！！
#include <stdio.h>
void halin(int n,char x,char y,char z);
void halin(int n,char x,char y,char z)
{
    if(n==1)
    {
        printf("%c -- >%c \n",x,z);
    }
    else
    {
        halin(n-1,x,z,y);  //自己调用自己
        printf("%c -- >%c\n",x,z);
        halin(n-1,y,x,z);
    }   
}
int main(void)
{
    int n;
    printf("please input the number halin: \n");
    scanf("%d",&n);
    halin(n,'x','y','z');
    return 0;
}

==分治法
==数据结构与算法

==快速排序算法
#include <stdio.h>
void quick_sort(int *array,int n);
void quick_sort(int *array,int n)
{
    if (n<2)
      return ;
    int itemp=array[0];
    int ileft=0;
    int iright=n-1;
    int imove=2;
    if(ileft>iright) return;
    while(ileft<iright)
    {   
        if(imove==2)
        { 
             if(itemp>array[iright])
             {
                 array[ileft]=array[iright];
                 ileft++;
                 imove=1;     
             }
            else{
                    iright--;          
             }
        }
        if(imove==1)
        {
            if(itemp<=array[ileft])
            {
                 array[iright]=array[ileft];
                 iright--;
                 imove=2;
            }
            else{
                  ileft++;
            }  
        }
    }
    array[ileft]=itemp;
    quick_sort(array,ileft);
    quick_sort(array+ileft+1,n-1-ileft);

}
int main(void)
{
    int array[]={10,6,10,14,18,10,35,67,28,59,23,0};
    int left,right;
    int i,j,length;
    length=sizeof(array)/sizeof(array[0]);
    quick_sort(array,length);
        for(i=0;i<length;i++)
    {
        printf("%d  ",array[i]);
    }
    return 0;
}

====下面四个函数都需要使用  <stdlib.h>
==========malloc 函数，申请的空间放在堆上，用完之后要自己
释放完malloc申请的空间

void *malloc(size_t size); //申请内存空间，并返回指针
 
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int *ptr;
    ptr=(int *)malloc(sizeof(int)); //分配一个int的 空间指针
  
    printf("input a number ");
    scanf("%d",ptr);
    printf("%d\n",*ptr);
    free(ptr);    //释放掉一些空间
    return 0;
}

===========free函数 释放ptr参数指向的内存空间，但是这个内存空间必须
由malloc,calloc,realloc函数申请
void free(void *ptr) 
===========内存泄漏 申请的动态空间必须尽快被释放 malloc 和 free 配套使用
malloc(4);
free()        不能释放简单的指针

===========malloc() 申请一块任意尺寸的地址
int num;
int *ptr;
ptr=(int *)malloc(num*sizeof(int));
free(ptr);
===========memset() 使用一个常量字节填充内存空间
这些函数都需要  <stdlib.h>

===========memset()函数需要  <strings.h>;
#define  N 10
ptr=(int *)malloc(N*sizeof(int));
memset(ptr,0,N*sizeof(int));  //将N个内存全部设置为0;

===========calloc()函数 分配内存空间并初始化
int *ptr=(int *)calloc(8,sizeof(int));
calloc() 函数直接将分配的空间给初始话为0了，

等价于== malloc()函数+memset()函数

===========memcpy()函数 拷贝内存空间里面的值
int *ptr1,*ptr2;
ptr1=(int *)malloc(10*sizeof(int));
ptr2=(int *)malloc(20*sizeof(int));
memcpy(ptr2,ptr1,10); //将ptr1中的数据拷贝到ptr2里面 10个(int)类型数据
free(ptr1);
free(ptr2);
===========int *ptr=NULL;
           ptr=(int *)realloc(ptr,2*sizeof(int))函数,重新给ptr分配内存空间
如果ptr的参数为NULL,则这个函数相当于 malloc()函数
如果ptr的参数不为NULL,则分配内存

#include <stdio.h>
#include <stdlib.h> 
void quick_sort(int *array,int n);

int main()
{   //动态输入，动态存储
    int i,num;
    int *ptr= NULL;
    int count=0;
    printf("please input the mumber: \n");
    do
    {   
   
        scanf("%d",&num);    //输入数字
        count=count+1;         //
        ptr=(int *)realloc(ptr,count*sizeof(int));  
        //  ptr为空指针，则分配一个int 型,ptr不为空时,则重新分配内存空间，count个数目的int
        ptr[count-1]=num;     //作为指针或者数组名，从0开始赋值

    }while(num!=-1);
    printf("the number is : \n");
    count--;
    for(i=0;i<count;i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
    printf("pai xun zhi hou:\n");
    quick_sort(ptr,count);
    for(i=0;i<count;i++)
    {
        printf("%d ",ptr[i]);
    }
    putchar('\n');
    return 0;
}

==堆 ：动态分配的内存段，调用malloc函数等分配内存，使用free函数释放内存
==栈 ：函数执行的内存区域
堆：手动申请，手动释放的内存
栈：自动分配，自动释放
===高级的宏定义用法：宏 替换
#define r 6.34
#define PI 3.1415  //pi=3.1415 不是语句或说明，不用加分号
#define v= PI*r*r*r*4/3  //宏支持嵌套

#undef  PI   终止pi的宏定义

#define MAX(x,y) (  (   (x)>(y) )? (x):(y)  )
#define 定义的时候要加括号，因为宏定义时无脑替换

inline()函数会优化函数的调用
会将函数出现的地方进行替换
inline int sequare(int x);
inline int sequare(int x)
{

}

#define str(s) # s  //预处理操作符 
                    // ##预处理将s变成字符串  " "
#include <stdio.h>
#define str(s) # s
int main()
{   

    printf(str( %s  =  %d ),str(fishc),510);
    return 0;
}

#include <stdio.h>
#define str1(x,y) x y       //连接字符串
#define str2(x,y) x##y     //连接操作符 将x y连接起来  连接数字
//The result of ## must be a single token, and "HELLO""WORLD" 
//is not a single token. To concatenate strings, simply leave them beside each other:
int main()
{   
    printf("%s\n",str1("x11","y22"));
    printf("%d\n",str2(3,4));
    printf("hello ""world");
    return 0;
}

#define PRINT(format,...) printf(# format ,##__VA_ARGS__);
... 可变的输入参数 #format 变为字符 
## 连接作用     __VA_ARGS__表示传入的数据集

#include <stdio.h>
#define PRINT(format,...) printf(# format ,## __VA_ARGS__);
#define PRINT2(format,...) printf(# format ,# __VA_ARGS__);
#define str(x) # x
int main()
{   
    PRINT(num=%d %d %d %s\n,512,53,18,str(s1)); //连接需要每一个格式控制
    PRINT2(num=%s\n, 5,10,15,20);         //一个%s
    return 0; 
}

====结构体声明
struct 结构体名称 
{
    结构体成员1；

};

struct Book    //结构体声明 //第一个名字字母为大写
{
    char title[128];
    char author[40];
    float price;
    unsigned int date;   //unsigned 存放无符号的长数字
    char publisher[40];
};    //记得加分号

struct 结构体名称 结构体变量名
    . 点号运算符 ，引用结构体的内部成员

#include <stdio.h>
struct Book
{
    char title[128];
    char author[40];
    float price;
    unsigned int date;
    char publisher[40];
};
int main()
{
    struct Book book; //book变量名 
    printf("please input book name:\n");
    scanf("%s",book.title);
    printf("please input author:\n");
    scanf("%s",book.author);
    printf("please input price:\n");
    scanf("%f",&book.price);    //加地址运算符
    printf("please input book number:\n");
    scanf("%d",&book.date);       //加地址运算符
    printf("please input publisher:\n");
    scanf("%s",book.publisher);

  struct Book book={     //结构体的初始化//要一一对应
        "nihao wolaile",
        "zhang jiawei",
        48.8,
        201732599,
        "西北工业大学出版社"
    };

    struct Book book={   //可以部分进行初始化
        .price = 48.8,
        .publisher ="西北工业大学出版社",
        .date = 45819
    }

    struct Book book={.price = 48.8}; //单个初始化

    printf("===input is ready=====\n");
    printf("%s \n",book.title);
    printf("%s \n",book.author);
    printf("%。2f \n",book.price);
    printf("%d \n",book.date);
    printf("%s \n",book.publisher);

return 0;
}

=================通过改变定义结构体的顺序，
可以达到节省内存空间的目的
struct A
{ 
    char a,
    int b,
    char c,
    
}a={'a',12,'c'};  占用1(4)+4+1(4) 12个字节
 
struct A
{ 
    char a,
    char b,
    int c,
    
}a={'a','c',12}; 占用2(2)+4   8个字节

==================结构体的嵌套
#include <stdio.h>
#include <stdio.h>   //结构体里面是分号
struct Date
{
    int year;
    int mouth;
    int day;
};
struct Book
{
    char title[128];
    char author[40];
    float price;
    struct Date date;
    char publisher[40];
}book={                 ///结构体初始化
        "nihao wolaile",
        "zhang jiawei",
        48.8,
        {2017,8,15},
        "xibeigongyedaxue"
};
int main()
{

    printf("===input is ready=====\n");
    printf("%s \n",book.title);
    printf("%s \n",book.author);
    printf("%.2f \n",book.price);
    printf("%d-%d-%d\n",book.date.year,book.date.mouth,book.date.day);
    printf("%s \n",book.publisher);

    return 0;
}

======结构体数组,每个数组元素都是一个叫结构体
===定义的时候要加括号
struct Book{

}book[3];
or

struct Book book[3];
=== 定义 结构体指针
struct Book *ptr;
pt=&book;    //将ptr指向数组book

==通过结构体指针来访问结构体成员的方法/2种方法
1.  (*ptr).price  //==book.price 先解引用
因为.的运行等级高于* ,所以先(* )再.
2. ptr->成员名, ->前面是指针

#include <stdio.h>
#include <stdio.h>
struct Date{
    int year;
    int mouth;
    int day;
};
struct Book
{
    char title[128];
    char author[40];
    float price;
    struct Date date;
    char publisher[40];
}book={                 ///初始化
        "nihao wolaile",
        "zhang jiawei",
        48.8,
        {2017,8,15},
        "xibeigongyedaxue"
};
int main()
{
    struct Book *ptr;        //多多注意
    ptr=&book;              //用指针指向结构体book
    printf("===input is ready=====\n");
    printf("%s \n",ptr->title);
    printf("%s \n",ptr->author);
    printf("%.2f \n",ptr->price);
    printf("%d %d %d\n",ptr->date.year,ptr->date.mouth,ptr->date.day); //通过->来解引用
    printf("%s \n",ptr->publisher);

    return 0;
}
===两个结构体类型一致的话可以用结构体对结构体赋值
///================多使用函数可以大大减少main函数里面的代码量，而且运行速度快
///================注意&的使用
#include <stdio.h>
#include <stdio.h>
struct Date{
    int year;
    int mouth;
    int day;
};
struct Book
{
    char title[128];
    char author[40];
    float price;
    struct Date date;
    char publisher[40];
};
struct Book getinput(struct Book book)   //因为输出为struct类型，所以函数为struct 类型
{
    printf("please input book title\n");
    scanf("%s",book.title);
    printf("please input book author\n");
    scanf("%s",book.author);
    printf("please input book price\n");
    scanf("%f",&book.price);           //记得加地址符，这里是数字
    printf("please input book date\n");
    scanf("%d-%d-%d",&book.date.year,&book.date.mouth,&book.date.day);
    printf("please input book publisher\n");
    scanf("%s",book.publisher);

    return book;
}
void output(struct  Book book)   //output 函数
{
    printf("%s\n",book.title);
    printf("%s\n",book.author);
    printf("%f\n",book.price);           //记得加地址符，这里是数字
    printf("%d-%d-%d\n",book.date.year,book.date.mouth,book.date.day);
    printf("%s\n",book.publisher);
}

int main()
{
    struct Book book1,book2;
    printf("please input the first  book1 message:\n");
    book1=getinput(book1);
    printf("please input the second  book2 message:\n");
    book2=getinput(book2);
    printf("=====input is ready,now output the message\n");
    printf("=====output the first book message\n");
    output(book1);
    printf("=====output the second book message\n");
    output(book2);
    return 0;
}
////////使用指针可以简化代码内容

用指针来修改结构体内容
#include <stdio.h>
#include <stdio.h>
void *getinput(struct Book *book);   //指针函数,调用用指针调用函数就行   函数的声明
void *output(struct Book *book);      //函数的声明  

struct Date{
    int year;
    int mouth;
    int day;
};
struct Book
{
    char title[128];
    char author[40];
    float price;
    struct Date date;
    char publisher[40];
};
void *getinput(struct Book *book)   //指针函数,调用用指针调用函数就行，函数的参数为struct类型的指针
{
    printf("please input book title\n");
    scanf("%s",book->title);                 //这里的book是指针
    printf("please input book author\n");
    scanf("%s",book->author);
    printf("please input book price\n");
    scanf("%f",&book->price);           //记得加地址符，这里是数字
    printf("please input book date\n");
    scanf("%d-%d-%d",&book->date.year,&book->date.mouth,&book->date.day);
    printf("please input book publisher\n");
    scanf("%s",book->publisher);
}
void *output(strcut Book *book)   //output 函数
{
    printf("%s\n",book->title);
    printf("%s\n",book->author);
    printf("%f\n",book->price);           //记得加地址符，这里是数字
    printf("%d-%d-%d\n",book->date.year,book->date.mouth,book->date.day);
    printf("%s\n",book->publisher);
}

int main()
{
    struct Book book1,book2;
    printf("please input the first  book1 message:\n");
    getinput(&book1);
    printf("please input the second  book2 message:\n");
    getinput(&book2);
    printf("=====input is ready,now output the message\n");
    printf("=====output the first book message\n");
    output(&book1);
    printf("=====output the second book message\n");
    output(&book2);
    return 0;
}

//动态申请结构体内存空间
//
int main()
{
    struct Book *book1,*book2;  //定义两个struct类型的指针
    book1=(struct Book *)malloc(sizeof(struct Book));
    
    //malloc 函数先申请一个book类型的结构体大小的内存空间，然后将
    //这个转换成struct Book类型的指针
    book2=(struct Book *)malloc(sizeof(struct Book));
    if(book1==NULL||book2==NULL)
    {
        printf("内存分配失败！")；
        exit(1);
    }
    free(book1);
    free(book2);
    return 0;
}

//////通过指针来写入结构体数组信息
#include <stdio.h>
#include <stdlib.h>
struct Date{
    int year;
    int mouth;
    int day;
};
struct Book
{
    char title[128];
    char author[40];
    float price;
    struct Date date;
    char publisher[40];
};
void *getinput(struct Book *book)   //因为输出为struct类型，所以函数为struct 类型
{
    printf("please input book title\n");
    scanf("%s",book->title);
    printf("please input book author\n");
    scanf("%s",book->author);
    printf("please input book price\n");
    scanf("%f",&book->price);           //记得加地址符，这里是数字
    printf("please input book date\n");
    scanf("%d-%d-%d",&book->date.year,&book->date.mouth,&book->date.day);
    printf("please input book publisher\n");
    scanf("%s",book->publisher);

    return book;
}
void *output(struct  Book *book)   //output 函数
{
    printf("%s\n",book->title);
    printf("%s\n",book->author);
    printf("%f\n",book->price);           //记得加地址符，这里是数字
    printf("%d-%d-%d\n",book->date.year,book->date.mouth,book->date.day);
    printf("%s\n",book->publisher);
}

int main()
{
    struct Book *book1,*book2;   //定义两个struct类型的指针
    book1=(struct Book *)malloc(sizeof(struct Book));
    book2=(struct Book *)malloc(sizeof(struct Book));
    getinput(book1);
    getinput(book2);
    printf("input is ready ! now output:  \n");
    output(book1);
    output(book2);
    free(book1);
    free(book2);
    return 0;

}

//////动态定义结构体数组 /////图书馆信息录入程序
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Book)
struct Date{
    int year;
    int mouth;
    int day;
};
struct Book
{
    char title[128];
    char author[40];
    float price;
    struct Date date;   ////////
    char publisher[40];
};
void getinput(int *p,struct Book *book)   //因为输出为struct类型，所以函数为struct 类型
{
    for (int i=0;i<(*p);i++)
    {
    printf("now is input %d book: \n",i+1);
    printf("please input book title\n");
    scanf("%s",book[i].title);
    printf("please input book author\n");
    scanf("%s",book[i].author);
    printf("please input book price\n");
    scanf("%f",&book[i].price);           //记得加地址符，这里是数字
    printf("please input book date\n");
    scanf("%d-%d-%d",&book[i].date.year,&book[i].date.mouth,&book[i].date.day);
    printf("please input book publisher\n");
    scanf("%s",book[i].publisher);
    }
    // return book;
}
void output(int *p,struct  Book *book)   //output 函数
{
    for(int i=0;i<(*p);i++)
    {   
        printf("now is output %d book message \n",i+1);
        printf("%s\n",book[i].title);
        printf("%s\n",book[i].author);
        printf("%f\n",book[i].price);           //记得加地址符，这里是数字
        printf("%d-%d-%d\n",book[i].date.year,book[i].date.mouth,book[i].date.day);
        printf("%s\n",book[i].publisher);
    }
}

int main()
{   
    int num0=0; //动态结构体数组,
    int i,*p=&num0;
    printf("please input the book num: \n");
    scanf("%d",&num0);
    struct Book *book1=(struct Book *)malloc(num0*LEN);   //定义两个struct类型的指针
    getinput(p,book1);
    printf("input is ready ! now output:  \n");
    output(p,book1);
    free(book1);
    return 0;
}

======单链表
基本数据结构，根据需求，链表的出现弥补了数组的先天不足
head 指针--> 信息域 --> 信息域 --> 信息域 --> NULL指针
struct Book
{
    char title[128];        //信息域
    char author[40];        //信息域
    struct Book *next;    //--> 单链表
}
//头插法
//h




======typedef  起别名 最重要的关键字之一，是对类型的封装

typedef int integer,*PTRINT;   PTRINT int *  指针
#define intrger int  //不是语句 不用加分号

%u  无符号 

==定义指针变量的时候 
#include <stdio.h>
typedef int integer;
typedef int *PRINT;
int main()
{   
    integer a=5;
    PRINT b;
    b=&a;
    printf("%p",b);
    printf("%p",&a);

    return 0;
}
================结构体与typedef 结合
#include <stdion.h>
#include <stdlib.h>
typedef struct Date
{
    int year ;
    int mouth ;
    int day ;
} DATE,*PDATE;
//将struct Date 的别名为DATE,PDATE是指向该类型的指针,是struct *
void *strprint(PDATE date)
{
    printf("%d-%d-%d\n",date->year,date->mouth,date->day);
}
int main()
{
    struct Date *date;  //定义date为指向结构体的指针
    date=(struct Date *)malloc(sizeof(struct Date));

    date=(PDATE)malloc(sizeof(DATE));

    date->year=1950;
    date->mouth = 12;
    date->day=5;
    strprint(date);
    return 0;
}

==========进阶typedef 
//一给变量起一个容易记住的别名
//简化一些复杂的类型声明
//

===============共用体
union g共用体名称
{
    共用体成员1;
    共用体成员2;
    共用体成员3;

};
#include <stdio.h>
#include <strings.h>
struct Test
{
     int i;
     double pi;
     char str[40];
};
int main()
{
    struct Test test;
    test.i=12;
    test.pi=3.15;
    strcpy(test.str,"nihao"); // 需要string.h函数
    printf("address  union .i =%p\n",&test.i);
    printf("test.i = %d \n",test.i);
    printf("test.pi = %f \n",test.pi);
    printf("test.str = %s \n",test.str);
    return 0;
}
=======打印出来地址是一样的 ，说明共用体的存储地址是一样的
//不能同时打印它们的地址
#include <stdio.h>
#include <strings.h>
union Test
{
     int i;
     double pi;
     char str[40];
};
int main()
{
    union Test test;
    union Test a,b,c;
    test.i=12;
    test.pi=3.15;
    strcpy(test.str,"nihao"); // 需要string.h函数
    printf("address  union .i =%p\n",&test.i);
    printf("test.i = %p \n",&test.i);
    printf("test.pi = %p \n",&test.pi);
    printf("test.str = %p \n",&test.str);
    printf("test.i = %d \n",test.i);
    printf("test.pi = %.2f \n",test.pi);
    printf("test.str = %s \n",test.str);
    
    return 0;
}
//只有第三个正确,三个成员只用一个地址，只有最后一个地址赋值的
//才正确,所以%s正确，大家共用一个地址，所以每次只能用一个

//初始化共用体：每次只初始一个
union Date date
{
    int year;
    int mouth;
    char title[40];
};
union Date a,b,c;
union Date a={520};
union Date b={.title ="ni hao"};


===宏定义 + 结构体函数
#include <stdio.h.>
#include <time.h>

#define SUM 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
 
int main(void)
{
    struct tm *p;   
    //结构体 指针p
    //time.h里面有这个结构体tm
    time_t t;   //time_t long ling time_t 类型,

    t=time(&t);   
    //time   time_t time(time_t *timer)  //long long int 类型
    //返回距离1970-1-1后的秒
    //localtime  struct time *licaltime(condt time_t *timer)
    //返回一个以tm结构表达的机器时间信息
    p=localtime(&t);   // 返回结构体指针 p 
    switch(p->tm_wday)    //结构体中的成员  一周中的第几天
    //p->tm_wday 返回 0-6 周末 0 开始
    {
        case MON:
        case TUE:
        case WED:
        case THU:
        case FRI:
            printf("work!\n");
            break;
        case SAT:
        case SUM:
            printf("rest!\n");
            break;
        default:
            printf("error1\n");     
    }
    printf("today is %d",p->tm_mday);
    return 0;
}

===枚举类型
enum 枚举类型名称 枚举值名称1,枚举值名称2;
enum week {one,two=3,three,four,five};
          //(0,3,4,5,6)
enum week today //定义枚举变量


#include <stdio.h>
#include <time.h>
int main()
{
    enum week {sun,mon,tue,wed,thu,fri,sat};//定义枚举类型
    //默认为int 类型 从0开始，第一个枚举成员的默认值为整型的0；
    //后面的枚举成员在前一个成员+1
    //{0,1,2,3,4,5,6};
    enum week today;  //today 定义枚举变量
    struct tm *p;
    time_t t;
    
    time(&t);
    p=localtime(&t);
    today =p->tm_wday;
    switch(today)
    {
        case mon:
        case tue:
        case wed:
        case thu:
        case fri:
            printf("work!\n");
            break;
        case sat:
        case sun:
            printf("rest!\n");
            break;
        default:
            printf("error!\n");
    }
    return 0;
}

====枚举 中间定义
#include <stdio.h>
int main()
{
    enum color {red,blue=9,green};
    enum color rgb;
    //int 类型
    printf("red  = %d \n",red);
    printf("blue = %d \n",blue);
    printf("green= %d \n",green);
    
    return 0;
}

===位域 单片机开发领域
51 单片机 大小 256b  一个字节 8bit 一个struct 类型指针 4字节
//     二进制： 32bit 
 1 1 1 0    1 0    1 1
  a         b      c
/*位域 相当于把一个字节拆开使用 在结构体定义的时候，在结构体
成员后面使用冒号：和 num 来表示该成员所占的位数*/

#include <stdio.h>
int main()
{
    struct Test
    {
        unsigned int a:1;  //unsigned 无符号
        unsigned int b:2;
        unsigned int c:3;
    };
    struct Test test;
    test.a=1;
    test.b=3;
    test.c=5;
    printf("a=%d b=%d c=%d \n",test.a,test.b,test.c);
    return 0;
}

位域：可以支持 char int 枚举类型

======逻辑位运算符 对二进制 运算  
~ 取反   ：1~ =0
& 与     ：全 1 为 1 ，不同为 0
^ 异或   ：不同为1 .相同为 0
| 或     ：全 0 为 0 ，有 1 为 1
======逻辑运算符  操作对象为整形
&&  与   :
||  或   :
!   非   :

===========%x 十六进制打印出来
===========%d 十进制打印
===========%u 无符号打印出来
===========%f 小数打印
进制：
    十进制  ： 
    八进制  ：以0开头 0123 =1*8^2+2*8+3=83
    十六进制：以0x开头，紧跟0~9,a~f,A~F,等表示十六进制
#include <stdio.h>
int main()
{
    int mask=0xf0;
    printf("0xff    =   %d \n",mask);
    int v1=0xabcdef;
    printf("0xabcdef=   %d \n",v1);
    v1=v1&mask;
    printf("0xabcdef=   %d \n",v1);
    int v2=0x01;
    printf("0xabcdef=   %d \n",v2);
    v2=v2|mask;
    printf("0xabcdef=   %d \n",v2);
    return 0;
}

===移位运算符
 11001010 << 1  左移两位，后面补0  ，*2^1
 00101000
 11001010 >> 2  右移两位 前面补0     /2^2
 00110010
最后 1>>2 = 0
//移位的效率高于运算
//有符号数 左边第一位是符号位 ，移动之后可能改变符号

#include <stdio.h>
int main()
{
    int a=1024,b=-1024;
    while(a>0)
    {
        a=a>>2;
        printf("a=%d \n",a);
    }
    while(b<-2)    //这里仍然可以保留符号位进行左移和右移
    {
        b=b>>1;
        printf("b=%d \n",b);
    }
    return 0;
}

======逻辑位运算的应用
确认某一位打开     掩码  &
打开位            掩码  |   
关闭位            掩码  ~ &
转置位            掩码  ^  对某一位取反

确认打开: 1 1 0 0 1 0 0 0
掩码&  ： 0 0 0 0 1 0 0 0  //要确定哪一位打开
         0 0 0 0 1 0 0 0

打开位:  1 1 0 0 1 0 0 0
|运算    0 0 0 0 0 0 1 0  //表示对哪一位下手
         1 1 0 0 1 0 1 0

关闭位:  1 1 0 0 1 0 0 0
掩码：   0 1 0 0 0 0 0 0  //表示对哪一位下手
取~ ：   1 0 1 1 1 1 1 1
&运算：  1 0 0 0 1 0 0 0  对第二位运算

转置位 : 1 1 0 0 0 0 0 1
掩码   : 0 1 0 0 1 0 0 0  //表示对哪个下手
^     :  1 0 0 0 1 0 0 1  //不同为1，相同为0

掩码和逻辑位运算的使用：
if((value&mask)== mask)
{
    printf("open !"); 
}

================文件操作 输入->处理->输出
.exe   .txt  .ppt=====万物皆文件
==文本文件和二进制文件

=====打开文件 必须关闭文件
=====处理的是二进制文件， "rb" "rw"
fopen() 打开一个文件，并返回file结构的文件指针


fclose() 

#include <stdio.h>
#include <stdlib.h>
FILE *fp;

fp=fopen("hello.txt","r");
fclose(fp);         //
==顺序读写  从头开始
==随机读写  

单个字符的文件读取：
fgetc()  //输入 file 类型的指针  错误的话返回EOF;
getc()   //宏实现 速度快

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //写入文件内容
    FILE *fp; // 定义一个文件指针
    fp=fopen("file.txt","w+"); //创建一个用于读写的文件,会覆盖
    fprintf(fp,"%s","we are the world"); //fprintf 给文件写入
    fclose(fp);
    //查看文件
    int c;
    fp=fopen("file.txt","r"); //r只读
    //feof 遇到标识符结束时返回0 ，否则返回非0
    while(1)
    {
        c=fgetc(fp);  //没有错误则返回一个字符,
        //错误情况下返回EOF，
        if(feof(fp))
            break;
        printf("%c",c);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int c;
    int n=0;
    fp=fopen("file.txt","w+");
    fprintf(fp,"%s","we are the world");  //这个也可以写入
    fclose(fp);
    fp=fopen("file.txt","r"); //创建一个写入文件
    if(fp==NULL)
    {
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        c=fgetc(fp);
        if(feof(fp))
            break;
        printf("%c",c);
    }
    return 0;
}


单个字符的给文件写入：
fputc()  //函数
putc()   //宏

#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int ch;
    fp=fopen("file.txt","a+");
    for(ch=33;ch<=100;ch++)
    {
        fputc(ch,fp);   //给文件写入
    }
    fclose(fp);
    //读取文件内容
    fp=fopen("file.txt","r");
    while(1)
    {
        ch=fgetc(fp);
        if(feof(fp))
            break;
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}

从文件中读取整个字符串,并返回一个str类型的指针,当读取(n-1)个字符时，或
换行符时，或文件末尾就会停止



fgets()   //size-1 个字符  从文件拿出 
        char *fgets(char *str, int n, FILE *stream)
    //三个输入 
fputs()   //              从文件写入一个字符串
        int fputs(const char *str, FILE *stream)   

puts()    //从标准输出拿一个字符串          //读出
        int puts(const char *str)
puts(str);
gets()    //从标准输入拿读取相应字长的字符串 //读入
        int gets(const char *str)

char str[20];
gets(srt);   //从标准输入读取20个字符

#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int ch;
    fp=fopen("file.txt","a+");
    for(ch=33;ch<=100;ch++)
    {
        fputc(ch,fp);   //
    }
    fclose(fp);
    //读取文件内容
    fp=fopen("file.txt","r");
    if(fp==NULL)
    {
        exit(EXIT_FAILURE);
    }
    char str[25];
    if(fgets(str,25,fp)!=NULL)
    {
       puts(str);
    }
    return 0;
}

"r"：只能从文件中读数据，该文件必须先存在，否则打开失败
"w"：只能向文件写数据，若指定的文件不存在则创建它，如果存在则先删除它再重建一个新文件
"a"：向文件增加新数据(不删除原有数据)，若文件不存在则打开失败，打开时位置指针移到文件末尾
"r+"：可读/写数据，该文件必须先存在，否则打开失败
"w+"：可读/写数据，用该模式打开新建一个文件，先向该文件写数据，然后可读取该文件中的数据
"a+"：可读/写数据，原来的文件不被删去，位置指针移到文件末尾


#include <stdio.h>
#include <stdlib.h>

#define max 512
int main()
{   //给文件写入字符串
    FILE *fp;
    fp=fopen("file.txt","w");  //w 如果原文件存在，则删除后重新创建一个
    if(fp==NULL)
    {
        exit(EXIT_FAILURE);
    }
    fputs("line one: you are my sunshine\n",fp);
    fputs("line two: you make me happy\n",fp);
    fputs("line three: you make me relax\n",fp);
    fputs("line four:you are the beautiful\n",fp);
    fclose(fp);
    //给文件读出 fgets函数
    char str[max];
    fp=fopen("file.txt","r");
    if(fp==NULL)
    {
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        fgets(str,max,fp);  //没有读入任何字符就遇到 eof ,则str指向上一次的内容，eof是文件的结尾
        //fgets 返回指针
        if(feof(fp))   //feof 遇到标识符结束时返回0 ，否则返回非0
            break;    
        printf("%s",str);
    }
    return 0;
}

=====fscanf()  //给指定文件进行输入和输出
=====fprintf();
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{  
    FILE *fp;
    struct tm *p;
    time_t t;

    time(&t);  //调用time函数 返回经过1970-01-01 开始经过的秒数
    p=localtime(&t);
    if((fp=fopen("file.txt","w"))==NULL)
    {
       printf("open the file faile!");
       exit(EXIT_FAILURE);
    }
    fprintf(fp,"%d-%d-%d%s",1900+p->tm_year,1+p->tm_mon,p->tm_mday,"you are the sunshine");
    fclose(fp);

    int year,mouth,day;
    char str;
    fp=fopen("file.txt","r");
    if (fp==NULL)
    {
        printf("error");
        exit(EXIT_FAILURE);
    }
    fscanf(fp,"%d-%d-%d",&year,&mouth,&day);

    //给变量读取字符串,并输入到对应的地址去
    printf("%d-%d-%d\n",year,mouth,day);
    while(1)
    {
        str=fgetc(fp);
        if(feof(fp))
            break;
        printf("%c",str);
    }
    fclose(fp);
    return 0;
}