#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<pair<int,int>> vpc[31];

bool cmp(pair<int,int> u, pair<int,int> v){
    if(u.second != v.second) return u.second < v.second;
    else return u.first < v.first;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, c;
    cin >> n >> c;
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        vpc[c].push_back({a, b});
    }
    for(int i=1;i<=c;i++) sort(vpc[i].begin(), vpc[i].end());
    for(int i=1;i<=c;i++){
        if(vpc[i].size()){
            int l = vpc[i][0].first, r = 0;
            for(int j=0;j<vpc[i].size();j++){
                r = vpc[i][j].second;
                if(j != (vpc[i].size()-1) && vpc[i][j].second == vpc[i][j+1].first) continue;
                else{
                    vp.push_back({l, r+1});
                    if(j != (vpc[i].size()-1)) l = vpc[i][j+1].first;
                }
            }
        }
    }
    sort(vp.begin(), vp.end(), cmp);
    int ans = 0;
    multiset<int> ms;
    for(int j=0;j<vp.size();j++){
        auto it = ms.upper_bound(vp[j].first);
        if(it == ms.begin()){
            ms.insert(vp[j].second);
        }else{
            it = prev(it);
            ms.erase(it);
            ms.insert(vp[j].second);
        }
        ans = max(ans, (int)ms.size());
    }
    cout << ans;
}
