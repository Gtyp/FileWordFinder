#include "task.h"

void FileTxt::setFindWord(string& word) { _word = word; }
string FileTxt::getFindWord() { return _word; }

void FileTxt::displayFiles() {
	system("cls");
	string catalog;
	auto path = fs::current_path(); //path = path / "TEST";

	cout << "\n��������� � ��������: " << path;
	printf("\n������� ���� � ��������\n(��������! ���� ������ ������� ��� ������������� �������� ���������)\n(���� �������� ��� ���� - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector)
			cout << f << "\n";
		cout << "\n���-�� ������: " << aVector.size();
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getDirectoryFiles(path, { _fileType });
	print_files(files);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	cout << "\n�����: " << finalTime.count();
}
void FileTxt::displayNotAllFiles() {
	system("cls");
	string catalog;
	auto path = fs::current_path(); //path = path / "TEST";

	cout << "\n��������� � ��������: " << path;
	printf("\n������� ���� � ��������\n(��������! ���� ������ ������� ��� ������������� �������� ���������)\n(���� �������� ��� ���� - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector)
			cout << f << "\n";
		cout << "\n���-�� ������: " << aVector.size();
	};

	auto files = getNotAllDirectoryFiles(path, { _fileType });
	print_files(files);
}

void FileTxt::findWordAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	string catalog, saveFileName;
	int counterFile = 0;
	auto path = fs::current_path(); //path = path / "TEST";

	cout << "\n��������� � ��������: " << path;
	
	printf("\n������� ���� � ��������\n(��������! ���� ������ ������� ��� ������������� �������� ���������)\n(���� �������� ��� ���� - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }
	cout << "\n������� ����� ��� ������: "; cin >> _word;
	cout << "\n������� ���� (������: C:\\somePath\\result.txt), ��� ����� �������� ���������\n(���� �� ����� ��������� - N): "; cin >> saveFileName; obj._fileName = saveFileName;
	
	auto print_result = [](const auto& aVector, const string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {

		for (auto& f : aVector) {
			ifstream file;
			string line;
			int counter = 1;
			try {
				file.open(f);
				while (getline(file, line)) {
					if (line.find(fWord) != string::npos) {

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						cout << "\n������� �����: " << fWord;
						cout << "\n����: " << f;
						cout << "\n����� ������: " << counter;
						cout << "\n������: " << line;
						counterFile++;
						printf("\n\n");
						
						if (obj._fileName != "N") { obj.saveInfo(fWord, f, counter, line, obj); }
					}
					counter++;
				}
			}
			catch (const std::exception& ex) {
				cout << ex.what() << "\n";
				file.close();
			}
			file.close();
		}
		printf("\n");
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getDirectoryFiles(path, { _fileType });
	print_result(files, _word, counterFile, obj);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	cout << "���-�� ������ �� ������ ����������� ������: " << counterFile;
	cout << "\n�����: " << finalTime.count();
}
void FileTxt::findWordNotAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	string catalog, saveFileName;
	int counterFile = 0;
	auto path = fs::current_path(); //path = path / "TEST";

	cout << "\n��������� � ��������: " << path;

	printf("\n������� ���� � ��������\n(��������! ���� ������ ������� ��� ������������� �������� ���������)\n(���� �������� ��� ���� - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }
	cout << "\n������� ����� ��� ������: "; cin >> _word;
	cout << "\n������� ���� (������: C:\\somePath\\result.txt), ��� ����� �������� ���������\n(���� �� ����� ��������� - N): "; cin >> saveFileName; obj._fileName = saveFileName;

	auto print_result = [](const auto& aVector, const string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {

		for (auto& f : aVector) {
			ifstream file;
			string line;
			int counter = 1;
			try {
				file.open(f);
				while (getline(file, line)) {
					if (line.find(fWord) != string::npos) {

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						cout << "\n������� �����: " << fWord;
						cout << "\n����: " << f;
						cout << "\n����� ������: " << counter;
						cout << "\n������: " << line;
						counterFile++;
						printf("\n\n");

						if (obj._fileName != "N") { obj.saveInfo(fWord, f, counter, line, obj); }
					}
					counter++;
				}
			}
			catch (const std::exception& ex) {
				cout << ex.what() << "\n";
				file.close();
			}
			file.close();
		}
		printf("\n");
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getNotAllDirectoryFiles(path, { _fileType });
	print_result(files, _word, counterFile, obj);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	cout << "���-�� ������ �� ������ ����������� ������: " << counterFile;
	cout << "\n�����: " << finalTime.count();
}

