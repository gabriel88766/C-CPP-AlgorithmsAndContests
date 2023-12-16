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
    //waf
    int n, r;
    cin >> n >> r;
    vector<pair<int,int>> pos, neg;
    for(int i=1;i<=n;i++){
        int mr, rg;
        cin >> mr >> rg;
        if(rg >= 0){
            pos.push_back({mr, rg});
        }else {
            neg.push_back({mr, rg});
        }
    }
    sort(pos.begin(), pos.end(), [&](pair<int,int> &u, pair<int,int> &v){
        return u.first < v.first;
    });
    //positive, trivial
    int cnt = 0;
    for(auto [x, y] : pos){
        if(r >= x){
            r += y;
            cnt++;
        }
    }
    sort(neg.begin(), neg.end(), [&](const pair<int,int> &u, const pair<int,int> &v){
        return u.first + u.second > v.first + v.second;
    });
    //here dp
    vector<int> dp(n+1, -INF_INT);
    dp[0] = 0;
    for(int i=0;i<neg.size();i++){
        auto [x, y] = neg[i];
        for(int j=n-1;j>=0;j--){
            if(dp[j] + r >= x){
                dp[j+1] = max(dp[j+1], dp[j] + y);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i] + r >= 0) cnt++;
    }
    cout << cnt << "\n";
}
