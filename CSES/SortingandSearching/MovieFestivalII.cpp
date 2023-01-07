#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

bool sortCompare(pair<int,int> &u, pair<int,int> &v){
    if(u.second != v.second ) return u.second < v.second;
    else return u.first < v.first;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    set<pair<int,int>> sv;
    for(int i=0;i<k;i++) sv.insert({0, i});
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        vp.push_back({a,b});
    }
    sort(vp.begin(), vp.end(), sortCompare);
    int ans = 0;
    for(int i=0;i<n;i++){
       auto it = sv.upper_bound({vp[i].first, INF_INT});
       if(it == sv.begin()) continue;
       else{
            it--;
            pair<int, int> old = *it;
            sv.erase(old);
            old.first = vp[i].second;
            sv.insert(old);
            ans++;
       }
    }
    cout << ans;


}
