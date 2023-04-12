#include "String.h"
#include "iostream"

using namespace std;

int main() {
	String s("this");

	cout << s.Value() << s.Length();

	return 0;
}