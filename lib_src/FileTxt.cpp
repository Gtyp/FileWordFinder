#include "FileTxt.hpp"
#include "getDirectoryFiles.hpp"
#include "getNotAllDirectoryFiles.hpp"

#include <iostream>
#include <memory>
#include <fstream>

FileTxt::FileTxt() { 
	setFileType(".txt"); 
}

FileTxt::FileTxt(const std::string& findingWord){
	setFileType(".txt");
	setFindWord(findingWord);
}

FileTxt::FileTxt(std::string&& findingWord){
	setFileType(".txt");
	setFindWord(std::move(findingWord));
}

FileTxt::FileTxt(const std::filesystem::path& path){
	setFileType(".txt");
	setPath(path);
}

FileTxt::FileTxt(std::filesystem::path&& path){
	setFileType(".txt");
	setPath(std::move(path));
}

FileTxt::FileTxt(const std::string& findingWord, const std::filesystem::path& path){
	setFileType(".txt"); 
	setFindWord(findingWord);
	setPath(path);
}

FileTxt::FileTxt(const std::string& findingWord, std::filesystem::path&& path){
	setFileType(".txt"); 
	setFindWord(findingWord);
	setPath(std::move(path));
}

FileTxt::FileTxt(std::string&& findingWord, std::filesystem::path&& path){
	setFileType(".txt"); 
	setFindWord(std::move(findingWord));
	setPath(std::move(path));
}

FileTxt::FileTxt(std::string&& findingWord, const std::filesystem::path& path){
	setFileType(".txt");
	setFindWord(std::move(findingWord));
	setPath(path);
}

void FileTxt::findWord(const std::function<std::vector<std::string>(const fs::path& dir, 
																	const std::vector<std::string>& ext)>& func){
	int counterFile = 0;

	auto print_result = [&counterFile](const auto& files, const std::string& findWord) {
		for (const auto& currentFile : files) {
			std::ifstream file;
			std::string line;
			int lineCounter = 1;
			try {
				file.open(currentFile);
				while (getline(file, line)) {
					if (line.find(findWord) != std::string::npos) {

						int spaceBarCounter = 0, coun = 0;
						while (line[coun] == ' ') { spaceBarCounter++; coun++; }
						line.erase(0, spaceBarCounter);

						std::cout << "\nSearching word: " << findWord;
						std::cout << "\nPath to file: " << currentFile;
						std::cout << "\nLine number: " << lineCounter;
						std::cout << "\nLine: " << line;
						std::cout << "\n";
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
			std::cout << "[INFO]: Word cannot be founded"; 
		}
		
		std::cout << "\n";
	};
	
	std::cout << "[INFO]: Collecting files...\n";
	const auto files = func(getDirPath(), { getFileType() });
	std::cout << "[INFO]: Collecting has been completed. Number of files: " << files.size() << '\n';
	std::cout << "[INFO]: Finding word...\n";
	print_result(files, getFindWord());
}
