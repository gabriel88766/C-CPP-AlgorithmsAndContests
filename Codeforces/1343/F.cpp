#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
vector<int> ans;

bool solve(vector<vector<int>> &v, int beg, int lst = -1){
    vector<int> cans;
    vector<bool> us(v.size(), false);
    int ind = -1;
    for(int i=1;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == beg){
                ind = i;
                break;
            }
        }
    }
    us[ind] = true;
    cans.push_back(beg);
    for(int u=2;u<v.size();u++){
        vector<int> pos1;
        vector<int> cnt(n+1, 0);
        for(int i=1;i<v.size();i++){
            if(us[i]) continue;
            for(int j=0;j<v[i].size();j++){
                cnt[v[i][j]]++;
            }
        }
        for(int i=1;i<=n;i++) if(cnt[i] == 1 && i != lst) pos1.push_back(i);
        int val;
        if(pos1.size() == 0) return false;
        if(pos1.size() == 2){
            assert(lst == -1);
            vector<int> cc(2);
            for(int i=1;i<v.size();i++){
                for(int j=0;j<v[i].size();j++){
                    if(v[i][j] == pos1[0]){
                        cc[0]++;
                    }
                    if(v[i][j] == pos1[1]){
                        cc[1]++;
                    }
                }
            }
            if(cc[0] > cc[1]){
                val = pos1[0];
                lst = pos1[1];
            }else if(cc[1] > cc[0]){
                val = pos1[1];
                lst = pos1[0];
            }else{
                vector<vector<int>> cv(1);
                for(int i=1;i<v.size();i++){
                    if(!us[i]) cv.push_back(v[i]);
                }
                if(!solve(cv, pos1[0], pos1[1])) solve(cv, pos1[1], pos1[0]);
                for(auto x : ans) cans.push_back(x);
                break;
            }
        }else val = pos1[0];

        for(int i=1;i<v.size();i++){
            if(us[i]) continue;
            for(int j=0;j<v[i].size();j++){
                if(v[i][j] == val){
                    ind = i;
                }
            }
        }
        cans.push_back(val);
        us[ind] = true;
    }
    if(lst != -1) cans.push_back(lst);
    ans = cans;
    return true;
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
            solve(v, pos[0]);
            reverse(ans.begin(), ans.end());
        }else{
            if(!solve(v, pos[0], pos[1])) solve(v, pos[1], pos[0]);
            reverse(ans.begin(), ans.end());
        }
        
        
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
