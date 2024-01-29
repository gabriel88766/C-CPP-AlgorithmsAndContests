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
    int n, m, l;
    cin >> n >> m >> l;
    vector<pair<int,int>> vp1(n), vp2(m);
    for(int i=0;i<n;i++){
        cin >> vp1[i].first;
        vp1[i].second = i+1;
    }
    for(int i=0;i<m;i++){
        cin >> vp2[i].first;
        vp2[i].second = i+1;
    }
    set<pair<int,int>> st;
    for(int i=0;i<l;i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        st.insert({a, b});
    }
    sort(vp1.begin(), vp1.end());
    sort(vp2.begin(), vp2.end());
    int lo = 2, hi = 2e9;
    while(lo != hi){ //find minimum sum with at most L possibilities
        int mid = lo + (hi - lo)/2;
        ll qnt = 0;
        for(int i=0;i<n;i++){
            int cur = mid - vp1[i].first;
            qnt += m - (lower_bound(vp2.begin(), vp2.end(), make_pair(cur, 0)) - vp2.begin());
        }
        if(qnt > l) lo = mid + 1;
        else hi = mid;
    }
    int ans = lo - 1;
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            if(vp1[i].first + vp2[j].first < lo) break;
            int a = vp1[i].second, b = vp2[j].second;
            if(a > b) swap(a, b);
            if(!st.count({a, b})) ans = max(ans, vp1[i].first + vp2[j].first);
        }
    }
    cout << ans << "\n";
}
