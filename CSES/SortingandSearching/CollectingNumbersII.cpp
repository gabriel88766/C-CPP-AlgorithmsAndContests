#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+4;
int mp[N];
int v[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, cnt = 0, j=0, m;
    cin >> n >> m;
    for(int i=1; i<=n;i++){
        int aux;
        cin >> aux;
        mp[aux] = i;
        v[i] = aux;
    }

    while(j < n){
        cnt++;
        j++;
        while(j < n){
            if(mp[j+1] > mp[j]){
                j++;
            }else{
                break;
            }
        }
    }

    for(int i=1; i<=m;i++){
        int j, k;
        char doublecountj=false, doublecountk=false;
        cin >> j >> k;
        //change cnt value
        if(abs(v[j]-v[k]) == 1){
            if(v[j] > v[k]) doublecountj = true;
            else doublecountk = true;
        }
        if(v[j] != 1){
            if(mp[v[j]-1] <= k && mp[v[j]-1] >= j) if(!doublecountj)cnt--;
            if(mp[v[j]-1] >= k && mp[v[j]-1] <= j) if(!doublecountj)cnt++;
        }
        if(v[j] != n){
            if(mp[v[j]+1] <= k && mp[v[j]+1] >= j) cnt++;
            if(mp[v[j]+1] >= k && mp[v[j]+1] <= j) cnt--;
        }
        if(v[k] != 1){
            if(mp[v[k]-1] <= j && mp[v[k]-1] >= k) if(!doublecountk)cnt--;
            if(mp[v[k]-1] >= j && mp[v[k]-1] <= k) if(!doublecountk)cnt++;
        }
        if(v[k] != n){
            if(mp[v[k]+1] <= j && mp[v[k]+1] >= k) cnt++;
            if(mp[v[k]+1] >= j && mp[v[k]+1] <= k) cnt--;
        }

        //swap op
        swap(mp[v[j]], mp[v[k]]);
        swap(v[j], v[k]);
        cout << cnt << endl;
    }

    
}
