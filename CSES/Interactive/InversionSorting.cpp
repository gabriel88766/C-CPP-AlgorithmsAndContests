#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll rev(int l, int r){
    cout << l << " " << r << "\n";
    cout.flush();
    ll ans;
    cin >> ans;
    return ans;
}
const int N = 1005;
int gr[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    ll val = rev(1, n);
    if(val != 0){
        ll lv = val;
        for(int i=n-1;i>=1;i--){
            ll nv = rev(i, n);
            if(nv == 0){
                val = 0;
                break;
            }
            // from -(n-i) to n-i
            ll ttn = n - i; //greater + lesser
            ll dd = (nv - lv); //greater - lesser
            ll cur = (ttn + dd)/2;
            assert((ttn + dd) % 2 == 0);
            gr[i] = cur;
            lv = nv;
            rev(i, n);
        }
    }
    if(val){
        set<int> s;
        for(int i=1;i<=n;i++) s.insert(i);
        vector<int> perm(n+1);
        for(int i=1;i<=n;i++){
            auto it = prev(s.end());
            while(gr[i]--) --it;
            perm[i] = *it;
            s.erase(it);
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(perm[j] == i){
                    if(i != j){
                        rev(i, j);
                        reverse(perm.begin() + i, perm.begin() + j + 1);
                    }
                    break;
                }
            }
        }
    }

    return 0;
}
