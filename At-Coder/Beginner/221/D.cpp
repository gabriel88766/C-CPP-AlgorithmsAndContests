#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+2;
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a, a+b-1});
    }
    sort(vp.begin(), vp.end());
    int tt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int le = -1;
    for(int i=0;i<n;i++){
        while(pq.size() && pq.top() <= vp[i].first){
            ans[tt] += pq.top() - le;
            --tt;
            le = pq.top();
            pq.pop();
        }
        if(tt){
            ans[tt] += vp[i].first - le;
        }
        tt++;
        le = vp[i].first;
        pq.push(vp[i].second + 1);
    }
    while(pq.size()){
        ans[tt] += pq.top() - le;
        --tt;
        le = pq.top();
        pq.pop();
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
