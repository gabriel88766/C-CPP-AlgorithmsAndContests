//tested https://cses.fi/problemset/task/1647
// O(n log n) build, O(1) query min/max, O(log n) query sum
const int N = 200005, M = 20; // M >= log2(N)
ll sparse[N][M];
vector<int> v;

void build(){
    int n = v.size();
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//1-idx
const int N = 200005, M = 20; // M >= log2(N)
ll sparse[N][M];
vector<ll> v;
void build(int n){
    for(int i=1;i<=n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            if((i + (1 << (j-1))) <= n) sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}