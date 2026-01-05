#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 200005, M = 20; // M >= log2(N)
int sparse[N][M];

void build(vector<int> &v){
    int n = v.size();
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

int query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    string s;
    cin >> n >> m >> s;
    set<int> unvis;
    for(int i=0;i<n;i++){
        if(s[i] == '0') unvis.insert(i);
    }
    vector<int> d(n+1, INF_INT);
    d[n] = 0;
    queue<int> q;
    q.push(n);
    while(q.size()){
        auto u = q.front();
        q.pop();
        auto it = unvis.lower_bound(u - m);
        vector<int> rml;
        while(it != unvis.end() && *it < u){
            auto v = *it;
            d[v] = d[u] + 1;
            q.push(v);
            rml.push_back(v);
            ++it;
        }
        for(auto x : rml) unvis.erase(x);
    }
    if(d[0] != INF_INT){
        int cur = 0;
        build(d);
        while(cur != n){
            int nv = d[cur] - 1;
            int j = cur;
            for(int jmp = n;jmp>=1;jmp>>=1){
                while(j + jmp <= n && query(cur, j + jmp) == d[cur]) j += jmp;
            }
            // cout << j << " " << query(cur, j) << " " << d[cur] << "\n";
            j++;
            cout << j - cur << " ";
            cur = j;
        }
        cout << "\n";
    }else cout << "-1\n";
}