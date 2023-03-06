#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool found[1005];
char ans[1005];
int val[1005];
int fst[26], lst[26];
int n;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    int cur = 0;
    int ansq;
    char ansc;
    for(int i=1;i<=n;i++){
        cout << "? 2 1 " << i << "\n";
        cout.flush();
        cin >> ansq;
        val[i] = ansq;
        if(ansq > cur){
            cur = ansq;
            fst[cur] = i;
            cout << "? 1 " << i << "\n";
            cout.flush();
            cin >> ansc;
            found[i] = true;
            ans[i] = ansc;
        }
    }
    for(int i=1;i<=n;i++){
        if(found[i]) continue;
        else{
            if(val[i] == 1){
                ans[i] = ans[1];
            }else{
                int lo = 1, hi = val[i];
                while(lo != hi){
                    int mid = (hi+lo)/2;
                    int cnt = 0;
                    map<char,int> mp;
                    int ind;
                    for(int j=(i-1);j>=1;j--){
                        if(!mp[ans[j]]) cnt++;
                        mp[ans[j]]++;
                        if(cnt == mid){
                            ind = j;
                            break;
                        }
                    }
                    cout << "? 2 " << ind << " " << i << "\n";
                    cout.flush();
                    cin >> ansq;
                    if(ansq == mid) hi = mid;
                    else lo = mid + 1;
                }
                map<char,int> mp;
                int cnt = 0;
                for(int j=(i-1);j>=1;j--){
                    if(!mp[ans[j]]) cnt++;
                    mp[ans[j]]++;
                    if(cnt == lo){
                        ans[i] = ans[j];
                        break;
                    }
                }
            }
        }
    }

    cout << "! ";
    for(int i=1;i<=n;i++) cout << ans[i];
    cout.flush();
}
