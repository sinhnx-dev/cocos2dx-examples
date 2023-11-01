#ifndef __ParseJsonDemo_H__
#define __ParseJsonDemo_H__

#include "cocos2d.h"
#include "external/json/document.h"
#include "external/json/writer.h"
#include "external/json/stringbuffer.h"
#include "playerUser.h"

class ParseJsonDemo
{
private:
  std::string path;
  rapidjson::Document jDoc;

public:
  ParseJsonDemo();
  ParseJsonDemo(std::string filePath);
  bool insertLeaderBoard(playerUser u);
  std::vector<playerUser> loadLeaderBoard(int no);
  bool saveToFile(std::vector<playerUser> users);
};

#endif // __ParseJsonDemo_H__