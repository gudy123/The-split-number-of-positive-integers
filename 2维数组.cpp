/**
    求拆分数的循环实现
*/
#include<bits/stdc++.h>
using namespace std;
unsigned long long mm[1000001][21];

const int MN = 1000000000;
//求得幂次
int getVM(int x){
    int t,cnt;
    t = x;
    cnt = 0;
    while(t!=0){
        t>>=1;
        cnt++;
    }
    cnt--;
    return cnt;
}
//循环计算
void cal(){
    for(int i = 0;i < 1000001;i++){
        mm[i][0] = 1;
    }
    for(int i = 0;i < 21;i++){
        mm[1][i] = 1;
    }
    for(int i = 2;i < 1000001;i++){
        for(int j = 1;j < 21;j++){
            if(i < (1 << j)){
                mm[i][j] = mm[i][getVM(i)];
            }else if(i == (1 << j)){
                mm[i][j] = (mm[i][j-1] % MN + 1) % MN;
            }else{
                mm[i][j] = (mm[i][j-1] % MN + mm[i - (1<<j)][j] % MN) % MN;
            }
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

        n = getVM(m);
        cout << "case #" << i << ":" << endl;
        //cout << f_cal(m,n) << endl;
        cout << mm[m][n] % MN << endl;
    }
    return 0;
}
