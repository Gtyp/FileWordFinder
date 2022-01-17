#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef FILE_USER_TYPE_H 
#define FILE_USER_TYPE_H

#include "FileAbstract.h"

class FileUserType : public FileAbstract {
	std::string _word;
	std::string _fileType = "";
public:
	// ������� override
	void displayFiles() override;
	void displayNotAllFiles() override;

	// ������� �� override
	void setFileType(std::string&fileType);
	std::string getFileType();

	void findWord();
	void findWordNotAll();
};

#endif