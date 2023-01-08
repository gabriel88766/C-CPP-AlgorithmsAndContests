//BIT 2D, tested https://cses.fi/problemset/task/1652/
//Easiest logic to more dimensions
const int M = 1e3+5;

ll bit[M][M];
ll v[M][M];
int n;

ll sum(int a, int b){ // sum in range [1, 1] to [a, b]
    ll ans = 0;
    for(int i = a; i >= 1; i -= i & -i){
        for(int j = b; j >= 1; j -= j & -j){
            ans += bit[i][j];
        }
    }
    return ans;
}

void add(int a, int b, ll value){ //add value to position [a, b]
    for(int i = a; i <= n; i += i & -i){
        for(int j = b; j <= n; j += j & -j){
            bit[i][j] += value;
        }
    }
}

void build(){
    for(int i=1;i<=n;i++) 
        for(int j=1; j<=n; j++)
            add(i, j, v[i][j]);
}
