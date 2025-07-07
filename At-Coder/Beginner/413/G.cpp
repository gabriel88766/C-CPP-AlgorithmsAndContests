#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> obs[N];
set<pair<int, int>> seg[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, k;
    cin >> h >> w >> k;
    for(int i=1;i<=k;i++){
        int r, c;
        cin >> r >> c;
        obs[r].push_back(c);
    }
    for(int i=1;i<=h;i++){
        obs[i].push_back(0);
        obs[i].push_back(w+1);
        sort(obs[i].begin(), obs[i].end());
        for(int j=1;j<obs[i].size();j++){
            int l = obs[i][j-1] + 1;
            int r = obs[i][j] - 1;
            if(r >= l){
                seg[i].insert({l, r});
            }
        }
    }
    auto it = seg[1].lower_bound({1, 0});
    assert(it != seg[1].end() && it->first == 1);
    queue<tuple<int, int, int>> qp;
    qp.push({1, it->first, it->second});
    seg[1].erase(it);
    while(qp.size()){
        auto [j, l, r] = qp.front();
        // cout << j << " " << l << " " << r << "\n";
        qp.pop();
        if(j != 1){
            auto it = seg[j-1].lower_bound({l, 0});
            if(it != seg[j-1].begin() && prev(it)->second >= l) it--;
            while(it != seg[j-1].end() && it->first <= r){
                qp.push({j-1, it->first, it->second});
                seg[j-1].erase(it);
                it = seg[j-1].lower_bound({l, 0});
            }
        }
        if(j != h){
            auto it = seg[j+1].lower_bound({l, 0});
            if(it != seg[j+1].begin() && prev(it)->second >= l) it--;
            while(it != seg[j+1].end() && it->first <= r){
                qp.push({j+1, it->first, it->second});
                seg[j+1].erase(it);
                it = seg[j+1].lower_bound({l, 0});
            }
        }
    }
    if(seg[h].size()){
        if(prev(seg[h].end())->second == w) cout << "No\n";
        else cout << "Yes\n";
    }else cout << "Yes\n";
}       
