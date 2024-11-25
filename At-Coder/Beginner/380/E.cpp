#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;   
int p[N], mn[N], mx[N], cl[N], ans[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = mn[i] = mx[i] = cl[i] = i; ans[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    int sza = mx[a] - mn[a] + 1;
    int szb = mx[b] - mn[b] + 1;
    if(sza < szb) swap(a,b);
    p[b] = a;
    mn[a] = min(mn[a], mn[b]);
    mx[a] = max(mx[a], mx[b]);
}



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, q;
    cin >> n >> q;
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int x, c;
            cin >> x >> c;
            x = get(x);
            ans[cl[x]] -= mx[x] - mn[x] + 1;
            ans[c] += mx[x] - mn[x] + 1;
            cl[x] = c;
            if(cl[get(mn[x] - 1)] == c) unite(mn[x] - 1, x);
            if(cl[get(mx[x] + 1)] == c) unite(mx[x] + 1, x);
        }else{
            int c;
            cin >> c;
            cout << ans[c] << "\n";
        }
    }
}
