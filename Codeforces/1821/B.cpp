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
        int fi = -1, li = -1;
        for(int i=0;i<n;i++){
            if(a[i] != b[i]){
                if(fi == -1) fi = i;
                li = i;
            }
        }
        if(fi == -1){
            pair<int,int> ans = {1, 1};
            int mv = 1, l = 0;
            for(int i=1;i<n;i++){
                if(b[i] < b[i-1]){
                    int len = i - l;
                    if(len > mv){
                        mv = len;
                        ans = {l+1, i};
                    }
                    l = i;
                }
            }
            int len = n - l;
            if(len > mv){
                ans = {l+1, n};
            }
            cout << ans.first << " " << ans.second << "\n";
        }else{
            int mine = *min_element(b.begin() + fi, b.begin() + li + 1);
            int maxe = *max_element(b.begin() + fi, b.begin() + li + 1);
            while(fi > 0 && b[fi-1] <= mine){
                fi--;
                mine = b[fi];
            }
            while(li + 1 < n && b[li+1] >= maxe){
                 li++;
                 maxe = b[li];
            }
            cout << fi+1 << " " << li+1 << "\n";
        }
    }
}
