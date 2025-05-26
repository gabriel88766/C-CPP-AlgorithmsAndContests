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
    priority_queue<int> pq;
    ll ans = 0;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(i == 1){
            pq.push(x);
        }else{
            if(x >= pq.top()) pq.push(x);
            else{
                ans += (pq.top() - x);
                pq.pop();
                pq.push(x);
                pq.push(x);
            }
        }
    }
    cout << ans << "\n";
}
