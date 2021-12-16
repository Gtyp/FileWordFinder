#pragma once
#include <filesystem>
#include <chrono>
#include "task.h"

class FileHtml : public FileAbstract {
	string _word, _fileType = ".html";
public:
	// ������� override
	void displayFiles() override;
	void displayNotAllFiles() override;

	// ������� �� override
	void find3LefRightWords();
	void findNotAll3LefRightWords();

	void setFindWord(string& word);
	string getFindWord();
};
