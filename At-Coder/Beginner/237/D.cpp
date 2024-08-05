#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct listn{
    int left = -1, right = -1;
};

listn nums[500006];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    int n;
    cin >> n;
    cin >> s;
    int cur = 0;
    for(auto c : s){
        if(c == 'L'){
            if(nums[cur].left != -1){
                nums[cur+1].left = nums[cur].left;
                nums[nums[cur].left].right = cur + 1;
            }
            nums[cur].left = cur + 1; 
            nums[cur+1].right = cur;
        }else{
            if(nums[cur].right != -1){
                nums[cur+1].right = nums[cur].right;
                nums[nums[cur].right].left = cur + 1;
            }
            nums[cur].right = cur + 1;
            nums[cur+1].left = cur;
        }
        cur++;
    }
    vector<int> ans;
    ans.push_back(0);
    cur = 0;
    if(nums[0].left != -1){
        while(nums[cur].left != -1){
            cur = nums[cur].left;
            ans.push_back(cur);
        }
        reverse(ans.begin(), ans.end());
    }else{
        while(nums[cur].right != -1){
            cur = nums[cur].right;
            ans.push_back(cur);
        }
    }
    for(auto x : ans) cout << x << " ";
}
