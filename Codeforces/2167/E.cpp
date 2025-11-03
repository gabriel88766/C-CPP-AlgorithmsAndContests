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
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int lo = 0, hi = x;
        while(lo != hi){
            int mid = lo + (hi - lo + 1) / 2;
            int tt = 0;
            //0 to first
            if(v[0] >= mid) tt += v[0] - mid + 1;
            //last to x;
            if(x - v.back() >= mid) tt += x - v.back() - mid + 1;
            for(int i=1;i<n;i++){
                if(v[i] - v[i-1] >= 2*mid) tt += (v[i] - v[i-1] - 2*mid + 1); 
            }
            if(tt >= k) lo = mid;
            else hi = mid - 1;
        }
        if(lo == 0){
            for(int j=0;j<k;j++) cout << j << " ";
            cout << "\n";
            continue;
        }
        vector<int> ans;
        auto addVal = [&](int val){
            if(ans.size() < k){
                ans.push_back(val);
                return true;
            }else return false;
        };
        
        for(int i=0;i<=v[0]-lo;i++){
            if(addVal(i)) continue;
            else break;
        }
        
        for(int i=1;i<n;i++){
            for(int j=v[i-1]+lo;j<=v[i]-lo;j++){
                if(addVal(j)) continue;
                else break;
            }
        }
        for(int i=v.back() + lo; i<=x;i++){
            if(addVal(i)) continue;
            else break;
        }
        for(auto x : ans) cout << x << " ";
        cout << "\n";
        

    }
}
