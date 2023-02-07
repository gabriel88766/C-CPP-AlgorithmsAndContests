#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i=0; i<n;i++) cin >> v[i];

        int cnt, maxcnt=1;
        for(int i=0;i<n;i++){
            for(int j=(i+1);j<n;j++){
                ll diff = v[j] - v[i], a, b, x;
                for(int k=1;k<32000;k++){
                    if(!(diff % k)){
                        if(k % 2){
                            b = diff/k;
                            a = k/2 * 2;
                            if(!(b % 2)) continue;
                            if((b-a) <= 0) break; //lowest num
                            b += a; //highest; 2k-1, diff k (k-1)^2, v[j] + x = k^2
                        }else{
                            b = diff/k+1;
                            if((b - k) <= 0) break;
                            if(!(b % 2 )) continue;
                            b += (k-2);
                        }
                        b /= 2;
                        b++;
                        x = b*b - v[j];
                        if(x < 0) continue;
                        cnt = 2;
                        for(int w = (j+1); w<n;w++){
                            ll d = sqrt(x + v[w]);
                            if(d*d == (x+v[w])) cnt++;
                        }
                        maxcnt = max(cnt,maxcnt);
                    }
                }
            }
        }


        cout << maxcnt << "\n";
    }
}
