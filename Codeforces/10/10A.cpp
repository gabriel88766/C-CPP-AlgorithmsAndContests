#include <bits/stdc++.h>
 
using namespace std;
 
int pointer = 0;
string s;
 
int l[105],r[105];
int n;
 
 
int main() {
    int a,b,c,mini,maxi,bp=0,ans=0;
    int t1,t2;
    cin >> n >> a >> b >> c >> t1 >> t2;
    for(int i=0;i<n;i++){
        cin >> l[i] >> r[i];
    }
    mini = l[0];
    maxi = r[n-1];
    while(bp<n){
        if(bp!=0){
            int totalT = l[bp] - r[bp-1];
            if(totalT > t1){
                ans+= t1*a;
                totalT-=t1;
                if(totalT > t2){
                    ans+= t2*b;
                    totalT-=t2;
                    ans += totalT*c;
                }else{
                    ans+= totalT*b;
                }
            }else{
                ans += totalT * a;
            }
        }
        ans+= a*(r[bp]-l[bp]);
        bp++;
    }
    cout << ans;
    
}