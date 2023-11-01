#include "ActionsDemoScene.h"

USING_NS_CC;

Scene *ActionsDemo::createScene()
{
  return ActionsDemo::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool ActionsDemo::init()
{
  if (!Scene::init())
  {
    return false;
  }
  auto dirs = Director::getInstance();
  auto visibleSize = dirs->getVisibleSize();
  Vec2 origin = dirs->getVisibleOrigin();

  // add a "close" icon to exit the progress. it's an autorelease object
  auto closeItem = MenuItemImage::create(
      "CloseNormal.png",
      "CloseSelected.png",
      CC_CALLBACK_1(ActionsDemo::menuCloseCallback, this));

  if (closeItem == nullptr ||
      closeItem->getContentSize().width <= 0 ||
      closeItem->getContentSize().height <= 0)
  {
    problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
  }
  else
  {
    float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
    float y = origin.y + closeItem->getContentSize().height / 2;
    closeItem->setPosition(Vec2(x, y));
  }

  // create menu, it's an autorelease object
  auto menu = Menu::create(closeItem, NULL);
  menu->setPosition(Vec2::ZERO);
  this->addChild(menu, 1);

  auto sprite = Sprite::create("HelloWorld.png");
  sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
  this->addChild(sprite);
  // Move sprite to position 50,10 in 2 seconds.
  auto moveTo = MoveTo::create(2, Vec2(50, 10));
  // sprite->runAction(moveTo);

  // Move sprite 20 points to right in 2 seconds.
  auto moveBy = MoveBy::create(2, Vec2(50, 10));
  // sprite->runAction(moveBy);

  // Rotates a Node to the specific angle over 2 seconds
  auto rotateTo = RotateTo::create(2.0f, 40.0f);
  // sprite->runAction(rotateTo);

  // Rotates a Node clockwise by 40 degree over 2 seconds
  auto rotateBy = RotateBy::create(2.0f, 40.0f);
  // sprite->runAction(rotateBy);

  // Scale to uniformly to 3x over 2 seconds
  auto scaleTo = ScaleTo::create(2.0f, 3.0f);
  // sprite->runAction(scaleTo);

  // Scale X by 5 and Y by 3x over 2 seconds
  auto scaleBy = ScaleBy::create(2.0f, 3.0f, 3.0f);
  // sprite->runAction(scaleBy);

  // fades in the sprite in 2 seconds
  auto fadeIn = FadeIn::create(2.0f);
  // sprite->runAction(fadeIn);

  // fades out the sprite in 2 seconds
  auto fadeOut = FadeOut::create(2.0f);
  // sprite->runAction(fadeOut);

  // fades to the sprite in 2 seconds
  auto fadeTo = FadeTo::create(2.0f, 100.0f);
  // sprite->runAction(fadeTo);

  // Tints a node to the specified RGB values
  auto tintTo = TintTo::create(2.0f, 255.0f, 255.0f, 0.0f);
  // sprite->runAction(tintTo);

  // Tints a node BY the delta of the specified RGB values.
  auto tintBy = TintBy::create(2.0f, 120.0f, 232.0f, 254.0f);
  // sprite->runAction(tintBy);

  // create a MoveBy Action to where we want the sprite to drop from.
  auto move = MoveBy::create(2, Vec2(100, dirs->getVisibleSize().height - sprite->getContentSize().height));
  auto move_back = move->reverse();
  // create a BounceIn Ease Action
  auto move_ease_in = EaseBounceIn::create(move->clone());
  auto move_ease_in_back = move_ease_in->reverse();
  // create a delay that is run in between sequence events
  auto delay = DelayTime::create(0.25f);
  // create the sequence of actions, in the order we want to run them
  auto seq1 = Sequence::create(move, delay, move_back, delay->clone(), move_ease_in, delay->clone(), move_ease_in_back, delay->clone(), nullptr);
  // run the sequence and repeat forever.
  // sprite->runAction(RepeatForever::create(seq1));

  // create a few actions.
  auto jump = JumpBy::create(0.5, Vec2(0, 0), 100, 1);
  auto rotate = RotateTo::create(2.0f, 10);
  // create a few callbacks
  auto callbackJump = CallFunc::create([]()
                                       { log("Jumped!"); });
  auto callbackRotate = CallFunc::create([]()
                                         { log("Rotated!"); });
  // create a sequence with the actions and callbacks
  auto seq = Sequence::create(jump, callbackJump, rotate, callbackRotate, nullptr);
  // run it
  // sprite->runAction(seq);

  // auto moveBy = MoveBy::create(10, Vec2(400, 100));
  // auto fadeTo = FadeTo::create(2.0f, 120.0f);

  // running the above Actions with Spawn.
  auto mySpawn = Spawn::createWithTwoActions(moveBy, fadeTo);
  sprite->runAction(mySpawn);

  // running the above Actions with consecutive runAction() statements.
  sprite->runAction(moveBy);
  sprite->runAction(fadeTo);

  // create a Spawn to use
  // auto mySpawn = Spawn::createWithTwoActions(scaleBy, fadeTo);
  // tie everything together in a sequence
  auto seq5 = Sequence::create(moveBy, mySpawn, moveBy, nullptr);
  // run it
  sprite->runAction(seq5);

  // // create our Sprites
  // auto heroSprite = Sprite::create("herosprite.png");
  // auto enemySprite = Sprite::create("enemysprite.png");

  // // create an Action
  // auto moveBy = MoveBy::create(10, Vec2(400, 100));
  // // run it on our hero
  // heroSprite->runAction(moveBy);
  // // run it on our enemy
  // enemySprite->runAction(moveBy->clone()); // correct! This will be unique

  // // create a Sprite
  // auto mySprite = Sprite::create("mysprite.png");
  // mySprite->setPosition(50, 56);
  // // create a few Actions
  // auto moveBy = MoveBy::create(2.0f, Vec2(500, 0));
  // auto scaleBy = ScaleBy::create(2.0f, 2.0f);
  // auto delay = DelayTime::create(2.0f);
  // // create a sequence
  // auto delaySequence = Sequence::create(delay, delay->clone(), delay->clone(),
  //                                       delay->clone(), nullptr);
  // auto sequence = Sequence::create(moveBy, delay, scaleBy, delaySequence, nullptr);
  // // run it
  // newSprite2->runAction(sequence);
  // // reverse it
  // newSprite2->runAction(sequence->reverse());

  return true;
}

void ActionsDemo::menuCloseCallback(Ref *pSender)
{
  // Close the cocos2d-x game scene and quit the application
  Director::getInstance()->end();

  /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

  // EventCustom customEndEvent("game_scene_close_event");
  //_eventDispatcher->dispatchEvent(&customEndEvent);
}