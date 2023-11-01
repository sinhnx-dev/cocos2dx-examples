#include "SpaceGameScene.h"

USING_NS_CC;

Scene *SpaceGameScene::createScene()
{
  return SpaceGameScene::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool SpaceGameScene::init()
{
  if (!Scene::init())
  {
    return false;
  }
  auto director = Director::getInstance();
  auto visibleSize = director->getVisibleSize();
  Vec2 origin = director->getVisibleOrigin();

  _batchNode = SpriteBatchNode::create("SpaceGame/Spritesheets/Sprites.pvr.ccz");
  this->addChild(_batchNode);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("SpaceGame/Spritesheets/Sprites.plist");

  _ship = Sprite::createWithSpriteFrameName("SpaceFlier_sm_1.png");
  _ship->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height * 0.5));
  _batchNode->addChild(_ship, 1);

  // 1) Create the ParallaxNode
  // _backgroundNode = ParallaxNode::create(); // 1
  _backgroundNode = InfiniteParallaxNode::create();
  _backgroundNode->setPosition(Vec2::ZERO);
  this->addChild(_backgroundNode, -1);

  // 2) Create the sprites will be added to the ParallaxNode
  _spacedust1 = Sprite::create("SpaceGame/Backgrounds/bg_front_spacedust.png");
  _spacedust2 = Sprite::create("SpaceGame/Backgrounds/bg_front_spacedust.png");
  _planetsunrise = Sprite::create("SpaceGame/Backgrounds/bg_planetsunrise.png");
  _galaxy = Sprite::create("SpaceGame/Backgrounds/bg_galaxy.png");
  _spacialanomaly = Sprite::create("SpaceGame/Backgrounds/bg_spacialanomaly.png");
  _spacialanomaly2 = Sprite::create("SpaceGame/Backgrounds/bg_spacialanomaly2.png");

  // 3) Determine relative movement speeds for space dust and background
  Point dustSpeed = Vec2(0.1, 0.1);
  Point bgSpeed = Vec2(0.05, 0.05);

  // 4) Add children to ParallaxNode
  _backgroundNode->addChild(_spacedust1, 0, dustSpeed, Vec2(0, visibleSize.height / 2)); // 2
  _backgroundNode->addChild(_spacedust2, 0, dustSpeed, Vec2(_spacedust1->getContentSize().width, visibleSize.height / 2));
  _backgroundNode->addChild(_galaxy, -1, bgSpeed, Vec2(0, visibleSize.height * 0.7));
  _backgroundNode->addChild(_planetsunrise, -2, bgSpeed, Vec2(600, visibleSize.height * 0));
  _backgroundNode->addChild(_spacialanomaly, -3, bgSpeed, Vec2(900, visibleSize.height * 0.3));
  _backgroundNode->addChild(_spacialanomaly2, -4, bgSpeed, Vec2(1500, visibleSize.height * 0.9));
  this->scheduleUpdate();

  // add star
  // this->addChild(ParticleSystemQuad::create("SpaceGame/Particles/Stars1.plist"));
  // this->addChild(ParticleSystemQuad::create("SpaceGame/Particles/Stars2.plist"));
  // this->addChild(ParticleSystemQuad::create("SpaceGame/Particles/Stars3.plist"));

  return true;
}

void SpaceGameScene::update(float dt)
{
  auto director = Director::getInstance();
  auto visibleSize = director->getVisibleSize();
  Point backgroundScrollVert = Vec2(-visibleSize.width, 0);
  _backgroundNode->setPosition(_backgroundNode->getPosition() + backgroundScrollVert * dt);
  _backgroundNode->updatePosition();

  // if (_backgroundNode->getPosition().x <= -(_spacedust1->getContentSize().width + _spacedust2->getContentSize().width))
  //   _backgroundNode->setPosition(Vec2::ZERO);

  // auto director = Director::getInstance();
  // auto visibleSize = director->getVisibleSize();
  // if (_backgroundNode->getPosition().x <= -(_backgroundNode->getContentSize().width))
  //   _backgroundNode->updatePosition();

  // auto pos = _backgroundNode->getPosition();
  // if (pos.x <= -(visibleSize.width + _backgroundNode->getContentSize().width + 1000))
  // {
  //   pos.x += visibleSize.width;
  //   _backgroundNode->setPosition(pos + backgroundScrollVert * dt);
  // }
  // else
  // {
  //   _backgroundNode->setPosition(_backgroundNode->getPosition() + backgroundScrollVert * dt);
  // }

  // _backgroundNode->incrementOffset(Vec2(_spacedust1->getContentSize().width * 2, 0), _spacedust1);
  // _backgroundNode->incrementOffset(Vec2(_spacedust2->getContentSize().width * 2, 0), _spacedust2);

  // std::vector<Sprite *> *spaceDusts = new std::vector<Sprite *>(2);
  // spaceDusts->push_back(_spacedust1);
  // spaceDusts->push_back(_spacedust2);
  // for (int ii = 0; ii < spaceDusts->size(); ii++)
  // {
  //   Sprite *spaceDust = spaceDusts->at(ii);
  //   // float xPosition = _backgroundNode->convertToWorldSpace(spaceDust->getPosition()).x;
  //   float xPosition = _backgroundNode->getPosition().x;
  //   float size = spaceDust->getContentSize().width;
  //   // if (xPosition < -size / 2)
  //   // {
  //   //   _backgroundNode->incrementOffset(Vec2(spaceDust->getContentSize().width * 2, 0), spaceDust);
  //   // }
  // }

  // std::vector<Node *> *backGrounds = new std::vector<Node *>(4);
  // backGrounds->push_back(_galaxy);
  // backGrounds->push_back(_planetsunrise);
  // backGrounds->push_back(_spacialanomaly);
  // backGrounds->push_back(_spacialanomaly2);
  // for (int ii = 0; ii < backGrounds->size(); ii++)
  // {
  //   Sprite *background = (Sprite *)(backGrounds->at(ii));
  //   float xPosition = _backgroundNode->convertToWorldSpace(background->getPosition()).x;
  //   float size = background->getContentSize().width;
  //   if (xPosition < -size)
  //   {
  //     _backgroundNode->incrementOffset(Vec2(2000, 0), background);
  //   }
  // }
}