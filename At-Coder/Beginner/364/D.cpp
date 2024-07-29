#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct query{
    int b, k, i;
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<query> vq(q);
    for(int i=0;i<q;i++){
        cin >> vq[i].b >> vq[i].k;
        vq[i].i = i;
    }
    sort(vq.begin(), vq.end(), [&](query &a, query &b){
        return a.b < b.b;
    });
    vector<int> ans(q);
    deque<int> dq1, dq2;
    for(int i=0;i<n;i++) dq2.push_back(a[i]);

    for(int i=0;i<q;i++){
        auto [b, k, j] = vq[i];
        while(dq2.size() && dq2.front() < b){
            dq1.push_front(-dq2.front());
            dq2.pop_front();
        }
        int lo = 0, hi = 3e8;
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            int ct = upper_bound(dq2.begin(), dq2.end(), b + mid) - dq2.begin();
            ct += upper_bound(dq1.begin(), dq1.end(), -(b-mid)) - dq1.begin();
            if(ct >= k) hi = mid;
            else lo = mid + 1;
        }
        ans[j] = lo;
    }







    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
}
