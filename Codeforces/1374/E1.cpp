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
    int n, k;
    cin >> n >> k;
    multiset<int> a, b, c;
    for(int i=0;i<n;i++){
        int t, x1, x2;
        cin >> t >> x1 >> x2;
        if(x1 == 1 && x2 == 1){
            c.insert(t);
        }else if(x1 == 1){
            a.insert(t);
        }else if(x2 == 1){
            b.insert(t);
        }
    }
    int ans = 0, cnt = 0;
    bool ok = true;
    while(cnt < k){
        if(c.size() && a.size() && b.size()){
            int sum1 = *a.begin() + *b.begin();
            int sum2 = *c.begin();
            if(sum1 < sum2){
                ans += sum1;
                a.erase(a.begin());
                b.erase(b.begin());
            }else{
                ans += sum2;
                c.erase(c.begin());
            }
            cnt++;
        }else if(a.size() && b.size()){
            ans += *a.begin() + *b.begin();
            a.erase(a.begin());
            b.erase(b.begin());
            cnt++;
        }else if(c.size()){
            ans += *c.begin();
            c.erase(c.begin());
            cnt++;
        }else break;
    }
    if(cnt == k) cout << ans << "\n";
    else cout << "-1\n";
}
