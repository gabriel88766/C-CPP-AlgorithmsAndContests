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
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int sz = r-l+1;
        vector<int> v(r-l+1);
        int sum = 0;
        for(int i=0;i<sz;i++){
            v[i] = i+1;
            sum += v[i];
        }
        if(sum > s) cout << "-1\n";
        else{
            int sm = n-sz;
            for(int i=sz-1;i>=0;i--){
                if(sum + sm <= s){
                    v[i] += sm;
                    sum += sm;
                }else{
                    int qt = s - sum;
                    v[i] += qt;
                    sum += qt;
                }
            }
            if(sum < s) cout << "-1\n";
            else{
                vector<bool> used(n+1, false);
                for(int i=0;i<sz;i++) used[v[i]] = true;
                int p = 1;
                for(int i=1;i<=n;i++){
                    if(i>=l && i<=r){
                        cout << v[i-l] << " ";
                    }else{
                        while(used[p]) p++;
                        used[p] = true;
                        cout << p << " ";
                    }
                }
                cout << "\n";
            }
            
        }
    }
}
