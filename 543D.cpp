#include<bits/stdc++.h>
#define int     long long
using namespace std;
const   int mx = 2e5+9, MOD = 1e9+7;
int     N, F[mx], ans[mx];
vector  <int>   A[mx], suf[mx], pre[mx];
bool    vis[mx];
void        open(){
    if (fopen("aa.inp","r")){
        freopen("aa.inp","r",stdin); freopen("aa.out","w",stdout);
    }
}

void        DFS(int u){
    vis[u] = 1;
    F[u] = 1;
    for (auto v: A[u]){
        if (vis[v])     continue;
        DFS(v);
        F[u] = F[u] * (F[v]+1) % MOD;
    }
}

void        DFS2(int u){
    vis[u] = 1;
    for (auto v: A[u]){
        if (vis[v])     continue;
        DFS2(v);
    }

    suf[u].push_back(1);
    for (int i=1; i<=A[u].size(); ++i){
        suf[u].push_back(suf[u][i-1] * (F[A[u][i-1]] + 1) % MOD);
    }

    pre[u].resize(A[u].size()+2);
    pre[u][A[u].size()+1] = 1;
    for (int i=A[u].size(); i>=1; --i){
        pre[u][i] = pre[u][i+1] * (F[A[u][i-1]] + 1) % MOD;
    }
}

void        cal(int u, int par){
    vis[u] = 1;
    ans[u] = F[u];
    for (int i=1; i<=A[u].size(); ++i){
        int v = A[u][i-1];
        if (vis[v])     continue;
        int parv = suf[u][i-1] * pre[u][i+1] % MOD * par % MOD;
        //cout<<v<<" "<<parv<<"\n";
        F[v] = F[v] * (parv + 1) % MOD;
        cal(v , parv + 1);
    }
}

void        solve(){
    cin>>N;
    int u;
    for (int i=2; i<=N; ++i){
        cin>>u;
        if (i < u)  A[i].push_back(u);
        else        A[u].push_back(i);
    }

    memset(vis , 0 , sizeof(vis));
    DFS(1);

    memset(vis , 0 , sizeof(vis));
    DFS2(1);

    /*for (int i=1; i<=N; ++i){
        cout<<i<<"\n";
        for (auto j: suf[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }*/

    memset(vis , 0 , sizeof(vis));
    cal(1,1);

    for (int i=1; i<=N; ++i){
        cout<<ans[i]<<" ";
    }
}

#undef  int
int         main(){
#define int     long long
    open();
    solve();
    return 0;
}

