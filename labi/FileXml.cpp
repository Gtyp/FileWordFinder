#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif

#ifndef FILESYSTEM
#define FILESYSTEM
#include <filesystem>
namespace fs = std::filesystem;
#endif

#include "FileXml.h"
#include "getDirectoryFiles.h"
#include "getNotAllDirectoryFiles.h"

void FileXml::setFindWord(std::string& word) { _word = word; }
std::string FileXml::getFindWord() { return _word; }
const std::string& FileXml::getFileType() const { return _fileType; }

void FileXml::displayFiles() {
	system("cls");
	std::string catalog;
	auto path = fs::current_path();

	std::cout << "\n��������� � ��������: " << path;
	printf("\n������� ���� � ��������\n(��������! ���� ������ ������� ��� ������������� �������� ���������)\n(���� �������� ��� ���� - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector)
			std::cout << f << "\n";
		std::cout << "\n���-�� ������: " << aVector.size();
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getDirectoryFiles(path, { getFileType() });
	print_files(files);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "\n�����: " << finalTime.count();
}
void FileXml::displayNotAllFiles() {
	system("cls");
	std::string catalog;
	auto path = fs::current_path();

	std::cout << "\n��������� � ��������: " << path;
	printf("\n������� ���� � ��������\n(��������! ���� ������ ������� ��� ������������� �������� ���������)\n(���� �������� ��� ���� - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector)
			std::cout << f << "\n";
		std::cout << "\n���-�� ������: " << aVector.size();
	};

	auto files = getNotAllDirectoryFiles(path, { _fileType });
	print_files(files);
}

void FileXml::findWordAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	std::string catalog, saveFileName;
	int counterFile = 0;
	auto path = fs::current_path(); //path = path / "TEST";

	std::cout << "\n��������� � ��������: " << path;

	printf("\n������� ���� � ��������\n(��������! ���� ������ ������� ��� ������������� �������� ���������)\n(���� �������� ��� ���� - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }
	std::cout << "\n������� ����� ��� ������: "; std::cin >> _word;
	std::cout << "\n������� ���� (������: C:\\somePath\\result.txt), ��� ����� �������� ���������\n(���� �� ����� ��������� - N): "; std::cin >> saveFileName; obj._fileName = saveFileName;

	auto print_result = [](const auto& aVector, const std::string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {
		for (auto& f : aVector) {
			std::ifstream file;
			std::string line;
			int counter = 1;

			try {
				file.open(f);
				while (getline(file, line)) {
					if (line.find(fWord) != std::string::npos) {
						std::string tag;

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

						std::string tagTemp = tag;
						std::cout << "\n������� ������: " << tag;
						for (size_t i = 0; i < tag.size(); i++) {
							if (tag[i] == '<') { tag.insert(i + 1, std::string("/")); break; }
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
	std::cout << "���-�� ������ �� ������ ����������� ������: " << counterFile;
	std::cout << "\n�����: " << finalTime.count();
}
void FileXml::findWordNotAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	std::string catalog, saveFileName;
	int counterFile = 0;
	auto path = fs::current_path(); //path = path / "TEST";

	std::cout << "\n��������� � ��������: " << path;

	printf("\n������� ���� � ��������\n(��������! ���� ������ ������� ��� ������������� �������� ���������)\n(���� �������� ��� ���� - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }
	std::cout << "\n������� ����� ��� ������: "; std::cin >> _word;
	std::cout << "\n������� ���� (������: C:\\somePath\\result.txt), ��� ����� �������� ���������\n(���� �� ����� ��������� - N): "; std::cin >> saveFileName; obj._fileName = saveFileName;

	auto print_result = [](const auto& aVector, const std::string& fWord, int& counterFile, const FileAbstract::SaveFile& obj) {
		for (auto& f : aVector) {
			std::ifstream file;
			std::string line;
			int counter = 1;

			try {
				file.open(f);
				while (getline(file, line)) {
					if (line.find(fWord) != std::string::npos) {
						std::string tag;

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
						std::string tagTemp = tag;
						std::cout << "\n������� ������: " << tag;
						for (int i = 0; i < tag.size(); i++) {
							if (tag[i] == '<') { tag.insert(i + 1, std::string("/")); break; }
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
	std::cout << "���-�� ������ �� ������ ����������� ������: " << counterFile;
	std::cout << "\n�����: " << finalTime.count();
}

