
#include<stdio.h>
#define N 100
int main()
{
    int n,i,j;
    int fish[N]={0},count[N]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&fish[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if(fish[j]<fish[i]){
                count[i]++;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d%c",count[i],(i==n-1)?'\n':' ');
    }
    return 0;
}
//初始化

#include<stdio.h>
#define N 100
int main()
{
    int i,j;
    int a[N]={0};
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
        if(a[i]==0){
            i--;
            break;
        }
    }
    for(j=i;j>=0;j--){
        printf("%d%c",a[j],(j==0)?'\n':' ');
    }
    return 0;
}


#include<stdio.h>
#define MAX 1000
int main()
{
    int a[MAX]={0};
    int n,i,j;
    scanf("%d",&a[0]);
    if(a[0]==1){
        printf("1\n");
        return 0;
    }
    for(i=0;i<MAX;i++){
        a[i+1]=(a[i]%2==0)?a[i]/2:3*a[i]+1;
        if(a[i+1]==1){
            break;
        }
    }
    for(j=i+1;j>=0;j--){
        printf("%d%c",a[j],(j==0)?'\n':' ');
    }
    return 0;
}

#include<stdio.h>
#define N 10001
#define M 100
int main()
{
    int l,m,i,j,left=0;
    int start[M]={0},end[M]={0},tree[N]={0};
    scanf("%d%d",&l,&m);
    for(i=0;i<=l;i++){
        tree[i]=1;
    }
    for(i=0;i<m;i++){
        scanf("%d%d",&start[i],&end[i]);
    }
    for(i=0;i<m;i++){
        for(j=start[i];j<=end[i];j++){
            tree[j]=0;
        }
    }
    for(i=0;i<=l;i++){
        left+=tree[i];
    }
    printf("%d\n",left);
    return 0;
}

