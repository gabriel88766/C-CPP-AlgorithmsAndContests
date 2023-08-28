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
    int t;
    cin >> t;
    while(t--){
        //sliding window, sum of m greater numbers(greater than 0 too)
        int n, m;
        ll d, ans = 0, S = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        cin >> n >> m >> d;
        for(ll i=0;i<n;i++){
            ll aux;
            cin >> aux;
            if(pq.size() < m){
                if(aux > 0){
                    S += aux;
                    pq.push(aux);
                }
            }else if(aux > pq.top()){
                S -= pq.top();
                pq.pop();
                S += aux;
                pq.push(aux);
            }
            ans = max(ans, S - d*(i+1));
        }
        cout << ans << "\n";

    }
}
