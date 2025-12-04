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
    freopen("snake_scales_chapter_2_input.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout); //test input
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        vector<int> v(n+1, 0);
        for(int j=1;j<=n;j++){
            cin >> v[j];
        }
        int lo = 1, hi = 1'000'000'000;
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            vector<bool> ok(n+1, false);
            for(int j=1;j<=n;j++){
                if(v[j] <= mid) ok[j] = true;
            }
            for(int j=2;j<=n;j++){
                if(ok[j]) continue;
                if(abs(v[j] - v[j-1]) <= mid && ok[j-1]) ok[j] = true;
            }
            for(int j=n-1;j>=1;j--){
                if(ok[j]) continue;
                if(abs(v[j] - v[j+1]) <= mid && ok[j+1]) ok[j] = true;
            }
            bool isok = true;
            for(int j=1;j<=n;j++) if(!ok[j]) isok = false;
            if(isok) hi = mid;
            else lo = mid + 1;
        }
        cout << "Case #" << i << ": " << lo << "\n";
    }
}
