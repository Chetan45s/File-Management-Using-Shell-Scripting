/*

Link : https://www.spoj.com/problems/AGGRCOW/

*/



#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
using ll = long long;
using ld = long double;
using namespace std::chrono; 
#define fo(i,z,n) for(int i = z;i<n;i++)
#define Fo(i,z,n) for(ll i = z;i<n;i++)
#define INT_BITS 32
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> > 
#define pb push_back
#define int long long
#define float long double
#define all(c) (c).begin(), (c).end()
#define endl '\n'
#define pi 3.14159265358979323846

int pow(int a,int b){
	if(b == 0)return 1;
	int res = pow(a,b/2);
	res = res*res;
	if(b&1)res *= a;
	return res;
}

bool check(int a[],int v,int n,int cows){
    int s = 1;
    int start = a[0];
    fo(i,1,n){
        if((a[i]-start) >= v){
            s++;
            start = a[i];
        }
        if(s == cows){
            return true;
        }
    }
    return false;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,c,ans=0;
        cin>>n>>c;
        int a[n];
        fo(i,0,n){cin>>a[i];}
        sort(a,a+n);
        int s = 0;
        int e = a[n-1] - a[0];
        while(s<=e){
            int mid = (s+e)/2;
            bool che = check(a,mid,n,c);
            if(che){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}