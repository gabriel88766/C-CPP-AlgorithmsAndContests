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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> vx(m);
        for(int i=0;i<m;i++){
            cin >> vx[i].first >> vx[i].second;
        }
        //check if mex can be 0, which means 0 in all perms
        vector<int> cnt(n+2);
        for(int i=0;i<m;i++){
            auto [l, r] = vx[i];
            cnt[l]++;
            cnt[r+1]--;
        }
        int idx = -1;
        for(int i=1;i<=n;i++){
            cnt[i] += cnt[i-1];
            if(cnt[i] == m) idx = i;
        }
        if(idx != -1){
            vector<int> ans(n+1);
            int p = 1;
            for(int i=1;i<=n;i++){
                if(i == idx) ans[i] = 0;
                else ans[i] = p++;
            }
            for(int i=1;i<=n;i++) cout << ans[i] << " ";
            cout << "\n";
        }else{
            //try to make it 1. if can't, make it 2. : 0, x1, x2, x3, ..., 1
            bool ok = false;
            for(int i=1;i<=n;i++){
                for(int j=i-1;j<=i+1;j++){
                    if(j == 0) continue;
                    if(j == n+1) continue;
                    if(i == j) continue;
                    //try to make p[i] = 0 and p[j] = 1
                    //ok if none contains i and don't contain j;
                    bool cok = true;
                    for(auto [a, b] : vx){
                        bool ok1 = false, ok2 = false;
                        if(a <= i && i <= b) ok1 = true;
                        if(a <= j && j <= b) ok2 = true;
                        if(ok1 && (!ok2)) cok = false;
                    }
                    if(cok){
                        ok = true;
                        vector<int> ans(n+1);
                        ans[i] = 0;
                        ans[j] = 1;
                        int p = 2;
                        for(int u=1;u<=n;u++){
                            if(u == i || u == j) continue;
                            ans[u] = p++;
                        }
                        for(int u=1;u<=n;u++) cout << ans[u] << " ";
                        cout << "\n";
                        break;
                    }
                }
                if(ok) break;
            }
            if(!ok){
                cout << "0 ";
                for(int i=2;i<n;i++) cout << i << " ";
                cout << "1\n";
            }
        }
    }
}   
