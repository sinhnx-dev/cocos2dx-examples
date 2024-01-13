#ifndef __ParseXmlDemo_H__
#define __ParseXmlDemo_H__

#include "cocos2d.h"
#include "external/tinyxml2/tinyxml2.h"
#include "playerUser.h"

class ParseXmlDemo
{
private:
  std::string path;
  tinyxml2::XMLDocument doc;

public:
  ParseXmlDemo();
  ParseXmlDemo(std::string filePath);
  bool insertLeaderBoard(playerUser u);
  std::vector<playerUser> loadLeaderBoard(int no);
  bool saveToFile(std::vector<playerUser> users);
};

#endif // __ParseXmlDemo_H__