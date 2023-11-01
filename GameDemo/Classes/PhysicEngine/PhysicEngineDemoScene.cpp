#include "PhysicEngineDemoScene.h"

USING_NS_CC;

Scene *PhysicEngineDemo::createScene()
{
  return PhysicEngineDemo::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool PhysicEngineDemo::init()
{
  if (!Scene::initWithPhysics())
  {
    return false;
  }
  this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();
  auto s_centre = Vec2(visibleSize.width / 2, visibleSize.height / 2);
  getPhysicsWorld()->setGravity(Vec2(0, 0));
  auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
  // auto edgeNode = Node::create();
  auto edgeNode = Layer::create();
  // edgeNode->setPosition(s_centre);
  edgeNode->setPhysicsBody(body);

  // create a sprite
  auto sprite = Sprite::create("HelloWorld.png");
  sprite->setPosition(s_centre);
  sprite->setScale(0.5f);
  edgeNode->addChild(sprite);

  auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
  physicsBody->setDynamic(false);

  // apply physicsBody to the sprite
  sprite->setPhysicsBody(physicsBody);
  // sprite->addComponent(physicsBody);

  // add five dynamic bodies
  for (int i = 0; i < 10; ++i)
  {
    sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(s_centre.x + cocos2d::random(-300, 300), s_centre.y + cocos2d::random(-300, 300)));
    sprite->setScale(0.3f);

    physicsBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
    // set the body isn't affected by the physics world's gravitational force
    physicsBody->setGravityEnable(false);
    // set initial velocity of physicsBody
    physicsBody->setVelocity(Vec2(cocos2d::random(-500, 500), cocos2d::random(-500, 500)));
    physicsBody->setTag(10);
    sprite->setPhysicsBody(physicsBody);
    edgeNode->addChild(sprite);
  }

  this->addChild(edgeNode);

  // adds contact event listener
  auto contactListener = EventListenerPhysicsContact::create();
  contactListener->onContactBegin = CC_CALLBACK_1(PhysicEngineDemo::onContactBegin, this);
  // contactListener->onContactBegin = [](cocos2d::PhysicsContact &contact)
  // {
  //   log("onContactBegin");
  //   return true;
  // };
  _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

  // schedule(
  //     [=](float delta) {
  //     },
  //     0.3f,
  //     "add sprite");

  return true;
}

bool PhysicEngineDemo::onContactBegin(cocos2d::PhysicsContact &contact)
{
  auto nodeA = contact.getShapeA()->getBody()->getNode();
  auto nodeB = contact.getShapeB()->getBody()->getNode();

  if (nodeA && nodeB)
  {
    if (nodeA->getTag() == 10)
    {
      nodeA->removeFromParentAndCleanup(true);
    }
    else if (nodeB->getTag() == 10)
    {
      nodeB->removeFromParentAndCleanup(true);
    }
  }
  // bodies can collide
  return true;
}

// auto visibleSize = Director::getInstance()->getVisibleSize();
// s_centre = Vec2(visibleSize.width/2, visibleSize.height/2);

// auto sprite1 = addSpriteAtPosition(Vec2(s_centre.x - 150,s_centre.y));
// sprite1->getPhysicsBody()->setCategoryBitmask(0x02);    // 0010
// sprite1->getPhysicsBody()->setCollisionBitmask(0x01);   // 0001

// sprite1 = addSpriteAtPosition(Vec2(s_centre.x - 150,s_centre.y + 100));
// sprite1->getPhysicsBody()->setCategoryBitmask(0x02);    // 0010
// sprite1->getPhysicsBody()->setCollisionBitmask(0x01);   // 0001

// auto sprite2 = addSpriteAtPosition(Vec2(s_centre.x + 150,s_centre.y),1);
// sprite2->getPhysicsBody()->setCategoryBitmask(0x01);    // 0001
// sprite2->getPhysicsBody()->setCollisionBitmask(0x02);   // 0010

// auto sprite3 = addSpriteAtPosition(Vec2(s_centre.x + 150,s_centre.y + 100),2);
// sprite3->getPhysicsBody()->setCategoryBitmask(0x03);    // 0011
// sprite3->getPhysicsBody()->setCollisionBitmask(0x03);   // 0011

// if ((shapeA->getCategoryBitmask() & shapeB->getCollisionBitmask()) == 0
//    || (shapeB->getCategoryBitmask() & shapeA->getCollisionBitmask()) == 0)
// {
//    // shapes can't collide
//    ret = false;
// }

// bool onContactBegin(PhysicsContact& contact){
//     auto bodyA = contact.getShapeA()->getBody();
//     auto bodyB = contact.getShapeB()->getBody();
//     return true;
// }

// bool init()
// {
//     auto visibleSize = Director::getInstance()->getVisibleSize();
//     s_centre = Vec2(visibleSize.width/2, visibleSize.height/2);

//     //create a static PhysicsBody
//     auto sprite = addSpriteAtPosition(s_centre, 1);
//     sprite->setTag(10);
//     sprite->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
//     sprite->getPhysicsBody()->setDynamic(false);

//     //adds contact event listener
//     auto contactListener = EventListenerPhysicsContact::create();
//     contactListener->onContactBegin = CC_CALLBACK_1(PhysicsDemoCollisionProcessing::onContactBegin, this);
//     _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

//     schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoCollisionProcessing::tick), 0.3f);
//     return true;

//     return false;
// }

// void tick(float dt)
// {
//     auto sprite1 = addSpriteAtPosition(Vec2(s_centre.x + cocos2d::random(-300,300),
//       s_centre.y + cocos2d::random(-300,300)));
//     auto physicsBody = sprite1->getPhysicsBody();
//     physicsBody->setVelocity(Vec2(cocos2d::random(-500,500),cocos2d::random(-500,500)));
//     physicsBody->setContactTestBitmask(0xFFFFFFFF);
// }