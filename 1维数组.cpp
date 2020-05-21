/**
    求拆分数的一维数组实现
*/
#include<bits/stdc++.h>
using namespace std;
unsigned long long mm[1000001];

const int MN = 1000000000;

//循环计算
void cal(){
    mm[0] = 1;
    for(int i = 1;i < 1000001;i++){
        if(i%2){
            mm[i] = mm[i-1];
        }else{
            //分为含有1和不含有1的组合
            mm[i] = (mm[i-1] + mm[i/2])%MN;
        }
    }
}

int main(){
    int T;
    cal();
    cin >> T;
    int n,m;
    for(int i = 0;i < T;i++){
        cin >> m;
        cout << "case #" << i << ":" << endl;
        //cout << f_cal(m,n) << endl;
        cout << mm[m] % MN << endl;
    }
    return 0;
}

            /**
            记f(n)为n的划分数，我们有递推公式：
f(2m + 1) = f(2m)，
f(2m) = f(2m - 1) + f(m)，
初始条件：f(1) = 1。


证明:

证明的要点是考虑划分中是否有1。

记:
A(n) = n的所有划分组成的集合，
B(n) = n的所有含有1的划分组成的集合，
C(n) = n的所有不含1的划分组成的集合，
则有: A(n) = B(n)∪C(n)。

又记:
f(n) = A(n)中元素的个数，
g(n) = B(n)中元素的个数，
h(n) = C(n)中元素的个数，
易知: f(n) = g(n) + h(n)。

以上记号的具体例子见文末。


我们先来证明: f(2m + 1) = f(2m)，
首先，2m + 1 的每个划分中至少有一个1，去掉这个1，就得到 2m 的一个划分，故 f(2m + 1)≤f(2m)。
其次，2m 的每个划分加上个1，就构成了 2m + 1 的一个划分，故 f(2m)≤f(2m + 1)。
综上，f(2m + 1) = f(2m)。

接着我们要证明: f(2m) = f(2m - 1) + f(m)，
把 B(2m) 中的划分中的1去掉一个，就得到 A(2m - 1) 中的一个划分，故 g(2m)≤f(2m - 1)。
把 A(2m - 1) 中的划分加上一个1，就得到 B(2m) 中的一个划分，故 f(2m - 1)≤g(2m)。
综上，g(2m) = f(2m - 1)。

把 C(2m) 中的划分的元素都除以2，就得到 A(m) 中的一个划分，故 h(2m)≤f(m)。
把 A(m) 中的划分的元素都乘2，就得到 C(2m) 中的一个划分，故 f(m)≤h(2m)。
综上，h(2m) = f(m)。

所以: f(2m) = g(2m) + h(2m) = f(2m - 1) + f(m)。
————————————————
版权声明：本文为CSDN博主「AndyZhang」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/zhang20072844/java/article/details/17033931
            */
