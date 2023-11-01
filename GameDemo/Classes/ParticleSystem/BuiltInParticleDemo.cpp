#include "BuiltInParticleDemo.h"

USING_NS_CC;

Scene *BuiltInParticleDemo::createScene()
{
  return BuiltInParticleDemo::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool BuiltInParticleDemo::init()
{
  if (!Scene::init())
  {
    return false;
  }

  auto director = Director::getInstance();
  auto visibleSize = director->getVisibleSize();
  Vec2 origin = director->getVisibleOrigin();

  auto fireworks = ParticleFireworks::create();
  addChild(fireworks, 10);

  auto fire = ParticleFire::create();
  fire->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 2));
  fire->setScale(0.5);
  addChild(fire, 10);

  auto snow = ParticleSnow::create();
  snow->setPosition(Vec2(visibleSize.width / 2, visibleSize.height));
  addChild(snow, 10);

  // create by plist file
  auto particleSystem = ParticleSystem::create("SpinningPeas.plist");

  return true;
}