#include<stdio.h>
#include<math.h>
#define N 1000
int main()
{
    int n,i,j,count=0;
    scanf("%d",&n);
    int chinese[N]={0},math[N]={0},english[N]={0},sum[N]={0};
    for(i=0;i<n;i++){
        scanf("%d%d%d",&chinese[i],&math[i],&english[i]);
        sum[i]=chinese[i]+math[i]+english[i];
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(fabs(chinese[i]-chinese[j])<=5
            &&fabs(math[i]-math[j])<=5
            &&fabs(english[i]-english[j])<=5
            &&fabs(sum[i]-sum[j])<=5)
            {
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
//换行输出

#include<stdio.h>
#define N 20
#define M 100
int main()
{
    int x,y,z,q,i,j,k,w,count=0;
    int cube[N][N][N]={0};
    int cut[M][6]={0};

    scanf("%d%d%d%d",&x,&y,&z,&q);

    for(i=0;i<q;i++){
        for(j=0;j<6;j++){
            int temp;
            scanf("%d",&temp);
            cut[i][j]=temp-1;
        }
    }
    for(w=0;w<q;w++){
        for(i=cut[w][0];i<=cut[w][3];i++){
            for(j=cut[w][1];j<=cut[w][4];j++){
                for(k=cut[w][2];k<=cut[w][5];k++){
                    cube[i][j][k]=1;
                }
            }
        }
    }
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            for(k=0;k<z;k++){
                if(cube[i][j][k]==1){
                    count++;
                }
            }
        }
    }
    printf("%d\n",x*y*z-count);
    return 0;
}
//0_base和1_base的转换，在输入时用temp-1

#include<stdio.h>
#define N 1000
int main()
{
    int i,j,k,n,count=0;
    int prize[7]={0};
    int a[N][7]={0};
    int final[7]={0};
    scanf("%d",&n);
    for(i=0;i<7;i++){
        scanf("%d",&prize[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<7;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<7;j++){
            for(k=0;k<7;k++){
                if(prize[j]==a[i][k])
                    count++;
            }
        }
        final[count-1]++;
    }
    for(i=6;i>=0;i--){
        printf("%d%c",final[i],(i==0)?'\n':' ');
    }
    return 0;
}

#include<stdio.h>
#define N 39
int main()
{
    int n,i,j,num=1;
    scanf("%d",&n);
    int a[N][N]={0};
    a[0][(n+1)/2-1]=1;
    i=0;
    j=(n+1)/2-1;
    for(num=2;num<=n*n;num++){
        if(i==0&&j!=n-1){
            i=n-1;
            j++;
            a[i][j]=num;
        }
        else if(i==0&&j==n-1){
            i++;
            a[i][j]=num;
        }
        else if(j==n-1&&i!=0){
            j=0;
            i--;
            a[i][j]=num;
        }
        else{
            if(a[i-1][j+1]==0){
                i--;
                j++;
                a[i][j]=num;
            }
            else{
                i++;
                a[i][j]=num;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d%c",a[i][j],' ');
        }
        printf("\n");
    }
    return 0;
}

#include<stdio.h>
int num[10]={0};
void calculate(int n)
{
    while(n!=0){
        num[n%10]++;
        n/=10;
    }
}
int main()
{
    int m,n,i;
    scanf("%d%d",&m,&n);
    for(i=m;i<=n;i++){
        calculate(i);
    }
    for(i=0;i<10;i++){
        printf("%d%c",num[i],(i==9)?'\n':' ');
    }
    return 0;
}

#include<stdio.h>
#define N 1000
int main()
{
    int n,i,j,k,count=0,found=0;
    int a[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-1&&!found;j++){
            for(k=j+1;k<n&&!found;k++){
                if(a[j]+a[k]==a[i]){
                    count++;
                    found=1;
                    break;
                }
            }
        }
    }
    printf("%d\n",count);
    return 0;
}

//标志位在循环条件里！found不用跳出
//哈希表
#include<stdio.h>
#include<limits.h>
#define N 3000
int main()
{
    int n,m,i,j;
    long long int min=LLONG_MAX;
    long long int a[N]={0};
    scanf("%d%d",&n,&m);
    if(m==0||n==0){
        printf("0\n");
        return 0;
    }
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    if(n==m){
        min=0;
        for(i=0;i<n;i++){
            min+=a[i];
            printf("%lld\n",min);
            return 0;
        }
    }
    for(i=0;i<=n-m;i++){
        long long int ans=0;
        for(j=0;j<m;j++){
            ans+=a[i+j];
        }
        if(ans<min){
            min=ans;
        }
    }
    printf("%lld\n",min);
    return 0;
}
//滑动窗口

#include<stdio.h>
#include<limits.h>
#define N 3000

int main()
{
    int n, m, i;
    long long int a[N] = {0};
    
    scanf("%d%d", &n, &m);
    
    if(m == 0 || n == 0 ) {
        printf("0\n");
        return 0;
    }
    
    // 输入并计算第一个窗口
    long long int window_sum = 0;
    for(i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(i < m) {
            window_sum += a[i];  // 计算第一个窗口的和
        }
    }
    
    // 如果n == m，直接输出
    if(n == m) {
        printf("%lld\n", window_sum);
        return 0;
    }
    
    // 滑动窗口找最小
    long long int min = window_sum;
    for(i = m; i < n; i++) {
        // 窗口右移：加上新元素，减去最早的元素
        window_sum = window_sum + a[i] - a[i - m];
        if(window_sum < min) {
            min = window_sum;
        }
    }
    
    printf("%lld\n", min);
    return 0;
}
#include<stdio.h>
#define N 77
int main()
{
    int a,b,c,i,j,k,max=0,index=0;
    int times[78]={0};
    scanf("%d%d%d",&a,&b,&c);
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            for(k=0;k<c;k++){
                times[i+j+k]++;
            }
        }
    }
    for(i=0;i<a+b+c-2;i++){
        if(times[i]>max){
            max=times[i];
            index=i;
        }
    }
    printf("%d\n",index+3);
    return 0;
}


#include<stdio.h>
#define M 2000000
#define N 5000
int lights[M+2]={0};
int main()
{
    int n,i,j,k;
    double a[N]={0};
    int t[N]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lf%d",&a[i],&t[i]);
    }
    for(i=0;i<n;i++){
        for(j=1;j<=t[i];j++){
            double val=a[i]*j;
            int light_idx=(int)(val+1e-9);
            if(light_idx>=1&&light_idx<=M){
                lights[light_idx]=!lights[light_idx];
            }
        }
    }
    for(i=1;i<=M;i++){
        if(lights[i]==1){
            break;
        }
    }
    printf("%d\n",i);
    return 0;
}
//开关转换用！
//大数组放在全局
//+2多留冗余防止循环或索引越界

