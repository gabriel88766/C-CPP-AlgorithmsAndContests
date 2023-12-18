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
    int m;
    cin >> m;
    vector<int> cnt(30, 0);
    while(m--){
        int i, n;
        cin >> i >> n;
        if(i == 1){
            cnt[n]++;
        }else{
            vector<int> cur(31, 0);
            for(int i=0;i<30;i++){
                cur[i] += cnt[i];
                if(cur[i] > 2){
                    int d = (cur[i] - 1)/2;
                    cur[i] -= 2*d;
                    cur[i+1] += d;
                }
            }
            bool ok = true;
            for(int i=29;i>=0;i--){
                if(n & (1 << i)){
                    if(!cur[i]){
                        bool cok = false;
                        int ind = -1;
                        for(int j=i-1;j>=0;j--){
                            if(cur[j] == 2){
                                 ind = j;
                                 cok = true;
                                 break;
                            }else if(cur[j] == 1) continue;
                            else break;
                        }   
                        if(cok){
                            for(int j=ind;j<=i-1;j++){
                                cur[j] = 0;
                            }
                        }else{
                            ok = false;
                            break;
                        }
                    }
                }
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
