#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include <string>

class FileReader {

  std::ifstream iFileStream;

  public:
     FileReader(std::string fname);
     ~FileReader();
     std::string readLine();
     bool eof();
     bool fileExists();

};

#endif
