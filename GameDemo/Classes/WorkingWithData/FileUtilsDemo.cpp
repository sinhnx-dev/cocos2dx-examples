#include "FileUtilsDemo.h"

USING_NS_CC;
using namespace std;

void FileUtilsDemo::readFile(string &filePath)
{
  FileUtils::getInstance()->getStringFromFile(
      filePath,
      [=](string str)
      {
        log("%s", str.c_str());
      });
}