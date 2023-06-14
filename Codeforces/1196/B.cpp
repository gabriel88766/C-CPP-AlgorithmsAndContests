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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        vector<int> indx;
        for(int i=0;i<n;i++){
            if(v[i]%2) indx.push_back(i);
        }
        int sz = indx.size();
        if((sz-k)%2 || sz < k){
            cout << "NO\n";
        }else{
            //Yep!
            int x = sz+1-k;
            cout << "YES\n";
            for(int i=x-1;i<sz-1;i++){
                cout << indx[i]+1 << " ";
            }
            cout << n << "\n";
        
        }
    }
}
