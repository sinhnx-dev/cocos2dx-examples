#include "FirstScene.h"
#include "SecondScene.h"

USING_NS_CC;

Scene *FirstScene::createScene()
{
  return FirstScene::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool FirstScene::init()
{
  if (!Scene::init())
  {
    return false;
  }

  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  auto label = Label::createWithTTF("First Scene", "fonts/Marker Felt.ttf", 36);
  label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
  this->addChild(label);

  auto lblNextScene = Label::createWithTTF(
      "Next Scene",
      "fonts/Marker Felt.ttf",
      30);
  // auto miNextScene = MenuItemLabel::create(lblNextScene, [&](Ref *sender)
  MenuItemFont::setFontSize(24);
  auto miNextScene = MenuItemFont::create(
      "Next Scene",
      [&](Ref *sender)
      {
        auto secondScene = SecondScene::create();
        // Director::getInstance()->replaceScene(secondScene);
        // Director::getInstance()->replaceScene(TransitionFlipX::create(2, secondScene));
        // Director::getInstance()->replaceScene(TransitionFlipY::create(2, secondScene));
        Director::getInstance()->replaceScene(TransitionZoomFlipX::create(2, secondScene));
        // Director::getInstance()->replaceScene(TransitionZoomFlipY::create(2, secondScene));
        // Director::getInstance()->replaceScene(TransitionFade::create(1, secondScene, Color3B(255,255,0)));
        //  Director::getInstance()->replaceScene(TransitionSlideInT::create(1, secondScene) );
        log("Next Scene Clicked!");
      });
  miNextScene->setPosition(Vec2(0, -100));
  auto menu = Menu::create(miNextScene, NULL);
  this->addChild(menu);

  return true;
}