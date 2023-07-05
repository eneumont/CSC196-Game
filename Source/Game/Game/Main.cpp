#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include <iostream>
#include <chrono>
using namespace std;

int main() {
	bunny::g_memoryTracker.DisplayInfo();
	int* p = new int;
	bunny::g_memoryTracker.DisplayInfo();
	delete p;
	bunny::g_memoryTracker.DisplayInfo();

	kiko::Time timer;
	for (int i = 0; i < 1000000; i++) {}
	cout << timer.GetElapsedSeconds() << endl;

	/*auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 10000000; i++) {}
	
	auto end = std::chrono::high_resolution_clock::now();

	cout << (end - start).count() << endl;*/

	/*cout << bunny::getFilePath() << endl;
	bunny::setFilePath("Assets");
	cout << bunny::getFilePath() << endl;
	size_t size;
	bunny::getFileSize("why.txt", size);
	cout << size << endl;

	string s;
	bunny::readFile("why.txt", s);
	cout << s << endl;

	bunny::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 10; i++) {
		cout << bunny::random(1, 9) << endl;
	}*/
}