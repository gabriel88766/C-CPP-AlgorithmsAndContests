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
        vector<int> v(n), ans;
        for(int i=0;i<n;i++) cin >> v[i];
        int pos = 1, maxv = 0;
        for(int i=1;i<n;i++){
            if(v[i] > maxv){
                maxv = v[i];
                pos = i;
            }
        }
        for(int i=pos;i<n;i++) ans.push_back(v[i]);

        if(n == 1){
            ans.push_back(1);
        }
        else if(pos == (n-1)){
            if(v[pos-1] > v[0]){
                ans.push_back(v[pos-1]);
                int p = pos - 2;
                while(p > 0 && v[p] > v[0]){
                    ans.push_back(v[p]);
                    p--;
                }
                for(int i=0;i<=p;i++) ans.push_back(v[i]);
            }else{
                for(int i=0;i<pos;i++)ans.push_back(v[i]);
            }
        }else{
            ans.push_back(v[pos-1]);
            int p = pos - 2;
            while(p > 0 && v[p] > v[0]){
                ans.push_back(v[p]);
                p--;
            }
            for(int i=0;i<=p;i++) ans.push_back(v[i]);
        }


        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
