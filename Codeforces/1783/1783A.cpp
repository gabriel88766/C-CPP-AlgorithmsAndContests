#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    vector<int> v(105);
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(),v.begin()+n, greater<int>());
        swap(v[1], v[n-1]);
        if(v[0] != v[1]){
            cout << "YES\n";
            for(int i=0;i<n;i++) cout << v[i] << " ";
            cout << "\n";
        }else cout << "NO\n";

    }
}
