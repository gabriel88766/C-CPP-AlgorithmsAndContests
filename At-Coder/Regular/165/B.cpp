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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    //possibility 1
    int cnt = 1;
    int maxv = 0;
    for(int i=1;i<n;i++){
        if(v[i] > v[i-1]){
            cnt++;
        }else{
            maxv = max(cnt, maxv);
            cnt = 1;
        }
    }
    maxv = max(cnt, maxv);
    if(maxv >= k){
        for(int i=0;i<n;i++) cout << v[i] << " ";
        cout << "\n";
    }else{
        //something will change
        int s = INF_INT;
        int p = n - k;
        while(p-1 >= 0 && v[p-1] < s){
            p--;
            s = v[p];
        }
        if(p != n-k && v[n-k-1] < *min_element(v.begin() + n - k, v.begin() + p + k)){
            sort(v.begin() + p, v.begin()+p+k);
        }else{
            sort(v.begin() + n - k, v.begin()+n);
        }
        
        for(int i=0;i<n;i++) cout << v[i] << " ";
        cout << "\n";
    }
}
