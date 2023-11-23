//TOTAL TRASHHHHHHHHH!

#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
vector<int> solve(vector<vector<int>> &v, int beg, int lst){
    vector<int> ans;
    vector<bool> us(n, false);
    int ind;
    for(int i=1;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == beg){
                ind = i;
                break;
            }
        }
    }
    us[ind] = true;
    ans.push_back(beg);
    for(int u=2;u<n;u++){
        vector<int> pos1;
        vector<int> cnt(n+1, 0);
        for(int i=1;i<n;i++){
            if(us[i]) continue;
            for(int j=0;j<v[i].size();j++){
                cnt[v[i][j]]++;
            }
        }
        for(int i=1;i<=n;i++) if(cnt[i] == 1) pos1.push_back(i);
        vector<int> pos;
        for(int j=0;j<v[ind].size();j++){
            for(auto x : pos1){
                if(v[ind][j] == x) pos.push_back(x);
            }
        }
        if(pos.size() == 0) break;
        for(int i=1;i<n;i++){
            if(us[i]) continue;
            for(int j=0;j<v[i].size();j++){
                if(v[i][j] == pos[0]){
                    ind = i;
                }
            }
        }
        ans.push_back(pos[0]);
        us[ind] = true;
    }
    ans.push_back(lst);
    return ans;
}

vector<int> solve2(vector<vector<int>> &v, int beg){
    vector<int> ans;
    vector<bool> us(n, false);
    int ind;
    for(int i=1;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == beg){
                ind = i;
                break;
            }
        }
    }
    us[ind] = true;
    ans.push_back(beg);
    for(int u=2;u<n;u++){
        vector<int> pos1;
        vector<int> cnt(n+1, 0);
        for(int i=1;i<n;i++){
            if(us[i]) continue;
            for(int j=0;j<v[i].size();j++){
                cnt[v[i][j]]++;
            }
        }
        for(int i=1;i<=n;i++) if(cnt[i] == 1) pos1.push_back(i);
        vector<int> pos;
        for(int j=0;j<v[ind].size();j++){
            for(auto x : pos1){
                if(v[ind][j] == x) pos.push_back(x);
            }
        }
        for(int i=1;i<n;i++){
            if(us[i]) continue;
            for(int j=0;j<v[i].size();j++){
                if(v[i][j] == pos[0]){
                    ind = i;
                }
            }
        }
        ans.push_back(pos[0]);
        us[ind] = true;
    }

    for(int i=1;i<=n;i++){
        bool ok = false;
        for(int j=0;j<ans.size();j++){
            if(ans[j] == i) ok = true;
        }
        if(!ok) ans.push_back(i);
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> v(n);
        vector<int> ans[2];
        vector<int> cnt(n+1, 0);
        for(int i=1;i<n;i++){
            int k;
            cin >> k;
            v[i].resize(k);
            for(int j=0;j<k;j++){
                 cin >> v[i][j];
                 cnt[v[i][j]]++;
            }
        }
        vector<int> pos;
        for(int i=1;i<=n;i++){
            if(cnt[i] == 1){
                pos.push_back(i);
            }
        }
        assert(pos.size() <= 2);
        if(pos.size() == 1){
            ans[0] = solve2(v, pos[0]);
            reverse(ans[0].begin(), ans[0].end());
            for(int i=1;i<n;i++){
                int a = ans[0][0], b = ans[0][1];
                bool ok1 = false, ok2 = false;
                for(int j=0;j<v[i].size();j++){
                    if(v[i][j] == a) ok1 = true;
                    if(v[i][j] == b) ok2 = true;
                }       
                if(ok1 && !ok2){
                    swap(ans[0][0], ans[0][1]);
                    break;
                }
            }
        }else{
            ans[0] = solve(v, pos[0], pos[1]);
            ans[1] = solve(v, pos[1], pos[0]);
            if(ans[0].size() != n) swap(ans[0], ans[1]);
            reverse(ans[0].begin(), ans[0].end());
        }
        
        
        for(auto x : ans[0]) cout << x << " ";
        cout << "\n";
    }
}
