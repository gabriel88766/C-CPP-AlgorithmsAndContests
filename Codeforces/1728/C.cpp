#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int len(int n){
    int ans = 0;
    while(n){
        ans++;
        n /= 10;
    }
    return ans;
}

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
        multiset<int> m1, m2;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            m1.insert(x);
        }
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            m2.insert(x);
        }
        int ans = 0;
        while(m1.size() && m2.size()){
            auto x = *prev(m1.end());
            auto y = *prev(m2.end());
            if(x == y){
                m1.erase(prev(m1.end()));
                m2.erase(prev(m2.end()));
            }else if(x > y){
                ans++;
                m1.erase(prev(m1.end()));
                m1.insert(len(x));
            }else{
                ans++;
                m2.erase(prev(m2.end()));
                m2.insert(len(y));
            }
        }
        cout << ans << "\n";
    }
}
