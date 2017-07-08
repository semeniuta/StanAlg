#include "FileReader.h"

#include <string>
#include <iostream>

FileReader::FileReader() { }

FileReader::~FileReader() {
  iFileStream.close();
}

int FileReader::open(std::string fname) {

  const char* fname_cstr = fname.c_str();

  iFileStream.open(fname_cstr);

  if (this->fileExists()) {
    std::cout << "File " << fname << " opened." << std::endl;
  }

  return 0;
}

std::string FileReader::readLine() {

  if (!this->fileExists()) {
    return NULL;
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
