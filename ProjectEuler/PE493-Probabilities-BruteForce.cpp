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
    ll fat[12];
    ll gfat = 1;
    set<int> s;
    for(int i=1;i<=20;i++) s.insert(i);
    for(int i=70;i>=51;i--){
        int mtp = i;
        vector<int> rml, inl;
        for(auto x : s){
            if(gcd(mtp, x) != 1){
                ll g = gcd(mtp, x);
                mtp /= g;
                rml.push_back(x);
                inl.push_back(x/g);
            }
        }
        for(auto x : rml) s.erase(x);
        for(auto x : inl) s.insert(x);
        gfat *= mtp;
    }
    fat[0] = 1;
    for(int i=1;i<=10;i++) fat[i] = fat[i-1] * i;
    double ans = 0;
    for(int a=0;a<=10;a++){
        for(int b=0;b<=10;b++){
            for(int c=0;c<=10 && a+b+c <= 20; c++){
                for(int d=0;d<=10 && a+b+c+d <= 20; d++){
                    for(int e=0;e<=10 && a+b+c+d+e <= 20; e++){
                        for(int f=0;f<=10 && a+b+c+d+e+f <= 20 ;f++){
                            int g = 20 - a - b - c - d - e - f;
                            if(g > 10) continue;
                            int qt = 0;
                            if(a)qt++;
                            if(b)qt++;
                            if(c)qt++;
                            if(d)qt++;
                            if(e)qt++;
                            if(f)qt++;
                            if(g)qt++;
                            ll nx = 1;
                            nx *= (fat[10] / (fat[a] * fat[10-a]));
                            nx *= (fat[10] / (fat[b] * fat[10-b]));
                            nx *= (fat[10] / (fat[c] * fat[10-c]));
                            nx *= (fat[10] / (fat[d] * fat[10-d]));
                            nx *= (fat[10] / (fat[e] * fat[10-e]));
                            nx *= (fat[10] / (fat[f] * fat[10-f]));
                            nx *= (fat[10] / (fat[g] * fat[10-g]));
                            double cp = nx;
                            cp /= gfat;
                            ans += qt * cp;
                        }
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(9) << ans << "\n";
}
