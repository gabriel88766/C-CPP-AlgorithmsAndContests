#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int sumdigit(int k){
    int ans = 0;
    while(k){
        ans += k%10;
        k /= 10;
    }
    return ans;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        set<int> updt;
        for(int i=1;i<=n;i++) updt.insert(i);
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=0;i<q;i++){
            int a,x,l,r;
            cin >> a;
            if(a == 1){
                cin >> l >> r;
                auto it = updt.lower_bound(l);
                while(it != updt.end() && (*it <= r)){
                    int newv = sumdigit(v[*it]);
                    int val = *it;
                    ++it;
                    if(newv == v[val]){
                        updt.erase(val);
                    }else{
                        v[val] = newv;
                    }
                }
            }else{
                cin >> x;
                cout << v[x] << "\n";
            }   
        }
    }
}
