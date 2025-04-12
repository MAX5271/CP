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

void sortfdsi(vector<pair<int, int>>& vec){
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        // Sort by first element in decreasing order
        if (a.first != b.first) {
            return a.first > b.first;
        }
        // If the first elements are equal, sort by the second element in increasing order
        return a.second < b.second;
    });

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

void input(vector<int>&a){
    for(int i=0;i<a.size();i++) cin>>a[i];
}

void solve()
{
    int n;
    cin>>n;
    map<int,int> a;
    vector<int> b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    int ans=0;
    int m=0,start=0;
    for(auto it=a.begin();it!=a.end();it++){
        if(it!=a.begin()){
            auto it1=it;
            --it1;
            if(it->first-it1->first!=1){
                b.push_back(0);
            }
        }
        b.push_back(it->second);
    }
    m=b[0];
    for(int i=1;i<b.size();){
        if(b[i]==0){
            ans+=(m-start);
            m=0;
            start=0;
            i++;
        }
        while(i<b.size()&&b[i]>=b[i-1]){
            m=b[i];
            i++;
        }
        while(i+1<b.size()&&b[i+1]<b[i]&&b[i]!=0){
            i++;
        }
        if(i<b.size()&&b[i-1]>b[i]&&b[i]!=0){
            ans+=(m-start);
            start=b[i];
            m=b[i];
            i++;
        }
        
    }
    ans+=(m-start);
    cout<<ans<<endl;
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