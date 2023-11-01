#include "AnimateDemoScene.h"

USING_NS_CC;

Scene *AnimateDemo::createScene()
{
  return AnimateDemo::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool AnimateDemo::init()
{
  if (!Scene::init())
  {
    return false;
  }

  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  // auto mySprite = Sprite::create("anim/run_01.png");
  // mySprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
  // this->addChild(mySprite);
  // // now lets animate the sprite we moved
  // Vector<SpriteFrame *> animFrames;
  // animFrames.reserve(8);
  // animFrames.pushBack(SpriteFrame::create("anim/run_01.png", Rect(0, 0, 600, 600)));
  // animFrames.pushBack(SpriteFrame::create("anim/run_02.png", Rect(0, 0, 600, 600)));
  // animFrames.pushBack(SpriteFrame::create("anim/run_03.png", Rect(0, 0, 600, 600)));
  // animFrames.pushBack(SpriteFrame::create("anim/run_04.png", Rect(0, 0, 600, 600)));
  // animFrames.pushBack(SpriteFrame::create("anim/run_05.png", Rect(0, 0, 600, 600)));
  // animFrames.pushBack(SpriteFrame::create("anim/run_06.png", Rect(0, 0, 600, 600)));
  // animFrames.pushBack(SpriteFrame::create("anim/run_07.png", Rect(0, 0, 600, 600)));
  // animFrames.pushBack(SpriteFrame::create("anim/run_08.png", Rect(0, 0, 600, 600)));
  // // create the animation out of the frames
  // Animation *animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
  // Animate *animate = Animate::create(animation);
  // // run it and repeat it forever
  // mySprite->runAction(RepeatForever::create(animate));

  // SpriteFrameCache::getInstance()->addSpriteFramesWithFile("anim/running.plist");
  auto spriteFrameCache = SpriteFrameCache::getInstance();
  spriteFrameCache->addSpriteFramesWithFile("anim/running.plist", "anim/running.png");
  auto sprite = Sprite::createWithSpriteFrameName("run_01.png");
  sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
  this->addChild(sprite, 1);

  auto animCache = AnimationCache::getInstance();
  animCache->addAnimationsWithFile("anim/run_animation.plist");
  auto anim = Animate::create(animCache->getAnimation("run"));
  sprite->runAction(RepeatForever::create(anim));

  return true;
}