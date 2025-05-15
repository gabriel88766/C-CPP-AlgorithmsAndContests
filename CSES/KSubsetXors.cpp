#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int xorb[32];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    int out_b = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        while(x && xorb[31-__builtin_clz(x)]){
            x ^= xorb[31-__builtin_clz(x)];
        }
        if(x){
            xorb[31-__builtin_clz(x)] = x;
        }else out_b++;
    }
    if(out_b >= 30 || (1 << out_b) > k){
        for(int i=1;i<=k;i++) cout << "0 ";
        cout << "\n";
    }else{
        vector<int> base;
        for(int i=0;i<=31;i++){
            if(xorb[i]) base.push_back(xorb[i]);
        }
        auto find_number = [&](int k){
            int ans = 0;
            for(int j=base.size()-1;j>=0;j--){
                int b = 0;
                if((ans ^ base[j]) > ans) b = 1;
                if(k >= (1 << j)){
                    k -= (1 << j);
                    if(b) ans ^= base[j];
                }else{
                    if(!b) ans ^= base[j];
                }
            }
            return ans;
        };
        int tt = 1 << out_b;
        for(int i=0;i<k;i++){
            int cn = i / tt;
            cout << find_number(cn) << " ";
        }
        cout << "\n";
    }
}
