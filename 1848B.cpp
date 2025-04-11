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

void input(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
}

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n),b(c+1,INT_MAX);
    input(a);
    if(c==1){
        cout<<0<<endl;
        return;
    }
    map<int,vector<int>> pos;
    set<int> num;
    for(int i=0;i<n;i++){
        pos[a[i]].push_back(i);
        num.insert(a[i]);
    }
    for(auto it=pos.begin();it!=pos.end();it++){
        int ind=0,m=-1;
        it->second.push_back(n);
        // cout<<it->first<<endl;
        for(int i=0;i<it->second.size();i++){
            if(i==0) {
                m=it->second[i];
                ind=it->second[i];
            }else if(it->second[i]-it->second[i-1]-1>m){
                m=it->second[i]-it->second[i-1]-1;
                ind=it->second[i];
            }
            // cout<<ind<<" ";
        }
        // cout<<endl;
        m=-1;
        int count=1;
        // cout<<ind<<endl;
        for(int i=0;i<it->second.size();i++){
            // cout<<it->second[i]<<" ";
            if(ind==it->second[0]&&i==0){
                count--;
                m=(it->second[i])/2;
            }else if(i==0){
                m=it->second[0];
            }
            else if(it->second[i]==ind&&count){
                count--;
                m=max(m,(it->second[i]-it->second[i-1]-1)/2);
            }else m=max(m,it->second[i]-it->second[i-1]-1);
            // cout<<m<<" ";
        }
        // cout<<endl;
        b[it->first]=m;
    }
    // print(b);
    cout<<*min_element(all(b))<<endl;
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