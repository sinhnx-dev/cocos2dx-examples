#include "LeaderBoardWithSqlite.h"
USING_NS_CC;
using namespace std;

LeaderBoardWithSqlite::LeaderBoardWithSqlite(string &dbName)
{
  createDb(dbName);
}

bool LeaderBoardWithSqlite::createDb(string &dbName)
{
  sqlite3 *pdb;
  pdb = NULL;
  std::string dbPath = cocos2d::FileUtils::getInstance()->getWritablePath() + dbName;
  // std::string dbPath = cocos2d::FileUtils::getInstance()->fullPathForFilename(dbName);
  log("%s\n", dbPath.c_str());
  int result = sqlite3_open(dbPath.c_str(), &pdb);

  if (result == SQLITE_OK)
  {
    log("open database successful!");
    // create table
    int result = 0;
    std::string sql;
    sql = "create table if not exists " +
          std::string("LeadersBoard") +
          std::string(" (user_name TEXT PRIMARY KEY, scores INT);");

    result = sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);

    if (result == SQLITE_OK)
    {
      // table created successfully
      log("table created successfully");
      return true;
    }
    else
    {
      // table was NOT created successfully
      log("table was NOT created successfully");
    }
  }
  else
    log("open database failed!");
  return false;
}

bool LeaderBoardWithSqlite::insertLeaderBoard(std::string &name, int score)
{
  int result = 0;
  std::string sql;
  sql = "insert into LeadersBoard(user_name, scores)" +
        std::string(" values('") + name + string("', ") +
        std::to_string(score) + std::string(");");
  result = sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);
  if (result == SQLITE_OK)
  {
    log("inserted to leader board.");
    return true;
  }
  sql = "update LeadersBoard set" +
        std::string(" scores = ") + std::to_string(score) +
        std::string(" where user_name='") + name + std::string("';");
  result = sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);
  if (result == SQLITE_OK)
  {
    log("update to leader board.");
    return true;
  }
  return false;
}

bool LeaderBoardWithSqlite::insertLeaderBoard(playerUser u)
{
  return insertLeaderBoard(u.userName, u.score);
}
std::vector<playerUser> LeaderBoardWithSqlite::loadLeaderBoard(int no)
{
  vector<playerUser> users = vector<playerUser>();

  std::string sql = "SELECT user_name, scores " +
                    std::string(" FROM LeadersBoard") +
                    std::string(" ORDER BY scores DESC") +
                    std::string(" LIMIT ") + std::to_string(no) + std::string(";");
  sqlite3_stmt *statement;
  if (sqlite3_prepare_v2(pdb, sql.c_str(), -1, &statement, 0) == SQLITE_OK)
  {
    int result = 0;
    while (true)
    {
      result = sqlite3_step(statement);
      if (result == SQLITE_ROW)
      {
        // do something with the row.
        playerUser u;
        u.userName = std::string(
            reinterpret_cast<const char *>(
                sqlite3_column_text(statement, 0)));
        u.score = sqlite3_column_int(statement, 1);
        users.push_back(u);
      }
      else
      {
        break;
      }
    }
  }
  return users;
}