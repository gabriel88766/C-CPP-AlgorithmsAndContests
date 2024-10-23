#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 130;
int lp[N];
int pos[N];
int msk[N];
int cnt = 0;
void sieve(){
    for(int i=2;i<N;i++){
        if(!lp[i]){
            pos[i] = cnt++;
            for(int j=i;j<N;j+=i){
                if(!lp[j]) lp[j] = i;
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
    for(int i=1;i<N;i++){
        int aux = i;
        int m = 0;
        while(aux != 1){
            m ^= (1 << pos[lp[aux]]);
            aux /= lp[aux];
        }
        msk[i] = m;
    }
    
    for(int i=2;i<N;i++) msk[i] ^= msk[i-1];
    int mp = 0;
    for(int i=1;i<N;i++){
        mp ^= msk[i];
        if(mp == 0) cout << i << " : " << 0 << endl;
        else{
            cout << i << " : ";
            bool ok = false;
            for(int j=1;j<=i;j++){
                if(msk[j] == mp){
                    cout << "1 " << j << endl;
                    ok = true;
                    break;
                }
            }
            if(ok) continue;
            for(int j=1;j<=i;j++){
                for(int k=j+1;k<=i;k++){
                    if((msk[j] ^ msk[k]) == mp){
                        cout << 2 << " " << j << " " << k << endl;
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            if(ok) continue;
            for(int j=1;j<=i;j++){
                for(int k=j+1;k<=i;k++){
                    for(int u=k+1;u<=i;u++){
                        if((msk[j] ^ msk[k] ^ msk[u]) == mp){
                            cout << 3 << " " << j << " " << k << " " << u << endl;
                            ok = true;
                            break;
                        }
                    }
                    if(ok) break;
                }
                if(ok) break;
            }
            if(!ok) cout << "not found" << endl;
        }
    }
}
