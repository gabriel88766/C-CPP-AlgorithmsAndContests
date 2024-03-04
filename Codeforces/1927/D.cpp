#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 200005, M = 20; // M >= log2(N)
int sp1[N][M], sp2[N][M];
vector<int> v;

void build(int n){
    for(int i=1;i<=n;i++) sp1[i][0] = sp2[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            if((i + (1 << (j-1))) <= n) sp1[i][j] = min(sp1[i][j-1], sp1[i + (1 << (j-1))][j-1]), sp2[i][j] = max(sp2[i][j-1], sp2[i + (1 << (j-1))][j-1]);
            else sp1[i][j] = sp1[i][j-1], sp2[i][j] = sp2[i][j-1];
        }
    }
}

int qmin(int a, int b){
    if(a == b) return sp1[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sp1[a][pot], sp1[b - (1 << pot) + 1][pot]);
}

int qmax(int a, int b){
    if(a == b) return sp2[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sp2[a][pot], sp2[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        v.resize(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        build(n);
        int q;
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            if(qmin(l, r) == qmax(l, r)) cout << "-1 -1\n";
            else{
                if(qmin(l, r) != v[l]){
                    int lo = l, hi = r;
                    while(lo != hi){
                        int mid = lo + (hi - lo)/2;
                        if(qmin(lo, mid) == qmin(l, r)) hi = mid;
                        else lo = mid + 1;
                    }
                    cout << l << " " << lo << "\n";
                }else{ //qmax != v[l]
                    int lo = l, hi = r;
                    while(lo != hi){
                        int mid = lo + (hi - lo)/2;
                        if(qmax(lo, mid) == qmax(l, r)) hi = mid;
                        else lo = mid + 1;
                    }
                    cout << l << " " << lo << "\n";
                }
            }
        }
        cout << "\n";
    }
}
