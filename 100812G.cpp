#include<bits/stdc++.h>
#define int     long long
#define ii      pair<int,int>
#define fi      first
#define se      second
using namespace std;
const   int mx = 1e5+9, INF = 1e15+7;
int     N, M, D[mx], par[mx], res = INF, res1, res2;
vector  <ii>    A[mx];
priority_queue <ii, vector<ii> , greater<ii>> Q;
void        open(){
    if (fopen("aa.inp","r")){
        freopen("aa.inp","r",stdin); freopen("aa.out","w",stdout);
    }
}

void        dijkstra(){
    while (!Q.empty()){
        int u = Q.top().se;
        int du = Q.top().fi;
        Q.pop();
        if (D[u] != du)     continue;
        for (auto i: A[u]){
            int v = i.se;
            int uv = i.fi;
            if (D[v] > du + uv){
                D[v] = du + uv;
                par[v] = par[u];
                Q.push({D[v] , v});
            }
        }
    }
}

void        solve(){
    cin>>N>>M;
    for (int i=1; i<=N; ++i){
        D[i] = INF;
    }

    int a, u, v, w;
    for (int i=1; i<=N; ++i){
        cin>>a;
        if (a == 1){
            Q.push({0 , i});
            par[i] = i;
            D[i] = 0;
        }
    }

    for (int i=1; i<=M; ++i){
        cin>>u>>v>>w;
        A[u].push_back({w , v});
        A[v].push_back({w , u});
    }

    dijkstra();

    for (int i=1; i<=N; ++i){
        for (auto j: A[i]){
            if (par[i] != par[j.se]){
                if (res > D[i] + D[j.se] + j.fi){
                    res = D[i] + D[j.se] + j.fi;
                    res1 = par[j.se];
                    res2 = par[i];
                }
            }
        }
    }

    if (res == INF){
        cout<<"No luck at all";
    }
    else{
        cout<<res<<"\n";
        cout<<res1<<" "<<res2;
    }
}

#undef  int
int         main(){
#define int     long long
    open();
    solve();
    return 0;
}
