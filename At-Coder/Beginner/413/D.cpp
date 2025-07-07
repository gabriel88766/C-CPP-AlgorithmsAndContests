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
        vector<ll> v(n), xx(n);
        int neg = 0, pos = 0;
        for(int i=0;i<n;i++){
            cin >> xx[i];
            v[i] = abs(xx[i]);
            if(xx[i] < 0) neg++;
            else pos++;
        }
        sort(v.begin(), v.end());
        if(v[0] == v.back()){
            if(neg == n || pos == n || abs(neg - pos) <= 1) cout << "Yes\n";
            else cout << "No\n";
        }else{
            //this case must not have equal nums
            ll q, d;
            q = v[1];
            d = v[0];
            ll g = gcd(q, d);
            q /= g;
            d /= g;
            bool ok = true;
            for(int i=2;i<n;i++){
                ll nq = v[i];
                ll nd = v[i-1];
                ll ng = gcd(nq, nd);
                nq /= ng;
                nd /= ng;
                if(q != nq || d != nd) ok = false;
            }
            if(ok){
                if(neg && pos){
                    vector<ll> rsq(1);
                    q *= -1;
                    for(int i=0;i<n;i++){
                        if(xx[i] == v[0]) rsq[0] = v[0];
                        if(xx[i] == -v[0]) rsq[0] = -v[0];
                    }
                    for(int i=1;i<n;i++){
                        rsq.push_back((rsq.back()*q)/d);
                    }
                    sort(rsq.begin(), rsq.end());
                    sort(xx.begin(), xx.end());
                    if(xx != rsq) ok = false;
                }
                if(ok) cout << "Yes\n";
                else cout << "No\n";
            }else cout << "No\n";
        }
    }
}
 