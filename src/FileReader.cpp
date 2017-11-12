#include "FileReader.h"

#include <string>
#include <iostream>

FileReader::~FileReader() {
    iFileStream.close();
}

void FileReader::open(std::string fname) {

    const char* fname_cstr = fname.c_str();

    iFileStream.open(fname_cstr);

    if (!this->fileExists()) {
        throw std::runtime_error("File does not exist");
    }

}

std::string FileReader::readLine() {

    if (!this->fileExists()) {
        return nullptr;
    }

    std::string line;
    std::getline(iFileStream, line, '\n');
    return line;

}

bool FileReader::fileExists() {
    return iFileStream.good();
}

bool FileReader::eof() {
    return iFileStream.eof();
}
