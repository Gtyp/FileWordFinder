#pragma once
#include <filesystem>
#include <chrono>
#include "FileAbstract.h"
#include "task.h"

class FileXml : public FileAbstract {
	string _word, _fileType = ".xml";
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
