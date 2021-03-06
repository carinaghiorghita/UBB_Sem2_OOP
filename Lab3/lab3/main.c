#include "test.h"
#include "ui.h"
#include <crtdbg.h>

int main()
{
	testFile();
	testDynamicArray();
	testOperations();
	testRepository();
	
	Repository* repository = createRepository();
	OperationStack* undoStack = createStack();
	OperationStack* redoStack = createStack();
	Service* service = createService(repository,undoStack,redoStack);
	UI* ui = createUI(service);

	startUI(ui);
	destroyUI(ui);

	_CrtDumpMemoryLeaks();
}