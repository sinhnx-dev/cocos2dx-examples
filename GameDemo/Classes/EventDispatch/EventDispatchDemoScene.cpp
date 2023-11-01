#include "EventDispatchDemoScene.h"

USING_NS_CC;

Scene *EventDispatchDemo::createScene()
{
  return EventDispatchDemo::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool EventDispatchDemo::init()
{
  if (!Scene::init())
  {
    return false;
  }
  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  // add "HelloWorld" splash screen"
  auto sprite = Sprite::create("HelloWorld.png");
  if (sprite == nullptr)
  {
    problemLoading("'HelloWorld.png'");
  }
  else
  {
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
  }

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
  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite);
  // _eventDispatcher->removeEventListener(listener);
  auto kbListener = EventListenerKeyboard::create();
  kbListener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event *event)
  {
    int speed = 10;
    Vec2 loc = event->getCurrentTarget()->getPosition();
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
    case EventKeyboard::KeyCode::KEY_A:
      event->getCurrentTarget()->setPosition(loc.x - speed, loc.y);
      break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
    case EventKeyboard::KeyCode::KEY_D:
      event->getCurrentTarget()->setPosition(loc.x + speed, loc.y);
      break;
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
    case EventKeyboard::KeyCode::KEY_W:
      event->getCurrentTarget()->setPosition(loc.x, loc.y + speed);
      break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
    case EventKeyboard::KeyCode::KEY_S:
      event->getCurrentTarget()->setPosition(loc.x, loc.y - speed);
      break;
    default:
      break;
    }
  };
  // Add listener
  _eventDispatcher->addEventListenerWithSceneGraphPriority(kbListener, sprite);

  // // creating an accelerometer event
  // auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(AccelerometerTest::onAcceleration, this));

  // _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

  // // Implementation of the accelerometer callback function prototype
  // void AccelerometerTest::onAcceleration(Acceleration * acc, Event * event)
  // {
  //   //  Processing logic here
  // }

  /* Mouse Event */
  auto _mouseListener = EventListenerMouse::create();
  _mouseListener->onMouseMove = CC_CALLBACK_1(EventDispatchDemo::onMouseMove, this);
  _mouseListener->onMouseUp = CC_CALLBACK_1(EventDispatchDemo::onMouseUp, this);
  _mouseListener->onMouseDown = CC_CALLBACK_1(EventDispatchDemo::onMouseDown, this);
  _mouseListener->onMouseScroll = CC_CALLBACK_1(EventDispatchDemo::onMouseScroll, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);

  return true;
}

void EventDispatchDemo::onMouseDown(Event *event)
{
  // to illustrate the event....
  EventMouse *e = (EventMouse *)event;
  log("Mouse Down detected");
}

void EventDispatchDemo::onMouseUp(Event *event)
{
  // to illustrate the event....
  EventMouse *e = (EventMouse *)event;
  log("Mouse Up detected");
}

void EventDispatchDemo::onMouseMove(Event *event)
{
  // to illustrate the event....
  EventMouse *e = (EventMouse *)event;
  log("Mouse move detected with position: x: %f, y: %f", e->getCursorX(), e->getCursorY());
}

void EventDispatchDemo::onMouseScroll(Event *event)
{
  // to illustrate the event....
  EventMouse *e = (EventMouse *)event;
  log("Mouse Scroll detected with position: x: %f, y: %f", e->getCursorX(), e->getCursorY());

  // auto _listener = EventListenerCustom::create(
  //     "game_custom_event1",
  //     [=](EventCustom *event)
  //     {
  //   std::string str("Custom event 1 received, ");
  //   char* buf = static_cast<char*>(event->getUserData());
  //   str += buf;
  //   str += " times";
  //   statusLabel->setString(str.c_str()); });
  // _eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}