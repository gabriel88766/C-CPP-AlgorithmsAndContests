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
        int n;
        cin >> n;
        int hf = n/2;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        bool ok = false;
        for(int i=0;i<=n-hf;i++){
            if(v[i] == v[i+hf-1]) ok = true;
        }
        if(ok) cout << "-1\n";
        else{
            int ans = 0;
            vector<int> pk;
            for(int i=0;i<n;i++){ // i is the first element
                for(int j=i+1;j<n;j++){
                    int d = v[j] - v[i];
                    for(int k=1;k*k<=d;k++){
                        if(!(d % k)){
                            pk.push_back(k);
                            if(k*k != d) pk.push_back(d/k);
                        }
                    }
                }
            }
            sort(pk.begin(), pk.end());
            pk.resize(unique(pk.begin(), pk.end()) - pk.begin());
            for(auto x : pk){
                bool ok = false;
                for(int i=0;i<n;i++){ // i is the first element
                    int cnt = 0;
                    for(int j=i;j<n;j++){
                        if((v[j] - v[i]) % x);
                        else cnt++;
                    }
                    if(cnt >= hf) ok = true;
                }
                if(ok) ans = x;
            }
            cout << ans << "\n";
        }
    }
}
