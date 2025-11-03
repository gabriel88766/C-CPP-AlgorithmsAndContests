#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 200005;
int lp[N+1], cntp[N];
vector<int> pr;
void sieve(){
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n+1);
        int g = 0, cans;
        auto insert = [&](int aux){
            vector<int> ap;
            while(aux != 1){
                if(ap.size() == 0 || lp[aux] != ap.back()){
                    ap.push_back(lp[aux]);
                }
                aux /= lp[aux];
            }
            for(auto x : ap){
                cntp[x]++;
                cans = max(cans, cntp[x]);
            }
        };
        for(int i = 1; i <= n; i++){
            cin >> v[i];
            int ng = gcd(g, v[i]);
            if(ng != g){
                g = ng;
                for(int j=1;j<=n;j++) cntp[j] = 0;
                cans = 0;
                for(int j=1;j<i;j++){
                    insert(v[j] / g);
                }   
            }
            insert(v[i] / g);
            cout << cans << " ";
        }
        cout << "\n";
    }
}
