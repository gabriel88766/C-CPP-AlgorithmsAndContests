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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    int mx = 0, mn = m;
    for(int i=0;i<n;i++){
        mn = min(mn, vp[i].second);
    }
    vector<int> ans(m+2, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=1;i<=mn;i++){
        if(i == 1){
            //init
            for(int j=0;j<n;j++) mx = max(mx, vp[j].first);
            for(int j=0;j<n;j++) pq.push({vp[j].first, j});
        }else{
            while(pq.size() && pq.top().first < i){ //can do O(n)
                mx = max(mx, vp[pq.top().second].second);
                pq.pop();
            }
        }
        int mnl = mx - i + 1;
        int mxl = m - i + 1;
        ans[mnl]++;
        ans[mxl+1]--;
    }
    for(int i=1;i<=m;i++){
        ans[i] += ans[i-1];
        cout << ans[i] << " ";
    }
    cout << "\n";
}
