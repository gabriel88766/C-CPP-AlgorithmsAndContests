#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        map<int,int> mp;
        vector<int> nums;
        int ans=-1, qt = 0, cqt = 0, bans;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            if(!mp[aux]){
                nums.push_back(aux);
            }
            mp[aux]++;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]] >= k){
                if(cqt){
                    if(nums[i-1] == (nums[i]-1)) cqt++;
                    else{
                        cqt = 1;
                        bans = nums[i];
                    }
                }else{
                    cqt = 1;
                    bans = nums[i];
                }
                if(cqt > qt){
                    qt = cqt;
                    ans = bans;
                }
            }else cqt = 0;
        }
        if(!qt){
            cout << "-1\n";
            continue;
        }
        cout << ans << " " << ans + qt - 1 << "\n";

    }
}
