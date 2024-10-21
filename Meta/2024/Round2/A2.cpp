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
    freopen("in.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout); //test input
    vector<string> vs[9];
    vector<ll> nums;
    vs[0].push_back("");
    int cnt = 0;
    for(int i=1;i<=99'999'999;i++){
        auto str = to_string(i);
        bool ok = true;
        char lg = '0';
        for(auto c : str){
            if(c < lg) ok = false;
            lg = c;
        }
        if(str.back() == '9') ok = false;
        if(ok){
            cnt++;
            vs[str.size()].push_back(str);
        }
    }
    for(int i=1;i<=9;i++) nums.push_back(i);
    for(int i=1;i<=8;i++){
        for(auto str1 : vs[i]){
            for(auto str2 : vs[i]){
                for(char c = max(str1.back(), str2.back())+1;c<='9';c++){
                    auto aux = str2;
                    reverse(aux.begin(), aux.end());
                    string cur = str1 + c + aux;
                    nums.push_back(stol(cur));
                    
                }
            }
        }
    }
    sort(nums.begin(), nums.end());
    
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        ll A, B, M;
        cin >> A >> B >> M;
        ll ans = 0;
        for(int i=0;i<nums.size();i++){
            if(A <= nums[i] && B >= nums[i]){
                if(!(nums[i] % M)) ans++;
            }
        }   
        cout << "Case #" << i << ": " << ans << "\n";
    }
}
