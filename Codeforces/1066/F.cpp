#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int cnt = 0;
map<int,int> mp;
int l[N], r[N];
ll dp[N][2];

//cout << fixed << setprecision(6)
bool cmp(pair<int,int> u, pair<int,int> v){
    return max(u.first, u.second) < max(v.first, v.second);
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<pair<int,int>> vp;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        vp.push_back({a,b});
    }
    vp.push_back({0, 0});
    sort(vp.begin(), vp.end(), cmp);
    for(int i=1;i<=n;i++){
        int cm = max(vp[i].first, vp[i].second);
        if(!mp[cm]) mp[cm] = ++cnt;
        int cur = mp[cm];
        if(!l[cur]) l[cur] = i;
        else{
            if(vp[i].second > vp[l[cur]].second) l[cur] = i;
            else if(vp[i].second == vp[l[cur]].second && vp[i].first < vp[l[cur]].first){
                l[cur] = i;
            }
        }
        if(!r[cur]) r[cur] = i;  
        else{
            if(vp[i].second < vp[r[cur]].second) r[cur] = i;
            else if(vp[i].second == vp[r[cur]].second && vp[i].first > vp[r[cur]].first) r[cur] = i; 
        }
    }
    for(int i=1;i<=cnt;i++){
        ll dist = abs(vp[l[i]].first - vp[r[i]].first) + abs(vp[r[i]].second - vp[l[i]].second);
        ll dist00 = abs(vp[l[i-1]].first - vp[l[i]].first) + abs(vp[l[i-1]].second - vp[l[i]].second);
        ll dist01 = abs(vp[l[i-1]].first - vp[r[i]].first) + abs(vp[l[i-1]].second - vp[r[i]].second);
        ll dist10 = abs(vp[r[i-1]].first - vp[l[i]].first) + abs(vp[r[i-1]].second - vp[l[i]].second);
        ll dist11 = abs(vp[r[i-1]].first - vp[r[i]].first) + abs(vp[r[i-1]].second - vp[r[i]].second);
        dp[i][0] = min(dp[i-1][0] + dist01 + dist, dp[i-1][1] + dist11 + dist);
        dp[i][1] = min(dp[i-1][0] + dist00 + dist, dp[i-1][1] + dist10 + dist);
    }
    cout << min(dp[cnt][0], dp[cnt][1]);
}
