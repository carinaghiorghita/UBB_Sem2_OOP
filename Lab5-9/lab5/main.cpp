#include "UI.h"
#include "Tests.h"
#include <crtdbg.h>
#include <stdlib.h>
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#define filePathPosition 13
#define mylistFilePathPosition 15
using namespace std;

int main()
{
	{
		//Test test{};
		//test.allTests();
		
		string filepath,filepathMylist;
		std::getline(std::cin, filepath);
		fileRepository repository{ filepath.substr(filePathPosition) };

		std::getline(std::cin, filepathMylist);
		if (filepathMylist[filepathMylist.size() - 1] == 'l')
		{
			HTMLRepository htmlRepository{ filepathMylist.substr(mylistFilePathPosition) };
			Service service{ repository,htmlRepository };
			UI ui{ service };
			ui.start();
		}
		else
		{
			CSVRepository CSVRepository{ filepathMylist.substr(mylistFilePathPosition) };
			Service service{ repository,CSVRepository };
			UI ui{ service };
			ui.start();
		}
		
	}
	_CrtDumpMemoryLeaks();

	return 0;
}