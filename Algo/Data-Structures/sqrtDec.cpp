#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
const int sqrtN = 500; //200000 = 500*400
ll v[N];
ll bl[N/sqrtN+1];
int n;

void build(){
    for(int i=1;i<=n;i++){
        bl[i/sqrtN] += v[i];
    }
}

ll query(int a, int b){
    int l = (a/sqrtN+1)*sqrtN;
    int r = (b/sqrtN)*sqrtN;
    ll ans = 0;
    if(r <= l){
        for(int i=a;i<=b;i++) ans += v[i];
    }else{
        for(int i=a;i<l;i++) ans += v[i];
        for(int i=r;i<=b;i++) ans += v[i];
        l /= 500, r /= 500;
        for(int i=l;i<r;i++){
            ans += bl[i];
        }
    }
    return ans;
}

void update(int pos, int val){ //PURS
    bl[pos/sqrtN] += (val-v[pos]);
    v[pos] = val;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int  q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    for(int i=1;i<=q;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            update(b,c);
        }else{
            cout << query(b,c) << "\n";
        }
        
    }
}
