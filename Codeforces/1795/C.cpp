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
        vector<ll> a(n+1), b(n+1), ps(n+1), sum1(n+1, 0), sum2(n+1, 0);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        ps[0] = 0;
        for(int i=1;i<=n;i++) ps[i] = (ps[i-1] + b[i]);
        for(int i=1;i<=n;i++){
            //find ps[l] - ps[i-1] > a[i]
            auto it = upper_bound(ps.begin(), ps.end(), ps[i-1] + a[i]);
            if(it != ps.end()){
                sum1[it-ps.begin()] -= 1;
                sum2[it-ps.begin()] += (a[i] - (ps[it-ps.begin()-1] - ps[i-1]));
            }
            sum1[i] += 1;
        }
        ll cursum = 0;
        for(int i=1;i<=n;i++){
            cursum += sum1[i];
            cout << cursum*b[i] + sum2[i] << " ";
        }
        cout << "\n";
    }
}
