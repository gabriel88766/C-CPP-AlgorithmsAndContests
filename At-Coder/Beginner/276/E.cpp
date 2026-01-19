#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 1e6+3;   
int p[N], sz[N];

void init(){
    for(int i=0;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int h, w;
int conv(int i, int j){
    return i*w + j;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    cin >> h >> w;
    vector<string> gr(h);
    for(int i=0;i<h;i++) cin >> gr[i];
    int si, sj;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(gr[i][j] == 'S') si = i, sj = j;
            if(gr[i][j] == '.'){
                for(int k=0;k<4;k++){
                    if(i + dx[k] >= 0 && i + dx[k] < h && j + dy[k] >= 0 && j + dy[k] < w && gr[i + dx[k]][j + dy[k]] == '.'){
                        unite(conv(i, j), conv(i + dx[k], j + dy[k]));
                    }
                }
            }
        }
    }
    bool ok = false;
    for(int k1=0;k1<=3;k1++){
        for(int k2=k1+1;k2<=3;k2++){
            int x1 = si + dx[k1], y1 = sj + dy[k1];
            int x2 = si + dx[k2], y2 = sj + dy[k2];
            if(x1 >= 0 && x2 >= 0 && y1 >= 0 && y2 >= 0 && x1 < h && x2 < h && y1 < w && y2 < w){
                if(get(conv(x1, y1)) == get(conv(x2, y2))) ok = true;
            }
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
