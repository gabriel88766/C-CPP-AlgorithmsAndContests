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
    //testing
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 2) cout << "-1\n";
        else if(n == 3){
            cout << "1 3\n2 3\n";
        }else if(n == 5){
            cout << "5 4\n4 2\n2 3\n2 1\n";
        }else{
            ll sum = n;
            sum *= (n+1);
            sum /= 2;
            sum -= 1;
            ll cs = sqrt(sum);
            ll ns = (cs + 1) * (cs + 1);
            if(ns - sum < 3) ns = (cs + 2) * (cs + 2);
            //try smart greedy
            vector<int> nn;
            ll x = ns - sum;
            ll nj = n;
            while(x >= 3 && nj >= 3){
                if(nj >= x){
                    nn.push_back(x);
                    nj = x = 0;
                }else{
                    if(x - nj >= 3) nn.push_back(nj);
                    else{
                        while(x - nj < 3) nj--;
                        if(nj <= 3) break;
                        nn.push_back(nj);
                    }
                    x -= nj;
                    nj--;
                }
            }
            vector<bool> is2(n+1, false);
            for(auto x : nn) is2[x] = true;
            ll acs = 0;
            for(int i=2;i<=n;i++){
                if(is2[i]){
                    acs += 2*i;
                    cout << 2 << " " << i << "\n";
                }else{
                    acs += i;
                    cout << 1 << " " << i << "\n";
                }
            }
        }
    }
}
