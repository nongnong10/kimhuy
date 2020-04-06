#include<bits/stdc++.h>
#define int     long long
#define ii      pair<int,int>
#define fi      first
#define se      second
using namespace std;
const   int mx = 1e5+9, INF = 1e9+7;
int     N, M, K, S, T, B[mx], D[mx];
vector  <int>   A[mx];
void        open(){
    if (fopen("aa.inp","r")){
        freopen("aa.inp","r",stdin); freopen("aa.out","w",stdout);
    }
}

bool        check(int a){
    for (int i=1; i<=N; ++i){
        D[i] = INF;
    }
    D[S] = 0;

    queue <ii> Q;
    Q.push(ii(0 , S));

    while (!Q.empty()){
        int u = Q.front().se;
        int du = Q.front().fi;
        Q.pop();
        if (du != D[u])     continue;
        for (auto i: A[u]){
            int s = du + 1;
            if (B[i])       s = 0;
            if (D[i] > s){
                D[i] = s;
                if (D[i] < a) Q.push({s , i});
            }
        }
    }

    if (D[T] <= a)   return 1;
    return 0;
}

void        solve(){
    cin>>N>>M>>K;
    memset(B , 0 , sizeof(B));
    int a, u, v;
    for (int i=1; i<=K; ++i){
        cin>>a;
        B[a] = 1;
    }

    for (int i=1; i<=M; ++i){
        cin>>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    cin>>S>>T;

    int low = 1, high = N, res = -1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (check(mid)){
            res = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<res;
}

#undef  int
int         main(){
#define int     long long
    open();
    solve();
    return 0;
}
