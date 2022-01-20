

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif

#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef FILESYSTEM
#define FILESYSTEM
#include <filesystem>
namespace fs = std::filesystem;
#endif

#include "FileAll.h"
#include "getDirectoryFiles.h"
#include "getNotAllDirectoryFiles.h"

void FileAll::displayFiles() {
	system("cls");
	std::string catalog;
	auto path = fs::current_path(); //path = path / "TEST";

	std::cout << "\n��������� � ��������: " << path;
	printf("\n������� ���� � ��������\n(��������! ���� ������ ������� ��� ������������� �������� ���������)\n(���� �������� ��� ���� - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector) { std::cout << f << "\n"; }
		std::cout << "\n���-�� ������: " << aVector.size();
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getDirectoryFiles(path, {});
	print_files(files);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "\n�����: " << finalTime.count();
}
void FileAll::displayNotAllFiles() {
	system("cls");
	std::string catalog;
	auto path = fs::current_path(); //path = path / "TEST";

	std::cout << "\n��������� � ��������: " << path;
	printf("\n������� ���� � ��������\n(��������! ���� ������ ������� ��� ������������� �������� ���������)\n(���� �������� ��� ���� - D): "); std::cin >> catalog;
	if (catalog != "D") { path = fs::path(catalog); }

	auto print_files = [](const auto& aVector) {
		for (auto& f : aVector) { std::cout << f << "\n"; }
		std::cout << "\n���-�� ������: " << aVector.size();
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getNotAllDirectoryFiles(path, {});
	print_files(files);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "\n�����: " << finalTime.count();
}

void FileAll::findWordAll() {
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

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						std::cout << "\n������� �����: " << fWord;
						std::cout << "\n����: " << f;
						std::cout << "\n����� ������: " << counter;
						std::cout << "\n������: " << line;
						counterFile++;
						printf("\n\n");

						if (obj._fileName != "N") { obj.saveInfoTxt(fWord, f, counter, line, obj); }
					}
					counter++;
				}
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << "\n";
				file.close();
			}
			file.close();
		}
		printf("\n");
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getDirectoryFiles(path, {});
	print_result(files, _word, counterFile, obj);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "���-�� ������ �� ������ ����������� ������: " << counterFile;
	std::cout << "\n�����: " << finalTime.count();
}
void FileAll::findWordNotAll() {
	system("cls");
	FileAbstract::SaveFile obj;
	std::string catalog, saveFileName;
	int counterFile = 0;
	auto path = fs::current_path();

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

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						std::cout << "\n������� �����: " << fWord;
						std::cout << "\n����: " << f;
						std::cout << "\n����� ������: " << counter;
						std::cout << "\n������: " << line;
						counterFile++;
						printf("\n\n");

						if (obj._fileName != "N") { obj.saveInfoTxt(fWord, f, counter, line, obj); }
					}
					counter++;
				}
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << "\n";
				file.close();
			}
			file.close();
		}
		printf("\n");
	};

	auto start = std::chrono::steady_clock::now();

	auto files = getNotAllDirectoryFiles(path, {});
	print_result(files, _word, counterFile, obj);

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> finalTime = end - start;
	std::cout << "���-�� ������ �� ������ ����������� ������: " << counterFile;
	std::cout << "\n�����: " << finalTime.count();
}