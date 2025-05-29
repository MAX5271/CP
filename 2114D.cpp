// template for cp

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int arr[N];

#define all(a) a.begin(), a.end()

int npr(int n, int r)
{
    r = min(r, (n - r));
    int a = 1;
    for (int i = 0; i < r; i++)
    {
        a *= (n - i);
    }
    for (int i = 1; i < r; i++)
    {
        a /= (i + 1);
    }
    return a;
}

vector<int> seive;

bool prime[1000001];
vector<int> v1(1000001);
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
            {
                if (v1[i] == 0)
                    v1[i] = p;
                prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            seive.push_back(p);
}

void print(vector<int> &a)
{
    for (auto element : a)
        cout << element << " ";
    cout << endl;
}

void sortfdsi(vector<pair<int, int>> &vec)
{
    sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        //sort by first element in decreasing order
        if (a.first != b.first) {
            return a.first > b.first;
        }
        //if the first elements are equal, sort by the second element in increasing order
        return a.second < b.second; });
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int factorial(int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
        p *= i;

    return p;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void input(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
}

vector<int> p2(32);
void calp2()
{
    for (int i = 0, p = 1; i < 32; i++, p *= 2)
    {
        p2[i] = p;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p1(n), p2(n);
    for (int i = 0; i < n; i++)
        cin >> p1[i].first >> p1[i].second;
    if(n==1) {
        cout<<1<<endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        p2[i].first = p1[i].second;
        p2[i].second = p1[i].first;
    }
    sort(all(p1));
    sort(all(p2));
    int ans=LLONG_MAX;
    int x1=INT_MAX,y1=INT_MAX,x2=0,y2=0;
    for(int i=1;i<n;i++){
        x1=min(p1[i].first,x1);
        y1=min(p1[i].second,y1);
        x2=max(p1[i].first,x2);
        y2=max(p1[i].second,y2);
    }
    // cout<<x1<<","<<y1<<"  "<<x2<<","<<y2<<endl;
    if((x2-x1+1)*(y2-y1+1)==n-1){
        ans=min(ans,(x2-x1+2)*(y2-y1+1));
        ans=min(ans,(x2-x1+1)*(y2-y1+2));
    }else ans = min(ans,(x2-x1+1)*(y2-y1+1));
    x1=INT_MAX,y1=INT_MAX,x2=0,y2=0;
    for(int i=0;i<n-1;i++){
        x1=min(p1[i].first,x1);
        y1=min(p1[i].second,y1);
        x2=max(p1[i].first,x2);
        y2=max(p1[i].second,y2);
    }
    // cout<<x1<<","<<y1<<"  "<<x2<<","<<y2<<endl;
    if((x2-x1+1)*(y2-y1+1)==n-1){
        ans=min(ans,(x2-x1+2)*(y2-y1+1));
        ans=min(ans,(x2-x1+1)*(y2-y1+2));
    }else ans = min(ans,(x2-x1+1)*(y2-y1+1));
    x1=INT_MAX,y1=INT_MAX,x2=0,y2=0;
    for(int i=1;i<n;i++){
        y1=min(p2[i].first,y1);
        x1=min(p2[i].second,x1);
        y2=max(p2[i].first,y2);
        x2=max(p2[i].second,x2);
    }
    // cout<<x1<<","<<y1<<"  "<<x2<<","<<y2<<endl;
    if((x2-x1+1)*(y2-y1+1)==n-1){
        ans=min(ans,(x2-x1+2)*(y2-y1+1));
        ans=min(ans,(x2-x1+1)*(y2-y1+2));
    }else ans = min(ans,(x2-x1+1)*(y2-y1+1));
    x1=INT_MAX,y1=INT_MAX,x2=0,y2=0;
    for(int i=0;i<n-1;i++){
        y1=min(p2[i].first,y1);
        x1=min(p2[i].second,x1);
        y2=max(p2[i].first,y2);
        x2=max(p2[i].second,x2);
    }
    // cout<<x1<<","<<y1<<"  "<<x2<<","<<y2<<endl;
    if((x2-x1+1)*(y2-y1+1)==n-1){
        ans=min(ans,(x2-x1+2)*(y2-y1+1));
        ans=min(ans,(x2-x1+1)*(y2-y1+2));
    }else ans = min(ans,(x2-x1+1)*(y2-y1+1));
    cout<<ans<<endl;
}

int32_t main()
{
    // calp2();
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