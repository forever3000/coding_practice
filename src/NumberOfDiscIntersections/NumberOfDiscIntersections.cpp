// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#define distance(a,b) (a > b ? (a - b) : (b - a))

int solution(vector<int> &A)
{
	int result = 0;
	int i = 0;
	int j = 0;
	
	if (A.size() == 0)
	{
	    return 0;
	}

	for (i = 0; i < A.size() - 1; i++)
	{
		for (j = i + 1; j < A.size(); j++)
		{
			if (A.at(i) >= (distance(i,j) - A.at(j)))
				result ++;
		}
	}

	return result;
}

int solution(vector<int> &A)
{
	int result = 0;
	int dps[A.size()] = {0};
	int dpe[A.size()] = {0};
	int t = A.size() - 1;

	for (int i = 0; i < A.size(); i++)
	{
		int s = i > A.at(i) ? i - A.at(i) : 0;
		int e = t - i > A.at(i) ? i + A.at(i) : t;
		dps[s]++;
		dpe[e]++;
	}

	t = 0;

	for (int i = 0; i < A.size(); i++)
	{
		if (dps[i] > 0)
		{
			result += t * dps[i];
			result += dps[i] * (dps[i] - 1) / 2;
			if (10000000 < result) return -1;
			t += dps[i];
		}
		t -= dpe[i];
	}

	return result;
}