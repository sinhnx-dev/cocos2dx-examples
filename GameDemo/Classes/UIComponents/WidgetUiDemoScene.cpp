#include "WidgetUiDemoScene.h"

USING_NS_CC;

Scene *WidgetUiDemo::createScene()
{
  return WidgetUiDemo::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool WidgetUiDemo::init()
{
  if (!Scene::init())
  {
    return false;
  }

  auto director = Director::getInstance();
  auto visibleSize = director->getVisibleSize();
  Vec2 origin = director->getVisibleOrigin();

  auto button = ui::Button::create("res/ui/Button_Normal.png", "res/ui/Button_Press.png", "res/ui/Button_Disabled.png");
  button->setTitleText("Button");
  // button->setColor(Color3B::GREEN);
  button->setTitleColor(Color3B::BLACK);
  button->addTouchEventListener(
      [&](Ref *sender, ui::Widget::TouchEventType type)
      {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
          break;
        case ui::Widget::TouchEventType::ENDED:
          log("Button 1 clicked!");
          break;
        default:
          break;
        }
      });
  button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
  this->addChild(button);

  auto checkbox = ui::CheckBox::create("res/ui/CheckBox_Normal.png",
                                       "res/ui/CheckBox_Press.png",
                                       "res/ui/CheckBoxNode_Normal.png",
                                       "res/ui/CheckBoxNode_Disable.png",
                                       "res/ui/CheckBox_Disable.png");

  checkbox->addTouchEventListener(
      [&](Ref *sender, ui::Widget::TouchEventType type)
      {
        switch (type)
        {
                case ui::Widget::TouchEventType::BEGAN:
                        break;
                case ui::Widget::TouchEventType::ENDED:
                        log("checkbox 1 clicked!");
                        break;
                default:
                        break;
        } });
  auto cbLabel = Label::createWithSystemFont("Label for Checkbox", "Arial", 20);
  cbLabel->setAnchorPoint(Vec2(0, 0.5));
  cbLabel->setPosition(Vec2(checkbox->getContentSize().width * 1.2, checkbox->getContentSize().height / 2));
  checkbox->addChild(cbLabel);
  checkbox->addEventListener(
      [&](Ref *sender, ui::CheckBox::EventType type)
      {
        switch (type)
        {
            case ui::CheckBox::EventType::SELECTED:
                printf("Check Box Selected1\n");
                break;
            case ui::CheckBox::EventType::UNSELECTED:
                printf("Check Box Unselected1\n");
                break;
            default:
                break;
        } });
  checkbox->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 50));
  this->addChild(checkbox);

  auto loadingBar = ui::LoadingBar::create("res/ui/LoadingBarFile.png");
  loadingBar->setDirection(ui::LoadingBar::Direction::LEFT);
  loadingBar->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100));
  loadingBar->setPercent(0);
  this->addChild(loadingBar);
  this->schedule(
      [=](float delta)
      {
        float percent = loadingBar->getPercent();
        percent++;
        loadingBar->setPercent(percent);
        if (percent>=100.0f) {
            this->unschedule("updateLoadingBar");
        } },
      0.1f, "updateLoadingBar");

  auto slider = ui::Slider::create();
  slider->loadBarTexture("res/ui/Slider_Back.png"); // what the slider looks like
  slider->loadSlidBallTextures("res/ui/SliderNode_Normal.png", "res/ui/SliderNode_Press.png", "res/ui/SliderNode_Disable.png");
  slider->loadProgressBarTexture("res/ui/Slider_PressBar.png");
  slider->addTouchEventListener(
      [&](Ref *sender, ui::Widget::TouchEventType type)
      {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
          break;
        case ui::Widget::TouchEventType::ENDED:
          log("slider moved and percent is %d", ((ui::Slider *)sender)->getPercent());
          break;
        default:
          break;
        }
      });
  slider->addEventListener(
      [&](Ref *sender, ui::Slider::EventType type)
      {
        if (type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
          log("slider changed");
          auto s = dynamic_cast<ui::Slider *>(sender);
          log("slider percent: %d", s->getPercent());
        }
      });
  slider->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 150));
  this->addChild(slider);

  auto textField = ui::TextField::create("Text Field", "Arial", 30);
  textField->addTouchEventListener(
      [&](Ref *sender, ui::Widget::TouchEventType type)
      { log("editing a TextField"); });
  textField->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 200));
  this->addChild(textField);

  auto passwordField = ui::TextField::create("Password", "Arial", 30);
  passwordField->setPasswordEnabled(true);
  passwordField->addTouchEventListener(
      [&](Ref *sender, ui::Widget::TouchEventType type)
      { log("editing a PasswordField"); });
  passwordField->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 250));
  this->addChild(passwordField);

  auto richText = ui::RichText::create();
  richText->ignoreContentAdaptWithSize(false);
  richText->setContentSize(Size(200, 300));
  richText->setAnchorPoint(Vec2(0.5, 0));
  richText->setPosition(Vec2(visibleSize.width / 2, 0));
  ui::RichElementText *re1 = ui::RichElementText::create(1, Color3B::WHITE, 255, "This is white color", "/fonts/arial.ttf", 24);
  ui::RichElementText *re2 = ui::RichElementText::create(2, Color3B::YELLOW, 255, "This is yellow color", "/fonts/Marker Felt.ttf", 20);
  richText->pushBackElement(re1);
  richText->pushBackElement(re2);
  this->addChild(richText);

  return true;
}