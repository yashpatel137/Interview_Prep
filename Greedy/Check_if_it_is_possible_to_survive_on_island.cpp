#include <bits/stdc++.h>
using namespace std;
void survival(int S, int N, int M)
{
	if (((N * 6) < (M * 7) && S > 6) || M > N)
    {
		cout << "No\n";
    }
	else 
    {
		int days = ceil(double(M * S) /(double)N);
		cout << "Yes " << days << endl;
	}
}
int main()
{
	int S = 10, N = 16, M = 2;
	survival(S, N, M);
	return 0;
}