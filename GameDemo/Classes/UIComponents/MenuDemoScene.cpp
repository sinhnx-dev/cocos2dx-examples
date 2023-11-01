#include "MenuDemoScene.h"

USING_NS_CC;

Scene *MenuDemo::createScene()
{
  return MenuDemo::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool MenuDemo::init()
{
  if (!Scene::init())
  {
    return false;
  }
  auto director = Director::getInstance();
  auto visibleSize = director->getVisibleSize();
  Vec2 origin = director->getVisibleOrigin();

  // auto singleMenu = Menu::create();
  // create a menu item by specifying images
  auto closeItem = MenuItemImage::create(
      "CloseNormal.png",
      "CloseSelected.png",
      CC_CALLBACK_1(MenuDemo::menuCloseCallback, this));
  float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
  float y = origin.y + closeItem->getContentSize().height / 2;
  closeItem->setPosition(Vec2(x, y));
  auto singleMenu = Menu::create(closeItem, NULL);
  singleMenu->setPosition(Vec2::ZERO);
  this->addChild(singleMenu, 1);

  // creating a Menu from a Vector of items
  Vector<MenuItem *> MenuItems;

  auto lblMenuExit = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 28);
  auto miExit = MenuItemLabel::create(
      lblMenuExit,
      CC_CALLBACK_1(MenuDemo::menuCloseCallback, this));
  miExit->setPosition(Vec2(0, -200));
  MenuItems.pushBack(miExit);
  /* repeat for as many menu items as needed */

  MenuItemFont::setFontSize(28);
  auto miFont = MenuItemFont::create(
      "Menu Item Font",
      [&](Ref *sender)
      {
        log("Menu Item Font Clicked!");
      });
  miFont->setPosition(Vec2(0, -150));
  MenuItems.pushBack(miFont);

  auto menu = Menu::createWithArray(MenuItems);
  this->addChild(menu, 1);

  return true;
}

void MenuDemo::menuCloseCallback(Ref *pSender)
{
  // Close the cocos2d-x game scene and quit the application
  Director::getInstance()->end();
}