#include<stdio.h>
#define N 10
int main()
{
    int square[N][N]={0};
    square[1][1]=1;
    int n,num=2,i=1,j=1;
    scanf("%d",&n);
    while(num<=n*n){
        while(j<=n-1&&square[i][j+1]==0){
            j++;
            square[i][j]=num;
            num++;
        }
        while(i<=n-1&&square[i+1][j]==0){
            i++;
            square[i][j]=num;
            num++;
        }
        while(j>=2&&square[i][j-1]==0){
            j--;
            square[i][j]=num;
            num++;
        }
        while(i>=2&&square[i-1][j]==0){
            i--;
            square[i][j]=num;
            num++;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%3d",square[i][j]);
        }
        printf("\n");
    }
    return 0;
}

#include<stdio.h>
#define N 20
int main()
{
    int n,i,j;
    long long int a[N][N]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if(j==0||i==j){
                a[i][j]=1;
            }
            else{
                a[i][j]=a[i-1][j]+a[i-1][j-1];
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("%lld%c",a[i][j],(i==j)?'\n':' ');
        }
    }
    return 0;
}

#include<stdio.h>
#define N 101
#define T 25
#define S 5
int main()
{
    int n,m,k,i,j,w,x,y,monster=0;
    int a[N][N]={0};
    int torch[T][2]={0};
    int stone[S][2]={0};
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++){
        scanf("%d%d",&torch[i][0],&torch[i][1]);
    }
    for(i=0;i<k;i++){
        scanf("%d%d",&stone[i][0],&stone[i][1]);
    }
    for(i=0;i<m;i++){
        x=torch[i][0];
        y=torch[i][1];
        a[x][y]=1;
        if(x-1>=1)
            a[x-1][y]=1;
        if(x-2>=1)
            a[x-2][y]=1;
        if(x+1<=n)
            a[x+1][y]=1;
        if(x+2<=n)
            a[x+2][y]=1;  
        if(y-1>=1)
            a[x][y-1]=1;
        if(y-2>=1)
            a[x][y-2]=1;  
        if(y+1<=n)
            a[x][y+1]=1;
        if(y+2<=n)
            a[x][y+2]=1;
        if(x-1>=1&&y-1>=1)
            a[x-1][y-1]=1;
        if(x+1<=n&&y+1<=n)
            a[x+1][y+1]=1;
        if(x-1>=1&&y+1<=n)
            a[x-1][y+1]=1;
        if(x+1<=n&&y-1>=1)
            a[x+1][y-1]=1;
    }
    for(i=0;i<k;i++){
        x=stone[i][0];
        y=stone[i][1];
        for(j=x-2;j<=x+2;j++){
            for(w=y-2;w<=y+2;w++){
                if(j>=1&&j<=n&&w>=1&&w<=n)
                    a[j][w]=1;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i][j]==0)
                monster++;
        }
    }
    printf("%d\n",monster);
    return 0;
}

#include<stdio.h>
#define N 40000
int main()
{
    int n,i,j,flag=0,count=0;
    int a[N]={0};
    scanf("%d",&n);
    for(i=0;count<n*n;i++){
        scanf("%d",&a[i]);
        count+=a[i];
    }
    count=0;
    for(i=0;count<n*n;i++){
        for(j=0;j<a[i];j++){
            printf("%d",flag);
            count++;
            if(count%n==0)
                printf("\n");
        }
        flag=1-flag;
    }
    return 0;
}
//连续读取

#include<stdio.h>
#include<math.h>
#define N 40000
int main()
{
    int n,i=0,j,index=0,flag=0,count=0;
    char c;
    int input[N]={0},zip[N]={0};
    while((c=getchar())!='\n'){
        input[i++]=c-'0';
        index++;
    }
    n=index;
    for(i=1;i<n;i++){
        for(j=0;j<n;j++){
            c=getchar();
            input[i*n+j]=c-'0';
        }
        getchar();
    }
    index=0;
    i=0;
    while(i<n*n-1){
        if(i==0){
            if(input[i]==1){
                zip[index++]=0;
                flag=1;
            }
        }
        if(input[i+1]==flag){
            count++;
        }
        else{
            zip[index++]=count+1;
            flag=1-flag;
            count=0;
        }
        i++;
    }
    zip[index++]=count+1;
    printf("%d ",n);
    for(i=0;i<index;i++){
        printf("%d%c",zip[i],(i==index)?'\n':' ');
    }
    return 0;
}
//字符串更好


//求满足和>10的最小连续数长度
