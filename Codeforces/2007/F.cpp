#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 400005, M = 20; // M >= log2(N)
ll sparse[N][M];
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

ll query(int a, int b){
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
        ll ans = n;
        vector<int> num(n);
        for(int i=0;i<n;i++) cin >> num[i];
        v.resize(n);
        for(int i=0;i<n-1;i++){
            v[i] = abs(num[i+1] - num[i]);
        }
        v[n-1] = 1;
        build();
        for(int i=0;i<n-1;i++){
            int lo = i, hi = n-1;
            while(lo != hi){
                int mid = lo + (hi - lo)/2;
                int x = query(i, mid);
                if(x != 0){
                    while(!(x%2)) x/= 2;
                }
                if(x == 1) hi = mid;
                else lo = mid + 1;
            }
            ans += n-1-lo;
            //see max x = 0
            if(v[i] == 0){
                int cur = i;
                for(int k=n/2;k>=1;k>>=1){
                    while(cur + k <= n-1 && query(i, cur+k) == 0) cur += k;
                }
                ans += cur - i + 1;
            }
        }
        cout << ans << "\n";
    }
}
