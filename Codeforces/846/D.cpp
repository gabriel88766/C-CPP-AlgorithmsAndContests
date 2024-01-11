#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Query{
    int t, x, y;
    bool operator< (const Query &u) const{
        return t < u.t;
    }
};

vector<Query> vq;
int n, m, k, q;


bool check(int qt){
    vector<vector<int>> ps(n+1, vector<int>(m+1, 0));
    for(int i=0;i<=qt;i++){
        ps[vq[i].x][vq[i].y] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ps[i][j] += ps[i][j-1] + ps[i-1][j] - ps[i-1][j-1];
        }
    }
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            int tt = ps[i][j] - ps[i-k][j] - ps[i][j-k] + ps[i-k][j-k];
            if(tt == k*k) return true;
        }
    }
    return false;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> m >> k >> q;
    vq.resize(q);
    for(int i=0;i<q;i++){
        int x, y, t;
        cin >> x >> y >> t;
        vq[i] = {t, x, y};
    }
    sort(vq.begin(), vq.end());
    if(check(q-1)){
        int lo = 0, hi = q-1;
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            if(check(mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << vq[lo].t << "\n";
    }else cout << "-1\n";
}
