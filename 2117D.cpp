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
        //sort by first element in decreasing order
        if (a.first != b.first) {
            return a.first > b.first;
        }
        //if the first elements are equal, sort by the second element in increasing order
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

vector<int> p2(32);
void calp2(){
    for(int i=0,p=1;i<32;i++,p*=2){
        p2[i]=p;
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    input(a);
    int d=a[1]-a[0];
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]!=d)
        {
            cn
            return;
        }
    }
    if((a[0]-d)<0||(a[0]-d)%(n+1)!=0)
    {
        cn
        return;
    }
    int x=(a[0]-d)/(n+1);
    int y=d+x;
    if(x>=0&&y>=0)
    cy
    else cn
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