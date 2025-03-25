// template for cp

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
#define MOD 1e9 + 7
const int N=1e5+10;
long long int arr[N];


#define all(a) a.begin(),a.end() 

ll int npr(ll int n,ll int r)
{
    r=min(r,(n-r));
    ll int a=1;
    for(ll int i=0;i<r;i++){
        a*=(n-i);
    }
    for(ll int i=1;i<r;i++){
        a/=(i+1);
    }
    return a;
}

vector <ll int> seive;

bool prime[1000001];
vector <ll> v1(1000001);
void SieveOfEratosthenes(int n)
{
	memset(prime, true, sizeof(prime));
 
	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p){
				if(v1[i]==0)   v1[i]=p;
				prime[i] = false;
			}
		}
	}
	for (int p = 2; p <= n; p++)
		if (prime[p])
			seive.push_back(p);
}

void print(vector<ll int>& a){
    for(auto element: a) cout<<element<<" ";
    cout<<endl;
}

bool is_Prime(ll int n)
{
    if (n <= 1)
        return false;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;

    return true;
}

void swap(ll int *a,ll int *b)
{
    ll int temp = *a;
    *a = *b;
    *b = temp;
}

ll int factorial(ll int n)
{
    ll int p = 1;
    for(int i=1;i<=n;i++)
        p *= i;

    return p;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve()
{
   ll int n,n1;
   cin>>n;
   n1=n;
   if(n%25==0){
    cout<<0<<endl;
    return;
   }
   vector<ll int> a,c00(2,-1),c25(2,-1),c50(2,-1),c75(2,-1);
   while(n){
    a.push_back(n%10);
    n/=10;
   }
   n=a.size();
   reverse(all(a));
   
   for(int i=a.size()-1;i>-1;i--){
    if(a[i]==0){
        if(c00[1]==-1){
            c00[1]=i;
        }else if(c00[0]==-1){
            c00[0]=i;
        }
        if(c50[0]==-1&&c50[1]==-1){
            c50[1]=i;
        }
    }
    if(a[i]==5){
        if(c25[0]==-1&&c25[1]==-1){
            c25[1]=i;
        }
        if(c50[0]==-1&&c50[1]!=-1){
            c50[0]=i;
        }
        if(c75[0]==-1&&c75[1]==-1){
            c75[1]=i;
        }
    }
    if(a[i]==2&&c25[0]==-1&&c25[1]!=-1){
        c25[0]=i;
    }
    if(a[i]==7&&c75[0]==-1&&c75[1]!=-1){
        c75[0]=i;
    }
   }
//    cout<<"a"<<endl;
   int a00=INT_MAX,a25=INT_MAX,a50=INT_MAX,a75=INT_MAX;
   if(c00[0]!=-1&&c00[1]!=-1){
    a00=n-2-c00[0];
   }
   if(c25[0]!=-1&&c25[1]!=-1){
    a25=n-2-c25[0];
   }
   if(c50[0]!=-1&&c50[1]!=-1){
    a50=n-2-c50[0];
   }
   if(c75[0]!=-1&&c75[1]!=-1){
    a75=n-2-c75[0];
   }
   int ans=min(a00,min(a25,min(a50,a75))),a1=a.size();
   if(c00[1]!=-1) a1--;
   cout<<min(ans,a1)<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
}