#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rnd(time(0));
 
const int N = 1e4 + 7;
int MOD;
 
bool prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return (x != 1);
}
 
int main()
{
    MOD = 5e8 + rnd() % (int) 5e8;
    while (!prime(MOD)) MOD--;
    
}