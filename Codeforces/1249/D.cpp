#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;
 
bool sortCompare(pair<pair<int,int>,int> &u, pair<pair<int,int>, int> &v){
    if(u.first.second != v.first.second ) return u.first.second < v.first.second;
    else return u.first.first < v.first.first;
}
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k, pointer=0;
    cin >> n >> k;
    set<pair<int,int>> sv;
    for(int i=0;i<k;i++) sv.insert({0, i});
    vector<pair<pair<int,int>,int>> vp;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        vp.push_back({{a,b}, i+1});
    }
    sort(vp.begin(), vp.end(), sortCompare);
    vector<int> ans;
    for(int i=0;i<n;i++){
       auto it = sv.upper_bound({vp[i].first.first, INF_INT});
       if(it == sv.begin()){
            ans.push_back(vp[i].second);
       }else{
            it--;
            pair<int, int> old = *it;
            sv.erase(old);
            old.first = vp[i].first.second+1;
            sv.insert(old);
       }
    }
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << " ";
 
 
}