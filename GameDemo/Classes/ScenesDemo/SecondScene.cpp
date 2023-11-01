#include "SecondScene.h"

USING_NS_CC;

Scene *SecondScene::createScene()
{
  return SecondScene::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool SecondScene::init()
{
  if (!Scene::init())
  {
    return false;
  }

  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  auto label = Label::createWithTTF("Second Scene", "fonts/Marker Felt.ttf", 36);
  label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
  this->addChild(label);

  return true;
}