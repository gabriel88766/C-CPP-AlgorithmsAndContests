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
        //ultramotherfuckin brute force
        vector<string> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        bool oksq = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=2;k<=n;k++){
                    if(i+k > n || j+k > n) break;
                    bool okc = true;
                    for(int u=0;u<n;u++){
                        for(int w=0;w<n;w++){
                            if(u >= i && u <= (i+k-1) && w >= j && w <= (j+k-1)){
                                if(v[u][w] == '0') okc = false;
                            }else if(v[u][w] == '1') okc = false;
                        }
                    }
                    if(okc) oksq = true;
                }
            }
        }

        if(oksq) cout << "SQUARE\n";
        else cout << "TRIANGLE\n";
    }
}
