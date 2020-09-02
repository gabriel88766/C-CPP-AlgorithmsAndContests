#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int n,len,aux,bp,ep,cur,old,ans;
char flag;
cin >> n;
vector<int> v;
v.reserve(200000);
for(int i=0;i<n;i++){
    cin >> len;
    v.clear();
    bp = 0;
    ep = len - 1;
    for(int j=0;j<len;j++){
        cin >> aux;
        v.push_back(aux);
    }
    cur = 0;
    ans = 0;
    while(bp != ep){
        old = cur;
        if(v[bp] <= v[ep]){
            cur = v[bp];
            flag = true;
        }else{
            cur = v[ep];
            ep--;
            flag = false;
        }

        if(cur < old){
            ep = len - 1;
            cur = 0;

            if(!flag) bp++;
            ans = bp;
        }else if (flag) bp++;
    }
    cout << ans << endl;
}

}
