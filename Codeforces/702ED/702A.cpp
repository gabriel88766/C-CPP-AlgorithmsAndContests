#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int n,cont=0,maxcont=1,ant=0,cur;
cin >> n;
for(int i=0;i<n;i++){
    cin >> cur;
    if(cur>ant) cont++;
    else{
        maxcont=max(cont,maxcont);
        cont=1;
    }
    ant = cur;
}
maxcont = max(cont,maxcont);
cout << maxcont;


}
