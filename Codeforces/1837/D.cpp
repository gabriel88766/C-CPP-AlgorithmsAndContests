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
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '(') cnt++;
            else cnt--;
        }
        if(cnt != 0) cout << "-1\n";
        else{
            int minv1 = 0, cnt1 = 0, minv2 = 0, cnt2 = 0, ind;
            for(int i=0;i<n;i++){
                if(s[i] == '(') cnt1++;
                else cnt1--;
                minv1 = min(minv1, cnt1);
                if(minv1 == cnt1) ind = i;
            }
            for(int i=n-1;i>=0;i--){
                if(s[i] == '(') cnt2++;
                else cnt2--;
                minv2 = min(minv2, cnt2);
            }
            if(max(minv1, minv2) >= 0){
                cout << "1\n";
                for(int i=0;i<n;i++) cout << "1 ";
                cout << "\n";
            }else{
                cout << "2\n";
                vector<bool> is2(n, false);
                int c = 0;
                for(int i=0;i<=ind;i++){
                    if(s[i] == ')' && c < abs(minv1)){
                        c++;
                        is2[i] = true;
                    }
                }
                c = 0;
                for(int i=n-1;i>=ind+1;i--){
                    if(s[i] == '(' && c < abs(minv1)){
                        c++;
                        is2[i] = true;
                    }
                }
                for(int i=0;i<n;i++){
                    if(is2[i]) cout << "2 ";
                    else cout << "1 ";
                }
                cout << "\n";
            }
        }
    }
}
