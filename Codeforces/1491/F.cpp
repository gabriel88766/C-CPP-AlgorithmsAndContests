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
        int cur = 1;
        int diff;
        while(true){
            cout << "? " << 1 << " " << n-cur << "\n";
            cout << cur << "\n";
            for(int i=cur+1;i<=n;i++) cout << i << " ";
            cout << "\n";
            cout.flush();
            int ans;
            cin >> ans;
            if(ans != 0){
                diff = ans;
                break;
            }
            cur++;
            assert(cur <= n);
        }
        int c1 = 0, c2 = 0;
        //cur is N or S
        vector<char> isnull(n+1, false);
        isnull[cur] = false;
        
        for(int i=cur+1;i<=n-1;i++){
            cout << "? " << 1 << " " << 1 << "\n";
            cout << cur << "\n";
            cout << i << "\n";
            cout.flush();
            int ans;
            cin >> ans;
            if(ans == 0) isnull[i] = true;
            else{
                if(ans == 1) c1++;
                else c2++;
            }
        }
        if(abs(c1 - c2) == abs(diff)) isnull[n] = true;
        for(int i=1;i<cur;i++) isnull[i] = true;
        //at most 1 non null from 1 to cur - 1;
        int lo = 1, hi = cur;
        while(hi > lo){
            int mid = lo + (hi - lo) / 2;
            cout << "? " << mid-lo+1 << " " << 1 << "\n";
            for(int i=lo;i<=mid;i++) cout << i << " ";
            cout << "\n" << cur << "\n";
            cout.flush();
            int ans;
            cin >> ans;
            if(ans != 0) hi = mid;
            else lo = mid + 1;
        }
        isnull[lo] = false;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(isnull[i]) ans.push_back(i);
        }
        cout << "! ";
        cout << ans.size() << " ";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
        cout.flush();
    }
}
