#include "FileReader.h"

#include <string>
#include <iostream>

FileReader::FileReader(std::string fname) {

  const char* fname_cstr = fname.c_str();

  iFileStream.open(fname_cstr);

  std::cout << "FileReader created" << " " << this->fileExists() << std::endl;
}

FileReader::~FileReader() {
  iFileStream.close();
  std::cout << "FileReader destroyed\n";
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
