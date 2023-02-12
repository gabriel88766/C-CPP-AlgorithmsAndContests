#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Val{
    int i, j, val;
};

bool cmp(Val &a, Val &b){
    if(a.val != b.val) return a.val < b.val;
    else return a.j < b.j;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, ver, ans;
        vector<Val> v;
        cin >> n;
        //solve...
        if(n == 2){
            cout << "? 1 2\n";
            cout.flush();
            cin >> ans;
            cout << "! 1 2\n";
            cout.flush();
            cin >> ver;
            if(ver == 1) continue;
            else return 0;
        }
        cout << "? " << n << " " << 1 << "\n";
        cout.flush();
        cin >> ans;
        int bp = 0;
        if(ans == 1){
            while(ans == 1){
                cout << "? " << bp+1 << " " << bp+2 << "\n";
                cout.flush();
                cin >> ans;
                bp++;
            }
        }
        //0 in range bp to n
        int l, r, x;
        if(bp == 0){ 
            l = 2;
            r = n-1;
            v.push_back({1, n, ans});
            bp = 1;
        }else if(bp == 1){
            l = bp+2;
            r = n-1;
            v.push_back({1, 2, ans});
        }else if(bp != (n-1)){
            l = bp+2;
            r = n;
            v.push_back({bp, bp+1, ans});
        }else{
            cout << "! " << n-1 << " " << n << "\n";
            cout.flush();
            cin >> ver;
            if(ver == 1) continue;
            else return 0;
        }
        stack<int> nums;
        for(int i=l; i<=r;i++) nums.push(i);
        while(true){
            while(!nums.empty()){
                cout <<"? "<<  bp << " " << nums.top() << "\n";
                cout.flush();
                cin >> ans;
                v.push_back({bp, nums.top(), ans});
                nums.pop();
            }
            sort(v.begin(), v.end(), cmp);
            int maxv = v[v.size()-1].val;
            for(int i=v.size()-1;i>=0;i--){
                if(v[i].val == maxv) nums.push(v[i].j);
                else break;
            }
            if(nums.size() == 1){
                nums.push(bp);
                break;
            }
            if(nums.size() == 2) break;
            bp = nums.top();
            nums.pop();
        }
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        
        cout <<  "! " << a <<  " " << b << "\n";
        cout.flush();
        


        //check if ok.
        cin >> ver;
        if(ver == 1) continue;
        else return 0;
    }
}
