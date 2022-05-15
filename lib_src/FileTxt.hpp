#ifndef FILE_TXT_H
#define FILE_TXT_H

#include "FileAbstract.hpp"

#include <functional>

class FileTxt : public FileAbstract {
	
public:
	FileTxt();
	FileTxt(const std::string& findingWord);
	FileTxt(std::string&& findingWord);
	FileTxt(const std::filesystem::path& path);
	FileTxt(std::filesystem::path&& path);
	FileTxt(const std::string& findingWord, const std::filesystem::path& path);
	FileTxt(const std::string& findingWord, std::filesystem::path&& path);
	FileTxt(std::string&& findingWord, std::filesystem::path&& path);
	FileTxt(std::string&& findingWord, const std::filesystem::path& path);
	~FileTxt() = default;

	/* function takes a function that searches files in dir. Example of that func in getDirectoryFiles.cpp*/
	void findWord(const std::function<std::vector<std::string>(const fs::path& dir, 
															   const std::vector<std::string>& ext)>& func);
};

#endif