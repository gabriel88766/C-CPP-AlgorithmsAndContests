#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
#define ll long long int
//matrix vector<vector<int>> matrix(row,vector<int>(col))

using namespace std;

ll pot[19];
void makepot(){
    ll S;
    for(int i=0;i<19;i++){
        S=1;
        for(int j=0;j<i;j++){
            S*=10;
        }
        pot[i]=S;
    }
}


int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
ll n,S,curn,p;
int s,t,num[19],maxsum;
makepot();
cin >> t;
for(int i=0;i<t;i++){
    label:
    cin >> n >> maxsum;
    curn=n;
    for(int j=18;j>=0;j--){
        if(curn>=pot[j]){
            num[j]=curn/pot[j];
            curn-=((curn/pot[j])*pot[j]);
        }else num[j]=0;
    }
    int Sum=0;
    int j;

    int sumofdigits=0;

        for(int i=0;i<=18;i++){
            sumofdigits+=num[i];
        }
        if(sumofdigits==maxsum){
            cout << "0" << endl;
            i++;
            if(i<t)
            goto label;
            else
            goto endlabel;
        }



     for(j=18;j>=0;j--){
       if((Sum+num[j])<maxsum){
            Sum+=num[j];
       }else{
            j++;
            break;
       }
    }
    p=0;
    for(int i=0;i<j;i++){
        p+=num[i]*pot[i];
    }
    cout << pot[j]-p << endl;
}
endlabel:
return 0;
}
 