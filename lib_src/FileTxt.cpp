#include "FileTxt.hpp"
#include "getDirectoryFiles.hpp"
#include "getNotAllDirectoryFiles.hpp"

#include <iostream>
#include <memory>
#include <fstream>

FileTxt::FileTxt(const std::string& findingWord, const std::filesystem::path& path){
	_fileType = ".txt"; 
	_word = findingWord;
	_dirPath = path;
}

FileTxt::FileTxt(std::string&& findingWord, std::filesystem::path&& path){
	_fileType = ".txt"; 
	_word = std::move(findingWord);
	_dirPath = std::move(path);
}

FileTxt::FileTxt(const std::filesystem::path& path, std::string&& findingWord /* = " "; */){
	_fileType = ".txt";
	_dirPath = path;
	_word = std::move(findingWord);
}

FileTxt::FileTxt(std::filesystem::path&& path, std::string&& findingWord /* = " "; */){
	_fileType = ".txt"; 
	_word = std::move(findingWord);
	_dirPath = std::move(path);
}

std::vector<OutResult> FileTxt::findWord(const std::function<std::vector<std::filesystem::path>(
														const std::filesystem::path& dir, 
														const std::vector<std::string>& ext)>& func){
	int counterFile = 0;
	std::vector<OutResult> results;

	auto doFinding = [&](const auto& files, const std::string& findWord) {
		for (const auto& currentFile : files) {
			std::ifstream file;
			std::string line;
			int lineCounter = 1;
			try {
				file.open(currentFile.string());
				while (getline(file, line)) {
					if (line.find(findWord) != std::string::npos) {

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);
						results.push_back(OutResult(findWord, currentFile, line, lineCounter));
						counterFile++;
					}
					lineCounter++;
				}
			}
			catch (const std::exception& ex) {
				std::cout << "[ERROR]: " << ex.what() << "\n";
				file.close();
			}
			file.close();
		}

		if (0 == counterFile) { 
			std::cout << "[INFO]: No files with this word"; 
		}
		
		std::cout << "\n";
	};
	
	const auto files = collectFiles(func);
	
	std::cout << "[INFO]: Finding word...\n";
	doFinding(files, _word);

	return results;
}



