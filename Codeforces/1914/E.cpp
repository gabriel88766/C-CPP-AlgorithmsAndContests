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
        vector<pair<int,int>> sum(n);
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++){
             cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        for(int i=0;i<n;i++){
            sum[i] = {a[i]+b[i], i};
        }
        sort(sum.begin(), sum.end(), greater<pair<int,int>>());
        vector<int> type(n);
        for(int i=0;i<n;i++){
            if(i % 2){
                type[sum[i].second] = 2;
            }else{
                type[sum[i].second] = 1;
            }
        }
        ll s1 = 0, s2 = 0;
        for(int i=0;i<n;i++){
            if(type[i] == 1){
                s1 += a[i] - 1;
            }else{
                s2 += b[i] - 1;
            }
        }
        cout << s1 - s2 << "\n";
    }
}
