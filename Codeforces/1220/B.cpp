#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[10];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size() - 1;
    for(int i=1;i < s.size();i++){
        int d = s[i] - s[i-1];
        if(d < 0) d += 10;
        if(d > 10) cout << d << endl;
        else cnt[d]++;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            ll ans = 0;
            for(int d = 0; d <= 9; d++){
                if(cnt[d] == 0) continue;
                int bj = -1;
                for(int jmp=1;jmp<=11;jmp++){
                    for(int x = 0; x <= jmp; x++){
                        if((x*i + (jmp-x)*j) % 10 == d){
                            bj = jmp;
                            break;
                        }
                    }
                    if(bj != -1) break;
                }
                if(bj == -1){
                    ans = n-1;
                    break;
                }else{
                    ans += bj * cnt[d];
                }
            }
            cout << ans-n << " ";       
        }
        cout << "\n";
    }
}
