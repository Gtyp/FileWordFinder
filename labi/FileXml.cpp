#include "task.h"

void FileXml::setFindWord(string& word) { _word = word; }
string FileXml::getFindWord() { return _word; }

void FileXml::displayFiles() {
	system("cls");
	string fileType = ".xml", catalog;
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

	auto files = getDirectoryFiles(path, { fileType });
	print_files(files);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	cout << "\n�����: " << finalTime.count();
}
void FileXml::displayNotAllFiles() {
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

void FileXml::findWordAll() {
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
						string tag;

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						for (int i = 0; i < line.size(); i++) {
							if (line[i] == ' ') { continue; }
							else {
								if (line[i] == '>') {
									tag.push_back(line[i]);
									break;
								}
								tag.push_back(line[i]);
							}
						}

						string tagTemp = tag;
						std::cout << "\n������� ������: " << tag;
						for (size_t i = 0; i < tag.size(); i++) {
							if (tag[i] == '<') { tag.insert(i + 1, string("/")); break; }
						}
						std::cout << tag;
						std::cout << "\n����: " << f;
						std::cout << "\n����� ������: " << counter;
						std::cout << "\n������: " << line;
						counterFile++;
						printf("\n\n");

						if (obj._fileName != "N") { obj.saveInfo3(tagTemp, f, counter, line, obj); }
					}
					counter++;
				}
			}
			catch (const std::exception& ex) {
				printf("\nFile does not exist\n");
				std::cout << ex.what() << "\n";
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
void FileXml::findWordNotAll() {
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
						string tag;

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						for (int i = 0; i < line.size(); i++) {
							if (line[i] == ' ') { continue; }
							else {
								if (line[i] == '>') {
									tag.push_back(line[i]);
									break;
								}
								tag.push_back(line[i]);
							}
						}
						string tagTemp = tag;
						std::cout << "\n������� ������: " << tag;
						for (int i = 0; i < tag.size(); i++) {
							if (tag[i] == '<') { tag.insert(i + 1, string("/")); break; }
						}
						std::cout << tag;
						std::cout << "\n����: " << f;
						std::cout << "\n����� ������: " << counter;
						std::cout << "\n������: " << line;
						counterFile++;
						printf("\n\n");

						if (obj._fileName != "N") { obj.saveInfo3(tagTemp, f, counter, line, obj); }
					}
					counter++;
				}
			}
			catch (const std::exception& ex) {
				printf("\nFile does not exist\n");
				std::cout << ex.what() << "\n";
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

