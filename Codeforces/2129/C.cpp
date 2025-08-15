#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string val[13];
int ask(vector<int> v){
    cout << "? ";
    cout << v.size() << " ";
    for(auto x : v) cout << x << " ";
    cout << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //init()
    int sum = 0;
    for(int i=0;i<=12;i++){
        int x = 1 << i;
        for(int j=1;;j++){
            int cur = (j * (j+1)) / 2;
            if(cur <= x && cur + j + 1 > x){
                //here
                int tt = (x - cur + j) * 2 + 1;
                string cs = "(";
                for(int u=0;u<x-cur;u++) cs += '(';
                for(int u=0;u<x-cur;u++) cs += ')';
                cs += ')';
                for(int u=1;u<j;u++) cs += "()";
                cs += ')';
                val[i] = cs;
                break;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        int x = ask(v); //1
        if(x == 0){
            reverse(v.begin(), v.end());
        }
        int lo = 1, hi = n;
        while(lo != hi){ //up to 10
            int mid = lo + (hi - lo + 1)/2;
            vector<int> cur;
            for(int i=0;i<mid;i++) cur.push_back(v[i]);
            if(ask(cur)) hi = mid - 1;
            else lo = mid;
        }
        int xn = v[lo];
        //now I can solve! :D
        string ans(n, '.');

        //up to 89 queries here
        for(int i=1;i<=n;i+=13){
            vector<int> cv;
            for(int j=i;j<=min(n, i+12);j++){
                int x = j - i;
                for(auto x : val[j-i]){
                    if(x == '(') cv.push_back(j);
                    else cv.push_back(xn);
                }
            }
            int as = ask(cv);
            for(int j=i;j<=min(n, i+12);j++){
                int x = j - i;
                if(as & (1 << x)){
                    ans[j-1] = '(';
                }else{
                    ans[j-1] = ')';
                }
            }
        }
        cout << "! " << ans << "\n";
        cout.flush();
    }
}
