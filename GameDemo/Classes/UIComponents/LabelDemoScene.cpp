#include "LabelDemoScene.h"

USING_NS_CC;

Scene *LabelDemo::createScene()
{
  return LabelDemo::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool LabelDemo::init()
{
  if (!Scene::init())
  {
    return false;
  }

  auto director = Director::getInstance();
  auto visibleSize = director->getVisibleSize();
  Vec2 origin = director->getVisibleOrigin();

  auto label = Label::create();
  label->setString("Label Default Value");
  label->setPosition(Vec2(visibleSize.width / 2, 50));
  this->addChild(label);

  // auto myLabel = Label::createWithBMFont("bitmapRed.fnt", "Your Text");

  auto labelTTF = Label::createWithTTF("Label with TTF font", "fonts/Marker Felt.ttf", 24);
  labelTTF->setPosition(Vec2(visibleSize.width / 2, 100));
  this->addChild(labelTTF);

  // create a TTFConfig files for labels to share
  TTFConfig labelConfig;
  labelConfig.fontFilePath = "fonts/Marker Felt.ttf";
  labelConfig.fontSize = 28;
  labelConfig.glyphs = GlyphCollection::DYNAMIC;
  labelConfig.outlineSize = 0;
  labelConfig.customGlyphs = nullptr;
  labelConfig.distanceFieldEnabled = false;

  // create a TTF Label from the TTFConfig file.
  auto labelWithConfig = Label::createWithTTF(labelConfig, "Label with custom config");
  labelWithConfig->setPosition(Vec2(visibleSize.width / 2, 150));
  this->addChild(labelWithConfig);

  auto labelSytemFont = Label::createWithSystemFont("Label with System Font", "Arial", 20);
  labelSytemFont->setPosition(Vec2(visibleSize.width / 2, 200));
  this->addChild(labelSytemFont);

  auto labelShadow = Label::createWithTTF("Label with Shadow Effect", "fonts/Marker Felt.ttf", 24);
  labelShadow->setPosition(Vec2(visibleSize.width / 2, 250));
  // shadow effect is supported by all Label types
  labelShadow->enableShadow();
  this->addChild(labelShadow);

  auto labelOutline = Label::createWithTTF("Label with Outline Effect", "fonts/Marker Felt.ttf", 24);
  labelOutline->setPosition(Vec2(visibleSize.width / 2, 300));
  // outline effect is TTF only, specify the outline color desired
  labelOutline->enableOutline(Color4B::GREEN, 1);
  this->addChild(labelOutline);

  auto labelGlow = Label::createWithTTF("Label with Glow Effect", "fonts/Marker Felt.ttf", 28);
  labelGlow->setPosition(Vec2(visibleSize.width / 2, 350));
  // outline effect is TTF only, specify the outline color desired
  labelGlow->enableGlow(Color4B::YELLOW);
  this->addChild(labelGlow);

  return true;
}