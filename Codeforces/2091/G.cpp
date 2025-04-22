#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;
bool v1[N], v0[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll s, k;
        cin >> s >> k;
        if(s % k == 0) cout << k << "\n";
        else{
            if(s >= k*k){
                if(k > 2) cout << k-2 << "\n";
                else cout << 1 << "\n";
            }else{
                //for now we know s < k*k
                //I'm almost sure (k-ans) * s ~ k*k LOL
                for(int i=0;i<=s;i++) v1[i] = false;
                for(int i=k;i<=s;i+=k) v1[i] = true;
                int x = 0;
                for(int i=k-1;i>=1;i--){
                    if(x == 0){
                        for(int j=0;j<=s;j++) v0[j] = false;
                        queue<int> q;
                        for(int j=i;j<=s;j++){
                            if(v1[j]){
                                v0[j-i] = true;
                                q.push(j-i);
                            }
                        }
                        while(!q.empty()){
                            auto u = q.front();
                            q.pop();
                            if(u >= i && v0[u-i] == false){
                                q.push(u-i);
                                v0[u-i] = true;
                            }
                        }
                        if(i == 1) i++;
                    }else{
                        for(int j=0;j<=s;j++) v1[j] = false;
                        queue<int> q;
                        for(int j=0;j<=s-i;j++){
                            if(v0[j]){
                                v1[j+i] = true;
                                q.push(j+i);
                            }
                        }
                        while(!q.empty()){
                            auto u = q.front();
                            q.pop();
                            if(u <= s-i && v1[u+i] == false){
                                q.push(u+i);
                                v1[u+i] = true;
                            }
                        }
                        if(v1[s]){
                            cout << i << "\n";
                            break;
                        }
                    }
                    x ^= 1;
                } 
            }


        }
    }
}
