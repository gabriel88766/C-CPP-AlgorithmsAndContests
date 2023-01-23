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
    string N, ans;
    bool onechange = false, isgr = false;
    char minc=0, mincnz=0;
    vector<bool> canuse(10, true);
    int q;
    cin >> N >> q;
    ans = N;
    for(int i=0;i<q;i++){
        int aux;
        cin >> aux;
        canuse[aux] = false;
    }
    for(int i=0;i<10;i++){
        if(canuse[i]){
            if(!minc) minc = i + '0';
            if(i) mincnz = i + '0';
            if(mincnz>0) break;
        }
    }
    for(int i=0;i<ans.size();i++){
        if(onechange){ ans[i] = minc; continue;}
        if(!canuse[ans[i]-'0']){
            while(true){
                for(int j=(ans[i]-'0'+1); j<=9;j++){
                    if(canuse[j]){
                        ans[i] = j+'0';
                        onechange = true;
                        break;
                    }
                }
                if(!onechange){
                    if(i) i--;
                    else{
                        i = ans.size();
                        isgr = true;
                        break;
                    }
                }else break;
            }
        }
    }
    if(isgr){
        cout << mincnz;
        for(int i=0;i<N.size();i++) cout << minc;
    }else{
        cout << ans;
    }

}
