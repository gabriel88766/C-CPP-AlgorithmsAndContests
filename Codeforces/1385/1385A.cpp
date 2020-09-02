#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int n,x,y,z,maxnum,minnum;
cin >> n;
for(int i=0;i<n;i++){
    cin >> x >> y >> z;
    maxnum = max(x,max(y,z));
    minnum = min(x,min(y,z));
    if((x==y && x!=z && maxnum>z)||(x==z && x!=y && maxnum>y)||(y==z && x!=z && maxnum>x)) {
            cout << "YES" << endl;
            cout << maxnum <<" "<< minnum <<" "<< 1 << endl;
    }else if(x == y && y == z){
            cout << "YES"<<endl;
            cout << x << " " << x << " " << x << endl;
    }else cout << "NO" << endl;
}

}
