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
        ll sum = 0;
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum += v[i];
        }
        int mx = *max_element(v.begin(), v.end());
        int dif = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
        int cnt = 0;
        for(int i=0;i<n;i++) if(mx == v[i]) cnt++;
        if((dif == k+1 && cnt >= 2) ||  dif > k+1) cout << "Jerry\n";
        else{
            if(sum % 2 == 0) cout << "Jerry\n";
            else cout << "Tom\n";
        }
    }
}
