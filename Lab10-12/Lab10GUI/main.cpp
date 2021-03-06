#include "Lab10GUI.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "MylistWidget.h"
#include <fstream>
#include <string>
#define filePathPosition 13
#define mylistFilePathPosition 15
using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	string repositoryFile, savedRepositoryFile;
	ifstream configuration("configurationFile.txt", std::ios::in);

	getline(configuration, repositoryFile);
	if (repositoryFile == "in memory")
	{

		memoryRepository repository{};
		memorySavedRepository savedRepository{};
		Service service{ repository,savedRepository };
		Lab10GUI gui{ service };
		gui.show();

		//MylistTableModel* model = new MylistTableModel(service);
		//MylistWidget widget{ model };
		//widget.show();
		return a.exec();
	}
	else
	{
		getline(configuration, savedRepositoryFile);
		if (savedRepositoryFile[savedRepositoryFile.size() - 1] == 'l')
		{
			fileRepository repository{ repositoryFile };
			HTMLRepository htmlRepository{ savedRepositoryFile };
			Service service{ repository,htmlRepository };
			Lab10GUI gui{ service };
			gui.show();

			//MylistTableModel* model = new MylistTableModel(service);
			//MylistWidget widget{ model };
			//widget.show();

			return a.exec();

		}
		else		
		{
			fileRepository repository{ repositoryFile };
			CSVRepository CSVRepository{ savedRepositoryFile };
			Service service{ repository,CSVRepository };
			Lab10GUI gui{ service };
			gui.show();

			//MylistTableModel* model = new MylistTableModel(service);
			//MylistWidget widget{ model };
			//widget.show();

			return a.exec();
		}

	}
	

}
