#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[21][21];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<int> u(n); 
    for(int i=0;i<n;i++) cin >> u[i];
    ll aux = 1 << 20;
    ll sum = 0;
    for(int i=0;i<n;i++) sum += aux - u[i];
    

    for(int j=19;j>=0;j--){
        ll sum = 0;
        ll curn = 1LL << j;
        for(int p=0;p<n;p++){
            ll d = v[p] / curn;
            if(d % 2) continue;
            ll dif = (d+1)*curn - v[p];
            sum += dif;
        }

    }

    for(int i=0;i<q;i++){
        ll k;
        cin >> k;
        if(k >= sum){
            cout << aux + (k-sum)/n << "\n";
        }else{
            //Unsolved;
        }


        //continue
        for(int j=62;j>=0;j--){
            ll sum = 0;
            ll curn = 1LL << j;
            for(int p=0;p<n;p++){
                ll d = v[p] / curn;
                if(d % 2) continue;
                ll dif = (d+1)*curn - v[p];
                sum += dif;
                if(sum > k) break;
            }
            if(sum > k) continue;
            else{
                k -= sum;
                for(int p=0;p<n;p++){
                    ll d = v[p] / curn;
                    if(d % 2) continue;
                    ll dif = (d+1)*curn - v[p];
                    v[p] += dif;
                }
                //cout << j << " " << k << " " << sum << "\n";
            }
        }
    }
}
