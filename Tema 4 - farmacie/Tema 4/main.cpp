#include <iostream>
#include <vector>
#include "user_interface.h"
#include "repository.h"
#include "tests.h"
using namespace std;

void run() {
	Tests TM;
	TM.runAllTests();
	Repository repo;
	UserInterface UI(repo);
	UI.begin();
}

int main() {
	run();
	return 0;
}
