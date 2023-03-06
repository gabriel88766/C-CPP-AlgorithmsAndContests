#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int mat[51][51];

const int N = 51;
int p1[N], sz1[N];

void init1(){
    for(int i=1;i<N;i++) {p1[i] = i; sz1[i] = 1;}
}

int get1(int a){ 
    return p1[a] = (p1[a] == a ? a : get1(p1[a]));
}

void unite1(int a, int b){
    a = get1(a);
    b = get1(b);
    if(a == b) return;
    if(sz1[a] < sz1[b]) swap(a,b);
    p1[b] = a;
    sz1[a] += sz1[b];
}

int p2[N], sz2[N];

void init2(){
    for(int i=1;i<N;i++) {p2[i] = i; sz2[i] = 1;}
}

int get2(int a){ 
    return p2[a] = (p2[a] == a ? a : get2(p2[a]));
}

void unite2(int a, int b){
    a = get2(a);
    b = get2(b);
    if(a == b) return;
    if(sz2[a] < sz2[b]) swap(a,b);
    p2[b] = a;
    sz2[a] += sz2[b];
}

ll fat[51];
void init(){
    fat[0] = 1;
    for(int i=1;i<=50;i++) fat[i] = (fat[i-1] * i) % MOD;
}

bool used1[51], used2[51];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, K;
    cin >> n >> K;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> mat[i][j];
        }
    }
    init1(), init2(), init();
    for(int i=1;i<=n;i++){
        for(int j=(i+1);j<=n;j++){
            bool ok = true;
            for(int k=1;k<=n;k++){
                if(mat[i][k] + mat[j][k] > K) ok = false;
            }
            if(ok) unite1(i, j);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=(i+1);j<=n;j++){
            bool ok = true;
            for(int k=1;k<=n;k++){
                if(mat[k][i] + mat[k][j] > K) ok = false;
            }
            if(ok) unite2(i, j);
        }
    }
    int max1 = 0, max2 = 0;
    ll ans = 1;

    for(int i=1;i<=n;i++){
        if(!used1[get1(i)]){
            ans =  (ans * fat[sz1[get1(i)]])%MOD;
            used1[get1(i)] = true;
        }
        if(!used2[get2(i)]){
            ans =  (ans * fat[sz2[get2(i)]])%MOD;
            used2[get2(i)] = true;
        }
    }
    cout << ans;
}
