#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1000001, M = 21; // M >= log2(N)
int sp1[N][M], sp2[N][M];
vector<int> v;

void build(){
    int n = v.size();
    for(int i=0;i<n;i++) sp1[i][0] = v[i], sp2[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sp1[i][j] = min(sp1[i][j-1], sp1[i + (1 << (j-1))][j-1]), sp2[i][j] = max(sp2[i][j-1], sp2[i + (1 << (j-1))][j-1]);
            else sp1[i][j] = sp1[i][j-1], sp2[i][j] = sp2[i][j-1];
        }
    }
}

ll minq(int a, int b){
    if(a == b) return sp1[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sp1[a][pot], sp1[b - (1 << pot) + 1][pot]);
}
ll maxq(int a, int b){
    if(a == b) return sp2[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sp2[a][pot], sp2[b - (1 << pot) + 1][pot]);
}

ll qmax(int l1, int r1){
    queue<pair<int,int>> q;
    q.push({l1, r1});
    ll ans = 0;
    while(!q.empty()){
        auto [l, r] = q.front();
        q.pop();
        if(l == r) ans += v[l];
        else{
            int m = maxq(l, r);
            int b = l;
            for(int i=(r-l+1)>>1;i>=1;i>>=1){
                while(b + i <= r && maxq(b+i, r) == m) b += i;
            }
            ll x1 = r-l+1, x2 = b-l, x3 = r-b;
            ans += ((x1*(x1+1))/2 - (x2*(x2+1))/2 - (x3*(x3+1))/2)*m; 
            if(b-1 >= l) q.push({l, b-1});
            if(r >= b+1) q.push({b+1, r});
        }
    }
    return ans;
}

ll qmin(int l1, int r1){
    queue<pair<int,int>> q;
    q.push({l1, r1});
    ll ans = 0;
    while(!q.empty()){
        auto [l, r] = q.front();
        q.pop(); 
        if(l == r) ans += v[l];
        else{
            int m = minq(l, r);
            int b = l;
            for(int i=(r-l+1)>>1;i>=1;i>>=1){
                while(b + i <= r && minq(b+i, r) == m) b += i;
            }
            ll x1 = r-l+1, x2 = b-l, x3 = r-b;
            ans += ((x1*(x1+1))/2 - (x2*(x2+1))/2 - (x3*(x3+1))/2)*m; 
            if(b-1 >= l) q.push({l, b-1});
            if(r >= b+1) q.push({b+1, r});
        }
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    build();
    ll ans = qmax(0, n-1);
    ans -= qmin(0, n-1);
    cout << ans << "\n";
}
