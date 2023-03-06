#include <iostream>
#include <cstdlib>
#include <ctime>

void show_arr(int arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

int search_index(int arr[], const int length, int value, int begin = 0) {
	for (int i = begin; i < length; i++)
		if (arr[i] == value)
			return i;
	return -1;
}

int search_last_index(int arr[], const int length, int value) {
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] == value)
			return i;
	return -1;
}

int search_last_index(int arr[], const int length, int value, int begin) {
	for (int i = begin; i >= 0; i--)
		if (arr[i] == value)
			return i;
	return -1;
}

int valid_pos(const int length) {
	int pos;
	do {
		std::cin >> pos;
		if (pos < 0 || pos >= length)
			std::cout << "Incorrect position! Please, repeat -> ";
		else
			return pos;
	} while (true);
}

int arr_max(int arr[], const int length) {
	int max = arr[0];
	for (int i = 1; i < length; i++)
		max = arr[i] > max ? arr[i] : max;
	return max;
}

int arr_min(int arr[], const int length) {
	int min = arr[0];
	for (int i = 1; i < length; i++)
		min = arr[i] < min ? arr[i] : min;
	return min;
}

double mean_value(int arr[], const int length) {
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	return (double)sum / (double)length;
}

void range(int arr[], const int length, int begin, int end) {
	for (int i = 0; i < length; i++)
		if (arr[i] >= begin && arr[i] <= end)
			std::cout << arr[i] << ", ";
	std::cout << "\b\b.\n";
}

int counter(int arr[], const int length, int value) {
	int counter = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == value)
			counter++;
	return counter;
}

int main() {
	int n, m, pos, index;
	char answer;

	const int size = 100;
	int arr[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (201) - 100;	// [-100..100]
	std::cout << "An array filled with random numbers [-100..100]: \n";
	show_arr(arr, size);
	
	// First element search
	std::cout << "\nEnter an element to search from the array beginning -> ";
	std::cin >> n;
	std::cout << "Search will start from position 0. Do you want to change start position (Y/N)? ";
	std::cin >> answer;
	if (tolower(answer) == 'y') {
		std::cout << "Enter a position for search start -> ";
		pos = valid_pos(size);
		index = search_index(arr, size, n, pos);
	}
	else 
		index = search_index(arr, size, n);
	if (index == -1)
		std::cout << "No match found!\n";
	else 
		std::cout << "Index of the first matching element: " << index << '\n';

	// Last element search
	std::cout << "\nEnter an element to search from the array end -> ";
	std::cin >> n;
	std::cout << "Search will start from position " << size - 1 << ". Do you want to change start position (Y/N)? ";
	std::cin >> answer;
	if (tolower(answer) == 'y') {
		std::cout << "Enter a position for search start -> ";
		pos = valid_pos(size);
		index = search_last_index(arr, size, n, pos);
	}
	else
		index = search_last_index(arr, size, n);
	if (index == -1)
		std::cout << "No match found!\n";
	else
		std::cout << "Index of the last matching element: " << index << '\n';

	// Max, min, ariphmetic mean
	std::cout << "\nMax array element: " << arr_max(arr, size) << '\n';
	std::cout << "Min array element: " << arr_min(arr, size) << '\n';
	std::cout << "Ariphmetic mean of all array elements: " << mean_value(arr, size) << '\n';

	// Elements from the range
	std::cout << "\nEnter lower range limit -> ";
	std::cin >> n;
	std::cout << "Enter upper range limit -> ";
	std::cin >> m;
	std::cout << "Array elements from the range [" << n << ".." << m << "]:\n";
	range(arr, size, n, m);

	// Number of occurrences
	std::cout << "\nEnter an element to search -> ";
	std::cin >> n;
	std::cout << "Number of occurrences: " << counter(arr, size, n) << '\n';
	
	return 0;
}