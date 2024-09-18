#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e5+3;
int cntq[N], mqt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int ov = v[0];
    int cnt = 1;
    for(int i=1;i<v.size();i++){
        if(v[i] != ov){
            vp.push_back({ov, cnt});
            ov = v[i];
            cnt = 1;
        }else cnt++;
    }
    vp.push_back({ov, cnt});
    for(auto [x, y] : vp){
        cntq[y]++;
    }
    int ttn = vp.size();
    for(int i=1;i<=n;i++){
        mqt[i] += mqt[i-1];
        mqt[i] += ttn;
        ttn -= cntq[i];
    }
    pair<int,int> bst = {0, 0};
    for(int i=1;i<=n;i++){
        for(ll j=i;j*i<=n;j++){
            int cur = i * j;
            int old = bst.first * bst.second;
            if(mqt[i] >= cur && cur > old) bst = {i, j}; 
        }
    }
    cout << bst.first * bst.second << "\n";
    cout << bst.first << " " << bst.second << "\n";
    auto [x, y] = bst;
    vector<vector<int>> ans(x, vector<int>(y));
    
    sort(vp.begin(), vp.end(), [&](pair<int,int> &u, pair<int,int> &v){
        return u.second > v.second;
    });
    vector<int> on;
    for(int i=0;i<vp.size();i++){
        for(int j=0;j<min(vp[i].second, x);j++) on.push_back(vp[i].first);
    }
    int p = 0;
    for(int i=0;i<y;i++){
        int ii = 0, ij = i;
        for(int j=0;j<x;j++){
            ans[ii][ij] = on[p++];
            ii++;
            ij = (ij + 1) % y;
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

}   
