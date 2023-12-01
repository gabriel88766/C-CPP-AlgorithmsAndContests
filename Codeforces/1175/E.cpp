#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3, M = 20;
int nxt[N][M];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> seg(n);
    for(int i=0;i<n;i++){
        cin >> seg[i].first >> seg[i].second;
    }
    sort(seg.begin(), seg.end());
    int p = 0, cur = -1;
    for(int i=0;i<N;i++){
        while(p < n && seg[p].first == i){
            cur = max(seg[p].second, cur);    
            p++;
        }
        if(cur <= i) nxt[i][0] = -1;
        else nxt[i][0] = cur;
    }
    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            if(nxt[j][i-1] != -1) nxt[j][i] = nxt[nxt[j][i-1]][i-1];
            else nxt[j][i] = -1;
        }
    }
    for(int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int j=M-1;j>=0;j--){
            if(nxt[l][j] > l && nxt[l][j] < r){
                ans += 1 << j;
                l = nxt[l][j];
            }
        }
        if(nxt[l][0] >= r) ans++;
        else ans = -1;
        cout << ans << "\n";
    }
}
