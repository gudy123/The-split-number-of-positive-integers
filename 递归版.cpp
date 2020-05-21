/**
    求拆分数的递归实现
*/
#include<bits/stdc++.h>
using namespace std;
//求得不大于x的最大的，可以由2的幂次得到的数
int getV(int x){
    int t,cnt;
    t = x;
    cnt = 0;
    while(t!=0){
        t>>=1;
        cnt++;
    }
    cnt--;
    return (1<<cnt);
}
//核心递归计算
int f_cal(int m,int n){
    if(m == 1|| n == 1)
        return 1;
    if(m < n){
        return f_cal(m,getV(m));
    }else if(n == m){
        return 1 + f_cal(m,getV(n/2));
    }
    //肯定有 n  和肯定没有n的组成
    return f_cal(m,getV(n/2)) + f_cal(m-n,n);
}
int main(){
    int T;
    //cal();
    cin >> T;
    int n,m;
    for(int i = 0;i < T;i++){
        cin >> m;
        n = getV(m);
        //n = getVM(m);
        cout << "case #" << i << ":" << endl;
        cout << f_cal(m,n) << endl;
        //cout << mm[m][n] << endl;
    }
    return 0;
}
