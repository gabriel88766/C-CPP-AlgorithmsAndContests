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
        string s;
        cin >> n >> s;
        bool rr = false, bb = false;
        for(int i=0;i<n;i++){
            if(s[i] == 'B' && s[(i+1)%n] == 'B') bb = true;
            if(s[i] == 'R' && s[(i+1)%n] == 'R') rr = true;
        }
        if(bb && rr){
             cout << "NO\n";
             continue;
        }else if(rr){
            //make it bb
            for(int i=0;i<n;i++){
                if(s[i] == 'B') s[i] = 'R';
                else s[i] = 'B';
            }
        }
        int fr = -1;
        for(int i=0;i<n;i++){
            if(s[i] == 'R'){
                fr = i;
                break;
            }
        }
        if(fr == -1){
            cout << "YES\n";
            continue;
        }else{
            if(fr != 0) s = s.substr(fr, s.size() - fr) + s.substr(0, fr);
        }
        vector<int> nums;
        int cb = 0;
        for(int i=1;i<n;i++){
            if(s[i] == 'B') cb++;
            else{
                assert(cb != 0);
                nums.push_back(cb%2);
                cb = 0;
            }
        }
        nums.push_back(cb%2);
        int co = 0, ce = 0;
        for(auto x : nums){
            if(x == 0) ce++;
            else co++;
        }
        if(ce >= 2) cout << "NO\n";
        else if(ce == 0 && co > 1) cout << "NO\n";
        else cout << "YES\n";
            
        
    }
}
