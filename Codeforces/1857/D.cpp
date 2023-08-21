#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> a, b;
bool cmp(int u, int v){
    if(a[u] - a[v] > b[u] - b[v]) return true;
    else return false;
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
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            b.push_back(x);
        }
        vector<int> xx;
        for(int i=0;i<n;i++) xx.push_back(i);
        sort(xx.begin(), xx.end(), cmp);
        int lo = 0, hi = n-1, mid;
        while(lo != hi){
            mid = lo + (hi - lo + 1)/2;
            bool cond = true;
            for(int i=0;i<mid;i++){
                int ind1 = xx[mid], ind2 = xx[i];
                if(a[ind1] - a[ind2] < b[ind1] - b[ind2]){
                    cond = false;
                    break;
                }
            }
            if(cond) lo = mid;
            else hi = mid - 1;
        }
        cout << lo+1 << "\n";
        vector<int> ans;
        for(int i=0;i<=lo;i++) ans.push_back(xx[i]+1);
        sort(ans.begin(), ans.end());
        for(auto x : ans) cout << x << " ";
        cout << "\n";
        a.clear();
        b.clear();
    }
}
