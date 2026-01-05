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
        int ce = 0, co = 0;
        vector<int> ne, no;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(x % 2){
                co++;
                no.push_back(x);
            }else{
                ce++;
                ne.push_back(x);
            }
        }
        sort(ne.begin(), ne.end(), greater<int>());
        sort(no.begin(), no.end(), greater<int>());
        if(co == 0){
            for(int i=0;i<n;i++) cout << "0 ";
            cout << "\n";
        }else if(ce == 0){
            for(int i=1;i<=n;i++){
                if(i % 2) cout << no[0] << " ";
                else cout << "0 ";
            }
            cout << "\n";
        }else{
            vector<ll> ans(n+1);
            sort(ne.begin(), ne.end(), greater<int>());
            sort(no.begin(), no.end(), greater<int>());
            ans[1] = no[0];
            for(int i=1;i<=ne.size();i++){
                ans[i+1] = ans[i];
                ans[i+1] += ne[i-1];
            }
            //1 ne
            //3 ne-1
            //3 ne
            //5 ne-1
            for(int i=ne.size()+2;i<=n;i++){
                ans[i] = ans[i-1];
                if((i-ne.size()) % 2 == 0) ans[i] -= ne.back();
                else ans[i] += ne.back();
            }
            if(co % 2 == 0) ans[n] = 0;
            for(int i=1;i<=n;i++) cout << ans[i] << " ";
            cout << "\n";
            
        }
    }
}
