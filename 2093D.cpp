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
vector<int> p2(32);
void calp2()
{
    int p = 1;
    for (int i = 0; i < 32; i++, p *= 2)
    {
        p2[i] = p;
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<pair<string, vector<int>>> a;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        if (s == "->")
        {
            vector<int> b(2);
            cin >> b[0] >> b[1];
            a.push_back({s, b});
        }
        else
        {
            vector<int> b(1);
            cin >> b[0];
            a.push_back({s, b});
        }
    }
    for (int i = 0; i < q; i++)
    {

        if (a[i].first == "->")
        {
            int ans = 0;
            int x = a[i].second[0], y = a[i].second[1];
            while (x > 2 || y > 2)
            {
                int mx = -1, my = -1;
                for (int j = 0; j < 31; j++)
                {
                    if (p2[j] < x)
                        mx = p2[j];
                    else
                        break;
                }
                for (int j = 0; j < 31; j++)
                {
                    if (p2[j] < y)
                        my = p2[j];
                    else
                        break;
                }
                // cout<<mx<<" "<<my<<endl;
                if (my > mx)
                {
                    ans += 3 * p2[my];
                    y -= my;
                }
                else if (mx > my)
                {
                    ans += 2 * p2[mx];
                    x -= mx;
                }
                else
                {
                    ans += p2[mx];
                    y -= mx;
                    x -= mx;
                }
            }
            if (x == 1 && y == 1)
                ans += 1;
            else if (x == 1 && y == 2)
                ans += 4;
            else if (x == 2 && y == 1)
                ans += 3;
            else
                ans += 2;
            cout << ans << endl;
        }
        else
        {
            int p,x=0,y=0;
            int num = a[i].second[0];
            while (num > 4)
            {
                for (int j = 1; j < 32; j *= 2)
                {
                    if (p2[j*2] < num)
                    {
                        p = j;
                    }
                    else
                        break;
                }
                int rem=num-p2[2*p];
                if(rem<=p2[2*p]){
                    x+=p2[p];
                    y+=p2[p];
                }else if(rem<=2*p2[2*p]){
                    x+=p2[p];
                }else{
                    y+=p2[p];
                }
                // cout<<num<<" "<<rem<<endl;
                num=num%p2[2*p];
            }
            if(num==1){
                x++;
                y++;
            }else if(num==2){
                x+=2;
                y+=2;
            }else if(num==3){
                x+=2;
                y++;
            }else{
                y+=2;
                x++;
            }
            cout<<x<<" "<<y<<endl;
        }
    }
}

int32_t main()
{
    calp2();
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