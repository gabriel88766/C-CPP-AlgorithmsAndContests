#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 200005, M = 20; // M >= log2(N)
int sparse[N][M];
vector<int> v;

void build(){
    int n = v.size();
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = gcd(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

int query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return gcd(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
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
        v.resize(n);
        int g = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            g = gcd(g, v[i]);
        }
        build();
        //assert(st.query(0, n-1) == g);
        //for each element, evaluate number of steps to become g
        int ans = 0;
        for(int i=0;i<n;i++){
            int cur = 0;
            if(query(i, n-1) == g){
                int lo = i, hi = n-1;
                while(lo != hi){
                    int mid = lo + (hi - lo)/2;
                    if(query(i, mid) == g) hi = mid;
                    else lo = mid + 1;
                }
                cur = lo - i;
                ans = max(ans, cur);
            }else{
                int g2 = query(i, n-1);
                int lo = 0, hi = i-1;
                while(lo != hi){
                    int mid = lo + (hi - lo)/2;
                    if(gcd(g2, query(0, mid)) == g) hi = mid;
                    else lo = mid + 1;
                }
                cur = n-i;
                cur += lo;
                ans = max(ans, cur);
            }
        }
        cout << ans << "\n";
    }
}
