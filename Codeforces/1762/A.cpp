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
        int n, sum = 0, minc = 1000;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum += v[i];
            int aux = v[i], cnt = 0;
            bool od = false, ev = false;
            if(v[i] % 2) od = true;
            else ev = true;
            while(aux){
                aux /= 2;
                cnt++;
                if(aux % 2) od = true;
                else ev = true;
                if(od && ev){
                    break;
                }
            }
            minc = min(minc, cnt);
        }
        if(sum % 2) cout << minc << "\n";
        else cout << "0\n";
    }
}
