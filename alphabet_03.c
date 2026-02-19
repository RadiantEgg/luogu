
#include<stdio.h>
int main()
{
    int n,i,min=1000;
    int num[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
        if(num[i]<min)
            min=num[i];
    }
    printf("%d\n",min);
    return 0;
}
//桶排序

#include<stdio.h>
int main()
{
    int n,k,i,count_a=0,sum_a=0,count_b=0,sum_b=0;
    float ave_a,ave_b;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        if(i%k==0){
            count_a++;
            sum_a+=i;
        }
        else{
            count_b++;
            sum_b+=i;
        }
    }
    ave_a=(double)sum_a/count_a;
    ave_b=(double)sum_b/count_b;
    printf("%.1f %.1f\n",ave_a,ave_b);
    return 0;
}
//强制转换

#include<stdio.h>
int main()
{
    int a,i=1;
    scanf("%d",&a);
    while(a>1){
        a/=2;
        i++;
    }
    printf("%d\n",i);
    return 0;
}

//前导零

//高精度算法
#include<stdio.h>
int main()
{
    int n,x,i,num,count=0;
    scanf("%d%d",&n,&x);
    for(i=1;i<=n;i++){
        num=i;
        while(num){
            if(num%10==x)
                count++;
            num/=10;
        }
    }
    printf("%d\n",count);
    return 0;
}

#include<stdio.h>
int main()
{
    int k,i;
    double sum=0;
    scanf("%d",&k);
    for(i=1;sum<=k;i++){
        sum+=1.0/i;
    }
    printf("%d\n",i-1);
    return 0;
}

#include<stdio.h>
int main()
{
    int k,count=0,n,i;
    scanf("%d",&k);
    for(i=1;i*(i+1)/2<=k;i++);
    i--;
    for(int k=1;k<=i;k++){
        count+=k*k;
    }
    count+=(k-i*(i+1)/2)*(i+1);
    printf("%d\n",count);
    return 0;
}

#include<stdio.h>
int main()
{
    int i,n,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum+=i;
    }
    printf("%d\n",sum);
    return 0;
}

#include<stdio.h>
#include<math.h>
int is_prime(int n)
{
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int l,i,count=0,sum=0;
    scanf("%d",&l);
    for(i=2;;i++){
        if(is_prime(i)==1){
            if(sum+i<=l){
                sum+=i;
                count++;
                printf("%d\n",i);
            }
            else    
                break;
        }
    }
    printf("%d\n",count);
    return 0;
}
//素数筛，欧拉筛，埃筛

#include<stdio.h>
int main()
{
    int i;
    float s,l=0,a=2.0;
    scanf("%f",&s);
    for(i=1;l<s;i++){
        l+=a;
        a*=0.98;
    }
    printf("%d\n",i-1);
    return 0;
}

#include<stdio.h>
#include<math.h>
int main()
{
    int n,a;
    scanf("%d",&n);
    if(n==0){
        printf("0\n");
        return 0;
    }
    if(n<0){
        printf("-");
    }
    a=fabs(n);
    while(a%10==0){
        a/=10;
    }
    while(a!=0){
        printf("%d",a%10);
        a/=10;
    }
    return 0;
}

#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    if(n==0){
        printf("0.00\n");
        return 0;
    }
    long long int a[49]={0};
    a[1]=1;
    a[2]=1;
    for(i=3;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    printf("%.2f\n",(double)a[n]);
    return 0;
}
//溢出

#include<stdio.h>
int main()
{
    int n,min=1000,max=0,i;
    scanf("%d",&n);
    int num[100]={0};
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
        if(num[i]<min){
            min=num[i];
        }
        if(num[i]>max){
            max=num[i];
        }
    }
    printf("%d\n",max-min);
    return 0;
}

#include<stdio.h>
int main()
{
    int n,i,len=0,count=0,index;
    long long int a[10000]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=0;i<n;){
        for(index=0;index+i+1<n&&a[index+i]+1==a[index+i+1];index++);
        if(index+1>len){
            len=index+1;
        }
        i+=index+1;
    }
    printf("%d\n",len);
    return 0;
}
//max初始化为-INF

#include<stdio.h>
#include<limits.h>
int main()
{
    int n,ans=1,i,max=INT_MIN;
    int a[10000]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        if(a[i+1]-a[i]==1){
            ans++;
        }
        else{
            ans=1;
        }
        if(ans>max){
            max=ans;
        }
    }
    printf("%d\n",max);
    return 0;
}
//库函数#include<limits.h>    遍历断点的思路

#include<stdio.h>
#include<math.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int i;
    if(n==1||n==2||n==3){
        printf("%d\n",n);
        return 0;
    }
    for(i=2;i<=sqrt(n);i++){
        if(n%i==0){
            break;
        }
    }
    printf("%lld\n",n/i);
    return 0;
}
//越界
//lld的输入输出

#include<stdio.h>
int main()
{
    int n,i,j,num=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%02d",(i-1)*n+j);
        }
        printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            printf("  ");
        }
        for(j=n-i+1;j<=n;j++){
            printf("%02d",num);
            num++;
        }
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int n,max=0,min=10,sum=0;
    float ave;
    int a[1000]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        if(a[i]<min){
            min=a[i];
        }
        if(a[i]>max){
            max=a[i];
        }
    }
    ave=(double)(sum-min-max)/(n-2);
    printf("%.2f\n",ave);
    return 0;
}

#include<stdio.h>
int main()
{
    int n,i,j,sum;
    scanf("%d",&n);
    sum=n/52/7;
    for(i=1;;i++){
        for(j=1;3*i+j<sum;j++);
        if(3*i+j==sum&&j<=100){
            break;
        }
    }
    printf("%d\n%d\n",j,i);
    return 0;
}

#include<stdio.h>
int main()
{
    int a[13]={0},left[13]={0},deposit[13]={0};
    int i,total;
    for(i=1;i<13;i++){
        scanf("%d",&a[i]);
        deposit[i]=(300+left[i-1]-a[i])/100*100;
        left[i]=300+left[i-1]-a[i]-deposit[i];
    }
    for(i=1;i<13;i++){
        if(left[i]<0){
            break;
        }
    }
    if(i==13){
        int sum=0;
        for(int j=1;j<13;j++){
            sum+=deposit[j];
        }
        total=sum*1.2+left[12];
        printf("%d\n",total);
    }
    else{
        printf("-%d\n",i);
    }
    return 0;
}