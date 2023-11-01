#include "RunningGame.h"

USING_NS_CC;

Scene *RunningGame::createScene()
{
  return RunningGame::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool RunningGame::init()
{
  if (!Scene::initWithPhysics())
  {
    return false;
  }
  // code here

  this->getPhysicsWorld()->setGravity(Vec2(0, -0));
  this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  player = Player::create();
  this->addChild(player);
  player->run();

  return true;
}