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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> x = {0};
    for(int i=1;i<n;i++){
        cin >> v[i];
        x.push_back(x.back() ^ v[i]);
    }
    sort(x.begin(), x.end());
    int ans = 0;

    int l = 0, r = n-1;
    for(int j=20;j>=0;j--){
        bool b1 = false, b2 = false;
        if(x[l] & (1 << j)) b1 = true;
        if(x[r] & (1 << j)) b2 = true;
        int m = r;
        if(b1 && b2){
            ans ^= (1 << j);
            continue;
        }
        if(!b1 && !b2) continue;
        if(b2){
            //!b1 && b2, impossible b1 && !b2
            m = l;
            for(int k=(r-l+1)/2; k>= 1; k>>=1){
                while(m+k <= r && !(x[m+k] & (1 << j))) m += k;
            }
            
        }
        if(r-m >= (m-l+1)){
            r = m;
            ans ^= (1 << j);
        }else{
            l = m+1;
        }
    }
    cout << ans << " ";
    for(int i=1;i<n;i++){
        ans ^= v[i];
        cout << ans << " ";
    }
    cout << "\n";
}
