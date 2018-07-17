// moving intervals
// assignment week 2
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct like
{
	long start;
	long finish;

	like(long n1 = 0L, long n2 = 0L) : start(n1), finish(n2) {}

};

static bool operator < (const struct like &left, const struct like &right)
{
	if (left.start < right.start)
		return true;
	else if (left.start > right.start)
		return false;
	else if (left.finish < right.finish)
		return true;
	else
		return false;
}

int main(void)
{
	long C, N;
	short K;
	vector<like> list;
	cin >> C >> N >> K;
	//list.reserve(N);

	for (long n = 1; n <= N; n++)
	{
		long n1, n2;
		cin >> n1 >> n2;
		like r(n1, n2);
		list.push_back(r);
	}

	cout << "[";
	for(vector<like>::const_iterator ci = list.begin(); ci != list.end(); ci++)
		cout << "(" << (*ci).start << "," << (*ci).finish << ")";
	cout << "]" << endl;
	sort(list.begin(), list.end());
	for(vector<like>::const_iterator ci = list.begin(); ci != list.end(); ci++)
		cout << "(" << (*ci).start << "," << (*ci).finish << ")";
	cout << "]" << endl;

	return 0;
}


