// activity selection
// assignment week 6
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long counts[100001] = {0UL};

class job_t
{
public:
	job_t(void)
	:start(0UL), finish(0UL)
	{
	}
	
	job_t(unsigned long startin, unsigned long duration)
	:start(startin), finish(startin+duration)
	{
	}
	
	unsigned long start, finish;
	bool operator < (const job_t &r) const
	{
		return (*this).finish < r.finish;
	}
} jobs[100001];

int main(void)
{
	long N;
	cin >> N;
	
	for (long n = 0; n < N; n++)
	{
		unsigned long duration;
		cin >> jobs[n].start >> duration;
		jobs[n].finish = jobs[n].start + duration;
	}
	
	sort(jobs, jobs + N);
	
	counts[0] = 1UL; // base case
	
	for (long n = 1; n < N; n++)
	{
		bool found = false;
		unsigned long curcount = 1, prev;
		for (long j = n - 1; j >= 0; j--)
		{
			if (jobs[j].finish <= jobs[n].start)
			{
				prev = j;
				found = true;
				break;
			}
		}
		if (found)
			curcount += counts[prev];
		
		counts[n] = max(curcount, counts[n - 1]);
	}
	
	cout << counts[N - 1] << endl;
	
	return 0;
}
