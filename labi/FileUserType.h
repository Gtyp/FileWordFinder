#pragma once
#include "task.h"

class FileUserType : public FileAbstract {
	string _word, _fileType = "";
public:
	// ������� override
	void displayFiles() override;
	void displayNotAllFiles() override;

	// ������� �� override
	void setFileType(string& fileType);
	string getFileType();

	void findWord();
	void findWordNotAll();
};