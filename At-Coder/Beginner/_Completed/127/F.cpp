#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll cte = 0;
ll sumd = 0;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    set<pair<int,int>> nums;
    pair<int,int> med;
    int ord;
    for(int i=0;i<q;i++){
        int a,b,t;
        cin >> t;
        if(t == 1){
            cin >> a >> b;
            cte += b;
            if(nums.empty()){
                nums.insert({a, i});
                med = {a, i};
                ord = 0;
            }else{
                nums.insert({a, i});
                sumd += abs(a - med.first);
                if(a < med.first) ord++;
                if(ord > (nums.size()-1)/2){
                    int k1 = nums.size() - ord;
                    int k2 = ord; 
                    auto nm = *prev(nums.lower_bound(med));
                    int diff = abs(nm.first - med.first);
                    med = nm;
                    sumd += (ll)diff * (k2-k1);
                    ord--;
                }else if(ord < (nums.size()-1)/2){
                    int k1 = nums.size() - ord-2;
                    int k2 = ord+2; 
                    auto nm = *next(nums.lower_bound(med));
                    int diff = abs(nm.first - med.first);
                    med = nm;
                    sumd += (ll)diff * (k1-k2);
                    ord++;
                }
            }
        }else{
            cout << med.first << " " << sumd+cte << "\n";
        }
        //calc
    }
}
