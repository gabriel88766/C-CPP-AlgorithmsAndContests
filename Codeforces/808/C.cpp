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
    int n , w;
    cin >> n >> w;
    //w <= 10000
    vector<pair<int,int>> vp(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first;
        vp[i].second = i;
    }
    sort(vp.begin(), vp.end(), greater<pair<int,int>>());
    //sequence decreasing
    int cans = 0;
    for(int i=0;i<n;i++){
        int cur = vp[i].first / 2 + vp[i].first % 2;
        cans += cur;
        ans[vp[i].second] = cur;
    }
    if(cans > w){
        cout << "-1\n";
        return 0;
    }else{
        for(int i=0;i<n;i++){
            int s = vp[i].first - ans[vp[i].second];
            if(s >= w - cans){
                ans[vp[i].second] += w-cans;
                break;
            }else{
                ans[vp[i].second] += s;
                cans += s;
            }
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}   
