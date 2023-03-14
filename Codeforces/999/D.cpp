#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1), mod(m, 0);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<vector<int>> mv(m, vector<int>());
    for(int i=1;i<=n;i++){
         mod[v[i]%m]++;
         mv[v[i]%m].push_back(i);
    }
    int k = n/m;
    vector<pair<int,int>> movsm, movsv;
    multiset<int> gr, lo;
    for(int i=0;i<m;i++){
        if(mod[i] > k) for(int j=0;j<(mod[i]-k);j++) gr.insert(i);
        else if(mod[i] < k) for(int j=0;j<(k-mod[i]);j++) lo.insert(i);
    }

    for(auto x : lo){
        auto it = gr.lower_bound(x);
        if(it == gr.begin()) it = gr.end();
        --it;
        int src = *it;
        gr.erase(it);
        movsm.push_back({src, x});
    }

    ll cost = 0;
    for(auto x : movsm){
        int ind = mv[x.first].back();
        mv[x.first].pop_back();
        ll more;
        if(x.second > x.first) more = x.second - x.first;
        else more = m+x.second-x.first;
        cost += more;
        v[ind] += more;
    }
    cout << cost << "\n";
    for(int i=1;i<=n;i++) cout << v[i] << " ";

    
}
