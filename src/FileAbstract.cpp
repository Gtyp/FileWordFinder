#include "FileAbstract.hpp"
#include "getDirectoryFiles.hpp"
#include "getNotAllDirectoryFiles.hpp"

#include <iostream>
#include <memory>

std::string FileAbstract::getFileType() const{ 
	return _fileType; 
}

std::string FileAbstract::getFindWord() const { 
	return _word; 
}

void FileAbstract::setFindWord(const std::string& word) { 
	_word = word; 
}

void FileAbstract::setFindWord(std::string&& word){ 
	_word = std::move(word);
}

void FileAbstract::setFileType(std::string&& type) { 
	_fileType = std::move(type); 
}

void FileAbstract::setPath() {
	std::string dir;
	std::filesystem::path _dirPath = fs::current_path();

	std::cout << "\nCurrent path: " << _dirPath;
	std::cout << "\nEnter path to the dir\n(Attention! The path must be written without using Cyrillic characters)\n(If left as is - D): ";
	std::cin >> dir;

	if (dir != "D") { 
		std::filesystem::path _dirPath = fs::path(dir); 
	}
}