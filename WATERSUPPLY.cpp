#include<bits/stdc++.h>
#define int     long long
#define ii      pair<int,int>
#define iii     pair<int,ii>
#define fi      first
#define se      second
using namespace std;
const   int mx = 2000+9;
int     N, T, K, sum = 0, A[mx], par[mx], D[mx][mx], C[mx][mx];
bool    vis[mx][mx];
priority_queue <iii , vector<iii> , greater<iii> > Q;
void        open(){
    if (fopen("aa.inp","r")){
        freopen("aa.inp","r",stdin); freopen("aa.out","w",stdout);
    }
}

int         root(int u){
    return (par[u] < 0) ? u : (par[u]);
}

void        merg(int u, int v){
    u = root(u);
    v = root(v);
    if (par[u] > par[v]){
        swap(u , v);
    }
    par[u] += par[v];
    par[v] = u;
}

void        solve(){
    cin>>T;
    while (T--){
        cin>>N>>K;
        sum = 0;
        for (int i=1; i<=N; ++i){
            cin>>A[i];
            sum += A[i];
            par[i] = -1;
        }

        while (!Q.empty())      Q.pop();

        for (int i=1; i<=N; ++i){
            for (int j=1; j<=N; ++j){
                cin>>C[i][j];
                if (i < j){
                    D[i][j] = D[j][i] = C[i][j] - max(A[i] , A[j]);
                    int u = i, v = j;
                    if (A[u] > A[v])    swap(u , v);
                    Q.push({D[i][j] , {u,v}});
                    //cout<<u<<" "<<v<<" "<<D[i][j]<<"\n";
                }
            }
        }

        memset(vis , 0 , sizeof(vis));
        int s = N;
        while (!Q.empty()){
            int u = Q.top().se.fi, v = Q.top().se.se, w = Q.top().fi;
            //cout<<u<<" "<<v<<" "<<w<<"\n";
            Q.pop();
            if (root(u) != u || root(v) != v)   continue;
            if (s <= K && w >= 0)   break;
            sum += w;
            s--;
            par[v] = u;
            vis[u][v] = vis[v][u] = 1;
            for (int j=1; j<=N; ++j){
                if (vis[v][j])      continue;
                if (D[u][j] > C[v][j] - max(A[u] , A[j])){
                    vis[v][j] = vis[j][v] = 1;
                    C[u][j] = C[j][u] = C[v][j];
                    D[u][j] = D[j][u] = C[v][j] - max(A[u],A[j]);
                    int a = u, b = j;
                    if (A[a] > A[b])        swap(a , b);
                    Q.push({D[a][b] , {a , b}});
                }
            }
        }

        cout<<sum<<"\n";
    }
}

#undef  int
int         main(){
#define int     long long
    open();
    solve();
    return 0;
}

