#include <crtdbg.h>
#include "user_interface.h"
#include "tests.h"

int main(int argc, char** argv) {
	Tests TM;
	TM.testAll();
	Pharmacy PY;
	UserInterface UI(PY);
	UI.begin();

	PY.~Pharmacy();
	UI.~UserInterface();
	_CrtDumpMemoryLeaks();
	return 0;
}
