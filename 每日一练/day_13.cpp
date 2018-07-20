#include <iostream>
using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length == 0)
			return false;
		char* count = new char[length];
		for (int i = 0; i < length; i++)
			count[i] = 0;

		for (int i = 0; i < length; i++)
		{
			if (count[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			else
				count[numbers[i]] = true;
		}
		return false;
	}
};