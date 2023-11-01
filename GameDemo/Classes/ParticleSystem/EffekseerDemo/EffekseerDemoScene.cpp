#include "EffekseerDemoScene.h"

USING_NS_CC;

Scene *EffekseerDemo::createScene()
{
  return EffekseerDemo::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool EffekseerDemo::init()
{
  if (!Scene::init())
  {
    return false;
  }

  auto director = Director::getInstance();
  auto visibleSize = director->getVisibleSize();
  Vec2 origin = director->getVisibleOrigin();

  auto emitter = ParticleFireworks::create();
  addChild(emitter, 10);

  // auto emitter = ParticleFireworks::create();

  // // set the duration
  // emitter->setDuration(ParticleSystem::DURATION_INFINITY);

  // // radius mode
  // emitter->setEmitterMode(ParticleSystem::Mode::RADIUS);

  // // radius mode: 100 pixels from center
  // emitter->setStartRadius(100);
  // emitter->setStartRadiusVar(0);
  // emitter->setEndRadius(ParticleSystem::START_RADIUS_EQUAL_TO_END_RADIUS);
  // emitter->setEndRadiusVar(100); // not used when start == end

  // addChild(emitter, 10);

  // auto sprite = Sprite::create("HelloWorld.png");
  // sprite->setPosition(Vec2(320, 200));
  // this->addChild(sprite, 0);

  // // for update
  // this->scheduleUpdate();

  // manager = efk::EffectManager::create(visibleSize);

  return true;
}

// void EffekseerDemo::update(float delta)
// {
//   // Effect1
//   if (count % 300 == 0)
//   {
//     /**
//       You read an effect file with specifying scale.
//     */
//     auto effect = efk::Effect::create("Laser01.efk", 13.0f);
//     if (effect != nullptr)
//     {
//       /**
//         You generate an emitter, set parameters and add it to the layer.
//       */

//       auto emitter = efk::EffectEmitter::create(manager);
//       emitter->setEffect(effect);
//       emitter->setPlayOnEnter(true);

//       emitter->setRotation3D(cocos2d::Vec3(0, 90, 0));
//       emitter->setPosition(Vec2(320, 150));

//       // emitter->setScale(13);
//       this->addChild(emitter, 0);

//       // No need (because it uses autorelease after 1.41)
//       // effect->release();
//     }
//   }

//   // Effect2
//   if (count % 300 == 120)
//   {
//     /**
//         You read an effect file.
//     */
//     auto effect = efk::Effect::create("Homing_Laser01.efk");
//     if (effect != nullptr)
//     {
//       /**
//       You generate an emitter, set parameters and add it to the layer.
//       */

//       auto emitter = efk::EffectEmitter::create(manager);
//       emitter->setEffect(effect);
//       emitter->setPlayOnEnter(true);

//       emitter->setPosition(Vec2(320, 150));
//       emitter->setScale(4);
//       this->addChild(emitter, 0);

//       /**
//       Some parameters are required to set after addChild
//       */
//       emitter->setTargetPosition(cocos2d::Vec3(320, 480, 0));

//       // No need (because it uses autorelease after 1.41)
//       // effect->release();
//     }
//   }

//   /**
//     You update the manager every frame.
//   */
//   manager->update();

//   count++;
// }

// void EffekseerDemo::visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags)
// {
//   /**
//     You inherit visit and add a process to actually draw the effect.
//   */
//   manager->begin(renderer, _globalZOrder);
//   cocos2d::Scene::visit(renderer, parentTransform, parentFlags);
//   manager->end(renderer, _globalZOrder);
// }