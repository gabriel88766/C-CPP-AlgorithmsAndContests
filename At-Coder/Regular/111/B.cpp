#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e5+3;   
int p[N], sz[N], ce[N];
bool seen[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    ce[a]++;
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    ce[a] += ce[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }
    int ans = 0;
    for(int i=1;i<=400000;i++){
        if(!seen[get(i)]){
            seen[get(i)] = true;
            if(sz[get(i)] > ce[get(i)]) ans += ce[get(i)];
            else ans += sz[get(i)];
        }
    }
    cout << ans << "\n";
}
