#include "AudioEngineDemoScene.h"

// using namespace CocosDenshion;
USING_NS_CC;

Scene *AudioEngineDemo::createScene()
{
  return AudioEngineDemo::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
  printf("Error while loading: %s\n", filename);
  printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// on "init" you need to initialize your instance
bool AudioEngineDemo::init()
{
  if (!Scene::initWithPhysics())
  {
    return false;
  }
  // AudioEngine::preload("audio/rock-808-beat.mp3");

  // AudioEngine::play2d("audio/rock-808-beat.mp3", true, 0.5f);

  // AudioEngine::play2d("take-out-yo-spoon.wav", false, 1.0f);
  // AudioEngine::stop(0);
  // int audioId2;
  // AudioEngine::preload(
  //     "audio/sound-short-generic.wav",
  //     [&](bool isSuccess)
  //     {
  //       log("load audio/sound-short-generic.wav completed.");
  //       audioId2 = AudioEngine::play2d("audio/sound-short-generic.wav");
  //       return true;
  //     });
  // AudioEngine::play2d("audio/music-loop-002.wav", true, 1.0f);
  // AudioEngine::pauseAll();
  // set the background music and continuously play it.
  // audio->playBackgroundMusic("audio/rock-808-beat.mp3", true);

  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  // The background music
  AudioEngine::play2d("audio/piano-loops.wav", true, 1.0f);
  auto slider = ui::Slider::create();
  slider->loadBarTexture("res/ui/Slider_Back.png");
  slider->loadSlidBallTextures("res/ui/SliderNode_Normal.png", "res/ui/SliderNode_Press.png", "res/ui/SliderNode_Disable.png");
  slider->loadProgressBarTexture("res/ui/Slider_PressBar.png");
  slider->addEventListener(
      [&](Ref *sender, ui::Slider::EventType type)
      {
        if (type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
          auto s = dynamic_cast<ui::Slider *>(sender);
          log("music percent: %d", s->getPercent());
          AudioEngine::setVolume(0, (float)s->getPercent() / 100);
        }
      });
  slider->setPercent(100);
  slider->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 150));
  auto lblVolume = Label::createWithSystemFont("Volume", "fonts/Arial.ttf", 20);
  lblVolume->setAnchorPoint(Vec2(0, 0.5));
  lblVolume->setPosition(
      Vec2(slider->getContentSize().width * 1.1,
           slider->getContentSize().height / 2));
  slider->addChild(lblVolume);
  this->addChild(slider);

  auto checkbox = ui::CheckBox::create(
      "res/ui/CheckBox_Normal.png",
      "res/ui/CheckBox_Press.png",
      "res/ui/CheckBoxNode_Normal.png",
      "res/ui/CheckBoxNode_Disable.png",
      "res/ui/CheckBox_Disable.png");
  auto cbLabel = Label::createWithSystemFont(
      "Background Music",
      "fonts/Arial.ttf", 20);
  cbLabel->setAnchorPoint(Vec2(0, 0.5));
  cbLabel->setPosition(
      Vec2(checkbox->getContentSize().width * 1.2,
           checkbox->getContentSize().height / 2));
  checkbox->addChild(cbLabel);
  checkbox->setSelected(true);
  checkbox->addEventListener(
      [&](Ref *sender, ui::CheckBox::EventType type)
      {
        switch (type)
        {
            case ui::CheckBox::EventType::SELECTED:
                printf("Background Music Selected\n");
                AudioEngine::resume(0);
                break;
            case ui::CheckBox::EventType::UNSELECTED:
                printf("Background Music Unselected\n");
                AudioEngine::pause(0);
                break;
            default:
                break;
        } });
  checkbox->setPosition(
      Vec2(visibleSize.width / 2,
           visibleSize.height / 2 + 100));
  this->addChild(checkbox);

  // MenuItemFont::setFontSize(28);
  auto miSoundEffect = MenuItemFont::create(
      "Play Audio Effect",
      [&](Ref *sender)
      {
        log("Play Audio Effect!");
        AudioEngine::play2d("audio/sound-short-generic.wav");
      });
  miSoundEffect->setPosition(Vec2::ZERO);
  this->addChild(Menu::create(miSoundEffect, nullptr));

  return true;
}