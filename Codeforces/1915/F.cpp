#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll ans = 0;
void mergesort(vector<int> &v, int a, int b){
    if(a == b) return;
    else{
        int mid = (a + b)/2;
        mergesort(v, a, mid);
        mergesort(v, mid+1, b);
        int pv1 = a, pv2 = mid+1;
        int aux[b-a+1];
        for(int i=a;i<=b;i++){
            if(pv1 <= mid && pv2 <= b){
                if(v[pv1] <= v[pv2]){
                    aux[i-a] = v[pv1++];
                    //lower than every element from i:[pv2, b];
                }else{
                    aux[i-a] = v[pv2++];
                    //every element v[i] from i:[pv1, mid] is greater than v[pv2]
                    ans += mid - pv1 + 1;
                }
            }else if(pv1 > mid){
                aux[i-a] = v[pv2++];
                //every inversion was counted
            }else{
                aux[i-a] = v[pv1++];
                //every inversion was counted
            }
        }
        for(int i=a;i<=b;i++){
            v[i] = aux[i-a];
        }
    }
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
        vector<pair<int,int>> in(n);
        for(int i=0;i<n;i++) cin >> in[i].first >> in[i].second;
        sort(in.begin(), in.end());
        ans = 0;
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i] = in[i].second;
        mergesort(v, 0, n-1);
        cout << ans << "\n";
    }
}
