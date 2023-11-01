#ifndef __TILE_MAP_DEMO_SCENE_H__
#define __TILE_MAP_DEMO_SCENE_H__

#include "cocos2d.h"
#include "AudioEngine.h"
#include "GameInfoLayer.h"

class TileMapDemo : public cocos2d::Scene
{
private:
  cocos2d::TMXTiledMap *_tileMap;
  cocos2d::TMXLayer *_background;
  cocos2d::Sprite *_player;
  cocos2d::TMXLayer *_meta;
  cocos2d::TMXLayer *_foreground;
  GameInfoLayer *_gameInfo;
  int _numCollected;

public:
  static cocos2d::Scene *createScene();

  virtual bool init();
  void setViewPointCenter(cocos2d::Point position);
  cocos2d::Point tileCoordForPosition(cocos2d::Point position);
  void setPlayerPosition(cocos2d::Point position);

  // implement the "static create()" method manually
  CREATE_FUNC(TileMapDemo);
};

#endif // __TILE_MAP_DEMO_SCENE_H__