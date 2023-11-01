#include "ParseJsonDemo.h"

USING_NS_CC;
using namespace std;

ParseJsonDemo::ParseJsonDemo()
{
}
ParseJsonDemo::ParseJsonDemo(std::string filePath)
{
  path = cocos2d::FileUtils::getInstance()->getWritablePath() + filePath;
}

vector<playerUser> ParseJsonDemo::loadLeaderBoard(int no)
{
  vector<playerUser> users = vector<playerUser>();
  std::string content = FileUtils::getInstance()->getStringFromFile(path.c_str());
  // log("%s", content.c_str());
  jDoc.Parse(content.c_str());
  const rapidjson::Value &ranking = jDoc["ranking"];
  if (ranking.IsArray())
  {
    for (int i = 0; i < ranking.Size(); ++i)
    {
      if (ranking[i].HasMember("userName") && ranking[i].HasMember("scores"))
      {
        playerUser u;
        u.userName = string(ranking[i]["userName"].GetString());
        u.score = ranking[i]["scores"].GetInt();
        users.push_back(u);
      }
    }
    sort(users.begin(), users.end(),
         [=](playerUser u1, playerUser u2)
         { return u1.score > u2.score; });
  }
  else
  {
    log("not is array...");
  }
  return users;
}

bool ParseJsonDemo::insertLeaderBoard(playerUser u)
{
  std::vector<playerUser> users = loadLeaderBoard(10);
  users.push_back(u);
  return saveToFile(users);
  // content = FileUtils::getInstance()->getStringFromFile(path.c_str());
  // // log("%s", content.c_str());
  // jDoc.Parse(content.c_str());
  // const rapidjson::Value &ranking = jDoc["ranking"];
  // if (!ranking.IsNull() && ranking.IsArray())
  // {
  //   auto rk = ranking.GetArray();
  //   rapidjson::Value newUserScore(rapidjson::Type::kObjectType);
  //   newUserScore.SetObject();

  //   rapidjson::Value uName(rapidjson::Type::kStringType);
  //   uName.SetString(u.userName.c_str(), strlen(u.userName.c_str()), jDoc.GetAllocator());
  //   newUserScore.AddMember("userName", uName, jDoc.GetAllocator());

  //   rapidjson::Value uScore(rapidjson::Type::kNumberType);
  //   uScore.SetInt(u.score);
  //   newUserScore.AddMember("scores", uScore, jDoc.GetAllocator());

  //   // rk.PushBack(newUserScore, jDoc.GetAllocator());
  //   // ranking.PushBack(newUserScore, jDoc.GetAllocator());
  // }

  // rapidjson::StringBuffer sb;
  // rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
  // jDoc.Accept(writer);
  // log("%s", string(sb.GetString()).c_str());
}
bool ParseJsonDemo::saveToFile(std::vector<playerUser> users)
{
  rapidjson::Document doc;
  doc.SetObject();
  rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();

  rapidjson::Value aUsers(rapidjson::Type::kArrayType);
  for (const playerUser u : users)
  {
    rapidjson::Value o;
    o.SetObject();

    rapidjson::Value uName(rapidjson::Type::kStringType);
    uName.SetString(u.userName.c_str(), strlen(u.userName.c_str()), jDoc.GetAllocator());
    o.AddMember("userName", uName, allocator);

    rapidjson::Value uScore(rapidjson::Type::kNumberType);
    uScore.SetInt(u.score);
    o.AddMember("scores", u.score, allocator);

    aUsers.PushBack(o, allocator);
  }
  doc.AddMember("ranking", aUsers, allocator);
  rapidjson::StringBuffer strbuf;
  rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
  doc.Accept(writer);

  // log("%s", strbuf.GetString());
  if (FileUtils::getInstance()->writeStringToFile(strbuf.GetString(), path))
  {
    return true;
  }
  return false;
}