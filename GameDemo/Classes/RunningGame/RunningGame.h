#ifndef __RUNNING_GAME_SCENE_H__
#define __RUNNING_GAME_SCENE_H__

#include "cocos2d.h"
#include "Player.h"

class RunningGame : public cocos2d::Scene
{
private:
  Player *player;

public:
  static cocos2d::Scene *createScene();

  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(RunningGame);
};

#endif // __ANIMATE_DEMO_SCENE_H__