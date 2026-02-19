# C语言学习笔记

## 目录
-[学习日志](#-学习日志)

-[代码技巧库](#-代码技巧库)

-[待办计划](#-待办计划)

---

## 学习日志

### 2026.2.18
**今日学习**
- 上传了alphabet_03
- 配置了launch.json并学会了调试

**今日心得**

1.计算两个整数相除的浮点类型结果要**强制类型转换**

```c
int a,b;
double result;
result=(double)a/b;
```

2.前导零格式%0nd

3.注意溢出

    - int大约10位

    - 阶乘：12！正常，13！溢出

    - 累加很多数：斐波那契
4.头文件<limits.h>可以用来初始化min和max
```c
#include<limits.h>
int min=INT_MAX;//找最大值用最小值初始化
int max=INT_MIN;//找最小值用最大值初始化
```

5.命名规范

| 后缀 | 类型 |
| :---: | :---: |
| _val | 数值 |
| _ptr | 指针 |
| _idx | 索引 |
| _cnt | 计数 |
| _flag | 标志位 |
| _buf | 缓冲区 |
7.long long int 的输入输出
```c
long long int a;
scanf("%lld",&a);
printf("%lld",a);
```

---

### 2026.2.17
**今日学习**
- 今天学习了markdown的基本语法
- 学会了怎么在GitHub上上传文件，并把我的alphabet_01上传到自己创建的repository里
- 把alphabet_02和LearningNotes一起上传到GitHub

**今日心得**

1.浮点数除法一定要记得加.0   

`
result=500.0/3;
`

2.两数相除，向上取整
```c
result=a/b;
if(a%b!=0)
    result+=1;
//a/b上取整=a+b-1/b下取整
result=(a+b-1)/b;
```
3.多行宏定义 

    - 每行末尾用\换行
    - 因为宏在写的时候会习惯性加分号，所以宏在定义时用do{}while{0}封装
    - 所有参数加括号，表达式加括号
    - 避免++这样的重复运算
```c
//比大小
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
//交换
#define SWAP(a,b) do{\
    int temp=a;\
    a=b;\
    b=temp;\
}while(0)
```
4.三元运算符返回字符串加双引号

`char name=(a>b)?"Eric":"Egg";`

5.读取%c注意空白字符(空格跳过)

`scanf(" %c",&ch);`

6.日期与数组结合使用
    
`int months[13]={0,1,2,3,4,5,6,7,8,9,10,11,12};`

7.读入字符串的特定部分一般用两个数组，再用index处理
```c
char input[100];
char want[100];
int index;
want[index++]=input[i];
```
8.辗转相除法求a和b的最大公约数
```c
//欧几里得
int r;
while(b!=0){
    r=a%b;
    a=b;
    b=r;
}
return a;
//递归
int gcd(int a,int b)
{
    return(b==0)?a:gcd(b,a%b);
}
//最小公倍数lcm*gcd=a*b
int lcm=a*b/gcd(a,b);
```

---

## 代码技巧库

### 输入输出技巧

### 循环技巧

### 数组技巧

### 字符串技巧

## 待办计划

- [ ] 位运算
- [ ] 排序
- [ ] 大数运算器
- [ ] 桶排序
- [ ] 高精度算法
- [ ] 素数筛