#include<bits/stdc++.h>
#define int     long long
using namespace std;
const   int mx = 3e6+9;
int     N, M, P, A[mx], num[mx], mul[mx], sum[mx];
bool    prime[mx];
void        open(){
    if (fopen("aa.inp","r")){
        freopen("aa.inp","r",stdin); freopen("aa.out","w",stdout);
    }
}

void        pre(){
    int W = 3e6;
    memset(mul , 0 , sizeof(mul));
    /*for (int i=1; i<=W; ++i){
        prime[i] = 1;
        if (i != 1){
            mul[i] += num[i] * num[1];
        }
        else{
            mul[i] += num[1] * (num[1] - 1);
        }
    }

    prime[1] = prime[0] = 0;*/

    for (int i=1; i<=W; ++i){
        if  (num[i]==0)    continue;
        for (int j=i; j<=W; j+=i){
            //prime[j] = 0;
            if (j == i*i){
                mul[j] += num[i] * (num[i]-1);
            }
            else{
                mul[j] += num[i] * num[j/i];
            }
        }
    }

    sum[0] = 0;
    for (int i=1; i<=W; ++i){
        sum[i] = sum[i-1] + mul[i];
    }

    /*for (int i=1; i<=36; ++i){
        if (mul[i])     cout<<i<<" "<<mul[i]<<"\n";
    }*/
}

void        solve(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for (int i=1; i<=N; ++i){
        cin>>A[i];
        num[A[i]]++;
    }

    pre();

    cin>>M;
    for (int i=1; i<=M; ++i){
        cin>>P;
        cout<<N*(N-1)-sum[P-1]<<"\n";
    }
}

#undef  int
int         main(){
#define int     long long
    open();
    solve();
    return 0;
}
