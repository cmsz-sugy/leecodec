#include<iostream>
using namespace std;
#define N 100
int a[N];

//�������C(m,k)����,k>=1
int  comb1(int m, int k,int &count)//(C(m,k))
{
	int i;
	for (i = m; i >= k; i--)
	{
		if (k > 1)
		{
			comb1(i - 1, k - 1,count);
		}
		else
		{
			count++;
			//cout<<m<<":"<<i<<",";
		}
	}
	return count;
}
//�������C(m,k)�������ֱ�Ӵ�С����
int  comb2(int m, int k,int &count)//(C(m,k))
{
	int i;
	cout << count << endl;
	for (i = m; i >= k; i--)
	{
		//a[k] = i;
		if (k > 1)
		{
			comb2(i - 1, k - 1,count);
		}
		else
		{
			count++;
		}
	}
	return count;
}
//int main()
//{
//	int m, k;
//	cin >> m >> k;
//	a[0] = k;
//	int count = 0;
//	int num = comb2(m, k,count);
//	cout << endl;
//	cout << num << endl;
//	system("pause");
//	return 0;
//}
