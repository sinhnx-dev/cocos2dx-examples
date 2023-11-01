#include "ParallaxDemoScene.h"

USING_NS_CC;

Scene *ParallaxDemo::createScene()
{
  return ParallaxDemo::create();
}
// on "init" you need to initialize your instance
bool ParallaxDemo::init()
{
  if (!Scene::initWithPhysics())
  {
    return false;
  }

  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  _bg1 = Sprite::create("grass_hd-1024x124.png");
  _bg1->setAnchorPoint(Vec2::ZERO);
  _bg1->setPosition(Vec2::ZERO);
  this->addChild(_bg1);
  _bg2 = Sprite::create("grass_hd-1024x124.png");
  _bg2->setAnchorPoint(Vec2::ZERO);
  _bg2->setPosition(Vec2(_bg1->getContentSize().width, 0));
  this->addChild(_bg2);
  // this->schedule(
  //     [=](float delta)
  //     {
  //       _bg1->setPosition(_bg1->getPosition() + scrollSpeed);
  //       log("(x=%f, y=%f)", _bg1->getPosition().x, _bg1->getPosition().y);
  //       if (_bg1->getPosition().x < -(_bg1->getContentSize().width))
  //       {
  //         log("reset bg1");
  //         _bg1->setPosition(Vec2(_bg2->getPosition().x + _bg2->getContentSize().width + scrollSpeed.x, 0));
  //       }
  //       _bg2->setPosition(_bg2->getPosition() + scrollSpeed);
  //       if (_bg2->getPosition().x < -(_bg2->getContentSize().width))
  //       {
  //         log("reset bg2");
  //         _bg2->setPosition(Vec2(_bg1->getPosition().x + _bg1->getContentSize().width, 0));
  //       }
  //     },
  //     0.1f, "run-background");
  this->scheduleUpdate();

  return true;
}

void ParallaxDemo::update(float delta)
{
  auto scrollSpeed = Vec2(-5, 0);
  _bg1->setPosition(_bg1->getPosition() + scrollSpeed);
  // log("(x=%f, y=%f)", _bg1->getPosition().x, _bg1->getPosition().y);
  if (_bg1->getPosition().x < -(_bg1->getContentSize().width))
  {
    // log("reset bg1");
    _bg1->setPosition(Vec2(_bg2->getPosition().x + _bg2->getContentSize().width + scrollSpeed.x, 0));
  }
  _bg2->setPosition(_bg2->getPosition() + scrollSpeed);
  if (_bg2->getPosition().x < -(_bg2->getContentSize().width))
  {
    // log("reset bg2");
    _bg2->setPosition(Vec2(_bg1->getPosition().x + _bg1->getContentSize().width, 0));
  }
}
