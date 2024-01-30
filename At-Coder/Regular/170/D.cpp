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
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool ok = false;
        vector<bool> ok1(n, false), ok2(n, false);
        for(int i=0;i<n;i++){
            //case 1 : b[j] <= a[i];
            if(b[0] > a[i]) ok1[i] = true;
            else{
                int dnxt = INF_INT;
                if(i != 0) dnxt = min(dnxt, a[i] - a[i-1]);
                if(i != (n-1)) dnxt = min(dnxt, a[i+1] - a[i]);
                if(dnxt < b[0]) ok1[i] = true;
            }
        }
        //case 2 : b[j] > a[i]; binsearch
        int lo = 0, hi = n;
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            bool ok = true;
            int p = 0;
            for(int i=0;i<n;i++){
                if(a[mid] >= b[i]) continue;
                //check if there is a[j] between b[i] - a[mid] and b[i] + a[mid]
                while(p < n && a[p] <= b[i] - a[mid]) p++;
                if(p == mid) p++;
                if(p == n || a[p] >= b[i] + a[mid]) ok = false;
            }
            if(ok) hi = mid;
            else lo = mid + 1;
        }
        for(int i=lo;i<n;i++) ok2[i] = true;

        for(int i=0;i<n;i++) if(ok1[i] && ok2[i]) ok = true;
        if(ok) cout << "Alice\n";
        else cout << "Bob\n";
    }
}
