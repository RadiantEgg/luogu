# C语言学习笔记

## 目录
-[学习日志](#-学习日志)

-[代码技巧库](#-代码技巧库)

-[待办计划](#-待办计划)

---

## 学习日志

### 2026.2.19&20
**今日学习**
- 复习了数组，完成alphabet_04

**今日心得**

1.库函数`memset`

- 函数原型：
```c
#include<string.h>
void *memset(void *s,int c,size_t n);//虽然是int，但是实际是char
```
- 用法
```c
//初始化数组
char str[10];
memset(str,'A',sizeof(str));//字符数组初始化
int arr[10];
memset(arr,0,sizeof(arr));//整型数组初始化
memset(arr,-1,sizeof(arr));
```
- 是按**字节**设置初始化的个数的，不是输入的数字
```c
memset(arr,0,10);//❌只设置了前一百个字节为0
memset(arr,0,sizeof(arr));//✔设置了所有的字节
```
- **只能初始化为0或-1**
- 用途：初始化字符串，清零数组，重置结构体，设置标志数组{-1}

2.换行输出
- 多行宏换行：`\`
- printf字符串换行：`""`
```c
printf("hello,"
        "world"
        "!");
```
- 剩下的都可以直接换行

3.0_base与1_base的转换
- 除了特别有实际生活意义的用1_base，剩下都用0_base
- 如果用0_base但是输入1_base，**要-1**

4.多重循环找到即跳出，设置标志found=0
- 找到found=1，在循环条件里判断
```c
 for(i=0;i<a&&!found;i++){
    for(j=0;j<b&&!found;j++){
        if(){
            found=1；
        }//寻找
    }
}
```
5.哈希表：一种数据结构，比如二维数组初始化为0，若某个位置有数则置为1

6.滑动窗口
- 固定窗口
    - 长度固定
    - 用left和right卡住窗口，每次丢掉left，新增right，再判断
    - 模板
```c
//数组a，长度n，窗口大小k
int left=0;
int window_sum=0;
//先计算第一个窗口大小
for(i=0;i<k;i++){
    window_sum+=a[i];
}
int ans=window_sum;
//开始滑动
for(int right=k;right<n;right++){
    //移除左边，加入右边
    ans=window_sum-a[right-k]+a[right];
    if(ans<window_sum)
        window_sum=ans;
}
```
- 可变窗口
    - 窗口大小会变
    - 每次用right扩大窗口，再用left缩小窗口
    - 模板(求满足条件最小长度)
```c
//数组a，长度n，目标条件condition()
int left=0;
int ans=  //最大或最小
for(int right=0;right<n;right++){
    //若窗口满足，尝试缩小
    while(condition()&&left<=right>){
    //更新ans
    ans=min(ans,right-left+1);
    //更新窗口
    left++;  
    }
}
```
7.开关转换用！`flag=0    !flag`

8.大的数组放在全局，栈装不下
```c
#include<stdio.h>
#define N 2000000
int a[N]={0};
int main(){
    ······
}
```

9.命名惯例：ans,res,sum,cnt,tmp,cur


---
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

6.long long int 的输入输出
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
- [ ] 连续读取
- [ ] 字符串滑动窗口