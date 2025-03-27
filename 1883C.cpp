// template for cp

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
#define MOD 1e9 + 7
const int N = 1e5 + 10;
int arr[N];


#define all(a) a.begin(), a.end()

int npr(int n, int r)
{
    r = min(r, (n - r));
    int a = 1;
    for (int i = 0; i < r; i++) {
        a *= (n - i);
    }
    for (int i = 1; i < r; i++) {
        a /= (i + 1);
    }
    return a;
}

vector < int > seive;

bool prime[1000001];
vector < int > v1(1000001);
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                if (v1[i] == 0) v1[i] = p;
                prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            seive.push_back(p);
}

void print(vector < int > & a) {
    for (auto element: a) cout << element << " ";
    cout << endl;
}

bool is_Prime(int n)
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

void swap(int * a, int * b)
{
    int temp = * a;
    * a = * b;
    * b = temp;
}

int factorial(int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    map<int,int> c2,c3,c4,c5;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c2[a[i]%2]++;
        c3[a[i]%3]++;
        c4[a[i]%4]++;
        c5[a[i]%5]++;
    }
    int m=INT_MAX;
    switch(k){
        case 2:
            for(auto it=c2.begin();it!=c2.end();it++){
                if(it->first==0&&it->second!=0){
                    cout<<0<<endl;
                    return;
                }
                if(it->second!=0){
                    m=min(m,2-it->first);
                }
            }
            break;
            case 3:
            for(auto it=c3.begin();it!=c3.end();it++){
                if(it->first==0&&it->second!=0){
                    cout<<0<<endl;
                    return;
                }
                if(it->second!=0){
                    m=min(m,3-it->first);
                }
            }
            break;
            case 4:
            for(auto it=c4.begin();it!=c4.end();it++){
                // cout<<c2[0]<<endl;
                if(it->first==0&&it->second!=0){
                    cout<<0<<endl;
                    return;
                }else if(c2[0]>=2){
                    cout<<0<<endl;
                    return;
                }else if(c2[0]==1&&(c4[1]>=1||c4[3]>=1)){
                    cout<<1<<endl;
                    return;
                }else if(c4[3]>=1){
                    cout<<1<<endl;
                    return;
                }else if(c2[1]>=2){
                    cout<<2<<endl;
                    return;
                }
                if(it->second!=0){
                    m=min(m,4-it->first);
                }
            }
            break;
            case 5:
            for(auto it=c5.begin();it!=c5.end();it++){
                if(it->first==0&&it->second!=0){
                    cout<<0<<endl;
                    return;
                }
                if(it->second!=0){
                    m=min(m,5-it->first);
                }
            }
            break;
    }
    cout<<m<<endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

}