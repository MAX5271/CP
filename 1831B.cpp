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
        // Sort by first element in decreasing order
        if (a.first != b.first) {
            return a.first > b.first;
        }
        // If the first elements are equal, sort by the second element in increasing order
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

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> a, b;
    unordered_set<int> e;
    vector<int> a1(n), b1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
        e.insert(a1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b1[i];
        e.insert(b1[i]);
    }
    int f = a1[0], count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a1[i] == f)
            count++;
        else
        {
            if(a.find(f)==a.end()) a[f]=count;
            else a[f]=max(a[f],count);
            f=a1[i];
            count=1;
        }
    }
    if(count){
        if(a.find(f)==a.end()) a[f]=count;
        else a[f]=max(a[f],count);
    }
    f = b1[0], count = 0;
    for (int i = 0; i < n; i++)
    {
        if (b1[i] == f)
            count++;
        else
        {
            if(b.find(f)==b.end()) b[f]=count;
            else b[f]=max(b[f],count);
            f=b1[i];
            count=1;
        }
    }
    if(count){
        if(b.find(f)==b.end()) b[f]=count;
        else b[f]=max(b[f],count);
    }
    int m=0;
    for(auto it=e.begin();it!=e.end();it++){
        int sum=0;
        if(a.find(*it)!=a.end()) sum+=a[*it];
        if(b.find(*it)!=b.end()) sum+=b[*it];
        m=max(sum,m);
    }
    cout<<m<<endl;
    // for(auto it=a.begin();it!=a.end();it++) cout<<it->first<<" "<<it->second<<endl;
    // cout<<endl;
    // for(auto it=b.begin();it!=b.end();it++) cout<<it->first<<" "<<it->second<<endl;
    // cout<<endl;

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