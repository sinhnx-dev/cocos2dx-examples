#include "Player.h"

Player *Player::create()
{
  auto p = new Player;
  if (p && p->init())
    return p;
  return nullptr;
}
bool Player::init()
{
  auto visibleSize = Director::getInstance()->getVisibleSize();
  auto spriteFrameCache = SpriteFrameCache::getInstance();
  spriteFrameCache->addSpriteFramesWithFile("anim/running.plist", "anim/running.png");
  this->initWithSpriteFrameName("run_01.png");
  this->setPosition(visibleSize.width / 2, visibleSize.height / 2);
  this->setScale(0.5f);
  auto physicsBody = PhysicsBody::createBox(this->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
  physicsBody->setDynamic(false);
  this->addComponent(physicsBody);

  auto animCache = AnimationCache::getInstance();
  animCache->addAnimationsWithFile("anim/run_animation.plist");
  auto anim = Animate::create(animCache->getAnimation("run"));
  this->_runAction = RepeatForever::create(anim);

  //  Create a "one by one" touch event listener (processes one touch at a time)
  auto listener1 = EventListenerTouchOneByOne::create();
  // trigger when you push down
  listener1->onTouchBegan = [](Touch *touch, Event *event)
  {
    log("onTouchBegan event");
    return true; // if you are consuming it
  };
  // trigger when moving touch
  listener1->onTouchMoved = [](Touch *touch, Event *event)
  {
    log("onTouchMoved event");
    // your code
  };
  // trigger when you let up
  listener1->onTouchEnded = [=](Touch *touch, Event *event)
  {
    // your code
    log("onTouchEnded event");
  };
  // Add listener
  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);

  return true;
}
void Player::run()
{
  this->runAction(_runAction);
}