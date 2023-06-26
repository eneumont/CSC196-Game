#include <iostream>

int main() {
#ifdef _DEBUG
	std::cout << "debug";
#endif // _DEBUG
	std::cout << "hi";
}