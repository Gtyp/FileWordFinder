#pragma once
#include <filesystem>
#include <chrono>
#include "FileAbstract.h"
#include "task.h"

namespace fs = std::filesystem;

class FileTxt : public FileAbstract {
	string _word;
	const string _fileType = ".txt";
public:
	// ������� override
	void displayFiles() override;
	void displayNotAllFiles() override;

	// ������� �� override
	void findWordAll();
	void findWordNotAll();

	void setFindWord(string& word);
	string getFindWord();
};