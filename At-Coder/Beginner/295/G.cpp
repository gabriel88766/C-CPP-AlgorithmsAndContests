#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N];
int par[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(a > b) swap(a, b);
    p[b] = a;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, q;
    cin >> n;
    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        par[i] = x;
    }
    cin >> q;
    for(int i = 0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int a, b;
            cin >> a >> b;
            while(get(a) != get(b)){
                a = get(a);
                unite(a, b);
                a = par[a];
            }
        }else{
            int a;
            cin >> a;
            cout << get(a) << "\n";
        }
    }
}
