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
        vector<int> x(n+1);
        vector<int> y(m+1);
        for(int i=1;i<=n;i++) cin >> x[i];
        for(int i=1;i<=m;i++) cin >> y[i];
        vector<vector<int>> ans(n+1, vector<int>(m+1));
        vector<vector<bool>> psh(n+1, vector<bool>(m+1));
        priority_queue<pair<int, int>> pr, pc;
        for(int i=1;i<=n;i++) pr.push({x[i], i});
        for(int i=1;i<=m;i++) pc.push({y[i], i});
        bool ok = true;
        int pt = n * m;
        set<pair<int, int>> ftu;

        while(pr.size() || pc.size()){
            int v1 = 0, i = 0, v2 = 0, j = 0;
            if(pr.size()) v1 = pr.top().first, i = pr.top().second;
            if(pc.size()) v2 = pc.top().first, j = pc.top().second;
            int mx = max(v1, v2);
            if(pt < mx){
                ok = false;
                break;
            }
            while(pt != mx){
                if(ftu.size()){
                    auto [i, j] = *ftu.begin();
                    ftu.erase(ftu.begin());
                    ans[i][j] = pt;
                    pt--;
                }else{
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
            //now ... 
            auto do_row = [&](int r){
                for(int j=1;j<=m;j++){
                    if(y[j] >= pt && (!psh[r][j])){
                        psh[r][j] = true;
                        ftu.insert({r, j});
                    }
                }
            };
            auto do_col = [&](int c){
                for(int i=1;i<=n;i++){
                    if(x[i] >= pt && (!psh[i][c])){
                        psh[i][c] = true;
                        ftu.insert({i, c});
                    }
                }
            };
            if(v1 == v2){
                assert(ans[i][j] == 0);
                ans[i][j] = pt;
                psh[i][j] = true;
                do_row(i);
                do_col(j);
                pr.pop();
                pc.pop();
            }else if(v1 == mx){
                bool cok = false;
                for(int j=1;j<=m;j++){
                    if(y[j] >= pt && ans[i][j] == 0){
                        ans[i][j] = pt;
                        psh[i][j] = true;
                        cok = true;
                        break;
                    }
                }
                if(!cok){
                    ok = false;
                    break;
                }
                do_row(i);
                pr.pop();
            }else{
                bool cok = false;
                for(int i=1;i<=n;i++){
                    if(x[i] >= pt && ans[i][j] == 0){
                        ans[i][j] = pt;
                        psh[i][j] = true;
                        cok = true;
                        break;
                    }
                }
                if(!cok){
                    ok = false;
                    break;
                }
                do_col(j);
                pc.pop();
            }
            pt--;
        }

        if(ok){
            while(pt != 0){
                if(ftu.size()){
                    auto [i, j] = *ftu.begin();
                    ftu.erase(ftu.begin());
                    ans[i][j] = pt;
                    pt--;
                }else{
                    ok = false;
                    assert(false); //something is wrong
                    break;
                }
            }
        }
        if(ok){
            cout << "Yes\n";
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            }
        }else{
            cout << "No\n";
        }
    }
}
