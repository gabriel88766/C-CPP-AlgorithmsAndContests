#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
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

char gr[101][101];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int ord = i * m + j;
            cin >> gr[i][j];
            if(gr[i][j] == 'B' && j > 0 && gr[i][j-1] == 'B') unite(ord, ord-1);
            if(gr[i][j] == 'B' && i > 0 && gr[i-1][j] == 'B') unite(ord, ord-m);
        }
    }
    set<int> s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int ord = i * m + j;
            if(gr[i][j] == 'B') s.insert(get(ord));
        }
    }
    cout << s.size() << "\n";
}
