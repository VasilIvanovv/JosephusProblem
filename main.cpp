#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"


int main()
{
	std::cout << "Enter N: " << std::endl;
	int N;
	std::cin >> N;
	std::cout << "Enter k: " << std::endl;
	int k;
	std::cin >> k;
	LinkedList<int> list;
	for (int i = 0; i < N; i++)
	{
		int number;
		std::cin >> number;
		list.Insert(number);
	}
	list.PrintSequence(k);
	return 0;
}

