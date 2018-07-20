#include <iostream>
using namespace std;
#pragma warning (disable:4996)

/* 奇数放在前面，偶数放到后面，且相对顺序不变 */
void reOrderArray(int *array) {
	int i = 0;
	int j = 0;

	while (i < 10)
	{
		if (array[i] % 2 == 1)
		{
			if (i == j)
			{
				i++;
				j++;
			}
			else
			{
				int k = i;
				int s = array[i];
				while (k - 1 >= j)
				{
					array[k] = array[k - 1];
					k--;
				}
				array[j] = s;
				i++;
				j++;
			}
		}
		else i++;
	}
}



//int* printMatrix(int **matrix) {
//
//}

//int main()
//{
//	string str;
//	int a[10] = {1,5,8,4,2,3,6,7,9,0};  
//	reOrderArray(a);
//
//	for(int i=0; i<10;i++)
//		cout << a[i]; // 1 5 3 7 9 8 4 2 6  0
//	system("pause");
//	return 0;
//}