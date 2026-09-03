#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string a, b, ans;
    cin >> a >> b;
    int n = b.size();
    b = " " + b;
    vector<vector<int>> idx(26);
    int cnt = 0;
    for(auto x : a) idx[x - 'a'].push_back(cnt++);
    vector<int> v1(n+2, INF_INT), v2(n+2, -1);
    v1[0] = -1;
    v2[n+1] = INF_INT;
    int id = -1;
    for(int i = 1; i <= n; i++){
        int nc = b[i] - 'a';
        int ni = INF_INT;
        if(idx[nc].size()){
            auto it = upper_bound(idx[nc].begin(), idx[nc].end(), id);
            if(it != idx[nc].end()) ni = *it;
        }
        if(ni == INF_INT) break;
        v1[i] = id = ni;
    }
    id = INF_INT;
    for(int i=n; i>=1; i--){
        int nc = b[i] - 'a';
        int ni = -1;
        if(idx[nc].size()){
            auto it = lower_bound(idx[nc].begin(), idx[nc].end(), id);
            if(it != idx[nc].begin()) ni = *prev(it);
        }
        assert(ni < id);
        if(ni == -1) break;
        v2[i] = id = ni;
    }
    int ansv = 0;
    int idl = -1;
    int cid = 0;
    for(int i=1;i<=n+1;i++){
        while(v1[cid + 1] < v2[i]) ++cid;
        if(cid >= i){
            ansv = n;
            idl = n;
            break;
        }
        if(v2[i] != -1){
            int cl = cid;
            int cr = n + 1 - i;
            if(cl + cr > ansv){
                ansv = cl + cr;
                idl = cl;
            }
        }
    }
    if(ansv != 0){
        int idr = ansv - idl;
        idr = n - idr + 1;
        for(int i=1;i<=idl;i++) ans += b[i];
        for(int i=idr;i<=n;i++) ans += b[i];
        cout << ans << "\n";
    }else cout << "-\n";
}
