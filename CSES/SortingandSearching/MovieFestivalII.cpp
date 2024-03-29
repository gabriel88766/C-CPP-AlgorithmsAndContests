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
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    sort(vp.begin(), vp.end(), cmp);
    int ans = 0;
    multiset<int> ms;
    for(int i=0;i<k;i++) ms.insert(0);
    for(int j=0;j<n;j++){
        auto it = ms.upper_bound(vp[j].first);
        if(it != ms.begin()){
            it = prev(it);
            ms.erase(it);
            ms.insert(vp[j].second);
            ans++;
        }
    }
    cout << ans;
}
