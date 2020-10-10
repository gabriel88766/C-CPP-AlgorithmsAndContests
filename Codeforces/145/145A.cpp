#include <bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
string a,b;
int SevenI4=0, FourI7=0;
cin >> a >> b;
for(int i=0;i<a.size();i++){
    if(a[i]=='4' && b[i] == '7'){
        SevenI4++;
    }
    if(a[i]=='7' && b[i] == '4'){
        FourI7++;
    }
}
cout << max(SevenI4,FourI7);

}
