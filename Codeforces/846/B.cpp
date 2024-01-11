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
    int n, k, M;
    cin >> n >> k >> M;
    vector<int> t(k);
    int sum = 0;
    for(int i=0;i<k;i++) cin >> t[i];
    for(int i=0;i<k;i++) sum += t[i];
    sort(t.begin(), t.end());
    int maxp = 0;
    for(int i=0;i<=n;i++){
        int cur = sum * i;
        if(cur > M) break;
        int ttp = i * (k + 1);
        int ot = n - i;
        for(int j=0;j<k;j++){
            if(cur + ot * t[j] <= M){
                cur += ot * t[j];
                ttp += ot;
            }else{
                while(cur + t[j] <= M){
                    cur += t[j];
                    ttp++;
                }
            }
        }
        maxp = max(maxp, ttp);
    }   
    cout << maxp << "\n";
}
