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
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<pair<int,int>> pq;
        pq.push({n,-1});
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++){
            auto el = pq.top();
            el.second = - el.second;
            pq.pop();
            int nxtans = (el.first-1)/2 + el.second;
            ans[nxtans] = i;
            if(nxtans - el.second > 0){
                 pq.push({nxtans-el.second, -el.second});
            }
            if(el.first+el.second -1- nxtans > 0){
                pq.push({el.first+el.second-1-nxtans, -(nxtans + 1)});
            }
        }
        for(int i=1;i<=n;i++) cout << ans[i]<< " \n"[i==n];
    }   
}
