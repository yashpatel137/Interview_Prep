//Method 1 formula based
unsigned long int catalan(unsigned int n)
{
    if (n <= 1)
        return 1;
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i)
            * catalan(n - i - 1);
 
    return res;
}

//Method 2 DP based TC=O(n^2)
unsigned long int catalanDP(unsigned int n)
{
    unsigned long int catalan[n + 1];
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i <= n; i++) 
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
    return catalan[n];
}

//Method 3 TC=O(n)
unsigned long int binomialCoeff(unsigned int n,unsigned int k)
{
    unsigned long int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
unsigned long int catalan(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2 * n, n);
    // return 2nCn/(n+1)
    return c / (n + 1);
}

//Method 4 TC=O(n)
/*
a) initially set cat_=1 and print it
b) run a for loop i=1 to i<=n
            cat_ *= (4*i-2)
            cat_ /= (i+1)
            print cat_
c) end loop and exit 
*/
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;
void catalan(int n)
{
	cpp_int cat_ = 1;
	cout << cat_ << " "; 
	for (cpp_int i = 1; i <=n; i++)
	{
		cat_ *= (4 * i - 2);
		cat_ /= (i + 1);
		cout << cat_ << " ";
	}
}
int main()
{
	int n = 5;
	catalan(n);
	return 0;
}
