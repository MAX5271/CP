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

void solve()
{
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<pair<int,int>> ar;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        ar.push_back({x,y});
    }
    int ma=10000000000,mb=10000000000;
    for(int i=0;i<k;i++){
        int c1=ar[i].first-ar[a-1].first,c2=ar[i].second-ar[a-1].second,c3=ar[i].first-ar[b-1].first,c4=ar[i].second-ar[b-1].second;
        if(c1<0) c1=-c1;
        if(c2<0) c2=-c2;
        if(c3<0) c3=-c3;
        if(c4<0) c4=-c4;
        if(c1+c2<ma) ma=c1+c2;
        if(c3+c4<mb) mb=c3+c4;
    }
    int c1=ar[a-1].first-ar[b-1].first,c2=ar[a-1].second-ar[b-1].second;
    if(c1<0) c1=-c1;
    if(c2<0) c2=-c2;
    if(ma+mb<c1+c2) cout<<ma+mb<<endl;
    else cout<<c1+c2<<endl;
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