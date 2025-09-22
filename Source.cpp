#include <iostream>

using namespace std;

int main()
{
	int Number[10] = {0,};
	int Count = 0;
	cin >> Count;
	
	for (int i = 0; i < Count; i++)
	{
		for (int k = 0; k < 0+i; k++)
		{
			cout << " ";
		}
		for (int j = 0; j < Count-i; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}