#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e6+3;
const int M = 305;
vector<tuple<int,int,int>> ins[N], ers[N];
int gr[M][M], aux[M][M];
int ansc[N];

int p[M*M], sz[M*M];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int gc(int a, int b){
    return (a-1)*m + b;
}
int cans = 0;
void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    cans--;
    sz[a] += sz[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen(  "in", "r", stdin); //test input
    int  q;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ins[0].push_back({i, j, 0});
        }
    }
    for(int i=1;i<=q;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(c != gr[a][b]){
            ers[gr[a][b]].push_back({a, b, i});
            gr[a][b] = c;
            ins[gr[a][b]].push_back({a, b, i});
        }
    }
    //at most 2e6 + 90000 insert and 2e6+90000 erase.
    for(int i=0;i<N;i++){
        if(ins[i].size()){
            init(n*m);
            //cell i, j => (i-1) * m + j
            // -m(if greater than m) +m(if lower than (n-1)*m + 1), +1 (if not m), -1 (if not 1)
            vector<pair<int,int>> aux1, aux2;
            if(i == 0){
                aux1.push_back({0, 1});
                ansc[0] += 1;
            }else{
                aux1.push_back({0, 0});
            }
            cans = 0;
            for(auto [a, b, j] : ins[i]){
                cans++;
                aux[a][b] = 1;
                for(int k=0;k<4;k++){
                    if(aux[a+dx[k]][b+dy[k]] == 1){
                        unite(gc(a, b), gc(a+dx[k], b+dy[k]));
                    }
                }
                if(i != 0) aux1.push_back({j, cans});
            }
            for(auto [a, b, j]: ers[i]){
                aux[a][b] = 0;
            }
            init(n*m);
            cans = 0;
            for(auto [a, b, j] : ins[i]){
                if(!aux[a][b]) continue;
                cans++;
                for(int k=0;k<4;k++){
                    if(aux[a+dx[k]][b+dy[k]] == 1){
                        unite(gc(a, b), gc(a+dx[k], b+dy[k]));
                    }
                }
            }
            reverse(ers[i].begin(), ers[i].end());
            for(auto [a, b, j] : ers[i]){
                aux2.push_back({j, cans});
                cans++;
                aux[a][b] = 1;
                for(int k=0;k<4;k++){
                    if(aux[a+dx[k]][b+dy[k]] == 1){
                        unite(gc(a, b), gc(a+dx[k], b+dy[k]));
                    }
                }
            }
            reverse(aux2.begin(), aux2.end());
            for(auto x : aux2) aux1.push_back(x);
            for(int i=1;i<aux1.size();i++){
                auto [a, b] = aux1[i];
                auto [c, d] = aux1[i-1];
                ansc[a] += b-d;
            }
            for(auto [a, b, j]: ins[i]){
                aux[a][b] = 0;
            }
        }
    }
    for(int i=1;i<=q;i++){
        ansc[i] += ansc[i-1];
        cout << ansc[i] << "\n";
    }
}
