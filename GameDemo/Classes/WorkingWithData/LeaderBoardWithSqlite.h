#ifndef __LeaderBoardWithSqlite_H__
#define __LeaderBoardWithSqlite_H__

#include "cocos2d.h"
#include "sqlite3/sqlite3.h"
#include "playerUser.h"
// struct user
// {
//   std::string userName;
//   int score;
// };

class LeaderBoardWithSqlite
{
private:
  sqlite3 *pdb;
  bool createDb(std::string &dbPath);

public:
  LeaderBoardWithSqlite(std::string &dbPath);
  bool insertLeaderBoard(std::string &name, int score);
  bool insertLeaderBoard(playerUser u);
  std::vector<playerUser> loadLeaderBoard(int no);
};

#endif // __LeaderBoardWithSqlite_H__