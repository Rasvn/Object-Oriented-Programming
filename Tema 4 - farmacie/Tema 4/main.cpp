#include <crtdbg.h>

#include "UserInterface.h"
#include "MedicineListRepository.h"
#include "Tests.h"

using namespace std;

void run() {
	Tests TM;
	TM.runAllTests();
	MedicineListRepository medicineListRepository;
	UserInterface UI(medicineListRepository);
	UI.begin();
}

int main() {
	run();
	_CrtDumpMemoryLeaks();
	return 0;
}
