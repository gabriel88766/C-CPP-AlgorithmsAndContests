#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 100005, M = 18; // M >= log2(N)
int sparse[N][M];
vector<int> v;
int n;
void build(){
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

int query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

int mx, mn;
int query2(int l, int r){
    if(r / n == l / n) return query(l % n, r % n);
    else if(r - l + 1 >= n) return mx;
    else return max(query(l%n, n-1), query(0, r%n));
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    mx = *max_element(v.begin(), v.end());
    mn = *min_element(v.begin(), v.end());
    build();
    //1, if for some position goes inf, goes inf for all positions
    if(mn >= (mx/2 + mx%2)){
        for(int i=0;i<n;i++) cout << "-1 ";
        cout << "\n";
    }else{
        vector<int> ans(n, -1);
        queue<int> q;
        for(int i=0;i<3*n;i++){
            while(!q.empty()){
                auto u = q.front();
                int cur = query2(u, i);
                if(v[i%n] < (cur/2 + cur%2)){
                    ans[u] = i - u;
                    q.pop();
                }else break;
            }
            if(i < n) q.push(i);
        }
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
