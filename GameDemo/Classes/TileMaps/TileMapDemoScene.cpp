#include "TileMapDemoScene.h"

USING_NS_CC;

Scene *TileMapDemo::createScene()
{
  return TileMapDemo::create();
}
// on "init" you need to initialize your instance
bool TileMapDemo::init()
{
  if (!Scene::init())
  {
    return false;
  }

  auto director = Director::getInstance();
  auto visibleSize = director->getVisibleSize();
  Vec2 origin = director->getVisibleOrigin();

  // reading in a tiled map.
  // auto map = TMXTiledMap::create("res/maps/tmw_desert_spacing_v190_sz.tmx");
  // map->setAnchorPoint(Vec2(0, 0));
  // map->setPosition(Vec2(0, 0));
  // auto background = map->getLayer("background");

  // this->addChild(map); // with a tag of '99'

  // how to get a specific layer
  // auto map = TMXTiledMap::create("TileMap.tmx");
  // auto layer = map->getLayer("Layer0");
  // auto tile = layer->getTileAt(Vec2(1, 63));

  // // to obtain a specific tiles id
  // unsigned int gid = layer->getTileGIDAt(Vec2(0, 63));

  _tileMap = new TMXTiledMap();
  _tileMap->initWithTMXFile("res/tilemap/TileMap.tmx");
  _background = _tileMap->getLayer("Background");
  _meta = _tileMap->getLayer("Meta");
  _meta->setVisible(false);

  _foreground = _tileMap->getLayer("Foreground");
  addChild(_tileMap);

  TMXObjectGroup *objGroup = _tileMap->getObjectGroup("Objects");
  if (objGroup == NULL)
  {
    log("tile map has no objects object layer");
    return false;
  }
  // ValueVector spawnPoint = objGroup->getObjects();
  ValueMap spawnPoint = objGroup->getObject("SpawnPoint");
  int x = spawnPoint.at("x").asInt();
  int y = spawnPoint.at("y").asInt();

  _player = new Sprite();
  _player->initWithFile("res/tilemap/Player.png");
  _player->setPosition(Vec2(x, y));
  addChild(_player);

  _numCollected = 0;
  _gameInfo = new GameInfoLayer();
  _gameInfo->init();
  this->addChild(_gameInfo);
  _gameInfo->numCollectedChanged(_numCollected);

  setViewPointCenter(_player->getPosition());

  auto touchEvent = EventListenerTouchOneByOne::create();
  touchEvent->onTouchBegan = [](Touch *touch, Event *event)
  {
    log("onTouchBegan event");
    return true;
  };
  touchEvent->onTouchMoved = [](Touch *touch, Event *event)
  {
    log("onTouchMoved event");
  };
  touchEvent->onTouchEnded = [=](Touch *touch, Event *event)
  {
    Point touchLocation = touch->getLocationInView();
    touchLocation = Director::getInstance()->convertToGL(touchLocation);
    touchLocation = this->convertToNodeSpace(touchLocation);

    Point playerPos = _player->getPosition();
    Point diff = touchLocation - playerPos;

    if (abs(diff.x) > abs(diff.y))
    {
      if (diff.x > 0)
      {
        playerPos.x += _tileMap->getTileSize().width;
      }
      else
      {
        playerPos.x -= _tileMap->getTileSize().width;
      }
    }
    else
    {
      if (diff.y > 0)
      {
        playerPos.y += _tileMap->getTileSize().height;
      }
      else
      {
        playerPos.y -= _tileMap->getTileSize().height;
      }
    }
    // safety check on the bounds of the map
    if (playerPos.x <= (_tileMap->getMapSize().width * _tileMap->getTileSize().width) &&
        playerPos.y <= (_tileMap->getMapSize().height * _tileMap->getTileSize().height) &&
        playerPos.y >= 0 &&
        playerPos.x >= 0)
    {
      this->setPlayerPosition(playerPos);
    }
    this->setViewPointCenter(_player->getPosition());
  };

  _eventDispatcher->addEventListenerWithSceneGraphPriority(touchEvent, _player);

  return true;
}

void TileMapDemo::setViewPointCenter(cocos2d::Point position)
{
  Size winSize = Director::getInstance()->getWinSize();
  int x = MAX(position.x, winSize.width / 2);
  int y = MAX(position.y, winSize.height / 2);
  x = MIN(x, (_tileMap->getMapSize().width * this->_tileMap->getTileSize().width) - winSize.width / 2);
  y = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height) - winSize.height / 2);
  Point actualPosition = Vec2(x, y);
  Point centerOfView = Vec2(winSize.width / 2, winSize.height / 2);
  Point viewPoint = centerOfView - actualPosition;
  _gameInfo->setPosition(viewPoint);
  this->setPosition(viewPoint);
}

Point TileMapDemo::tileCoordForPosition(Point position)
{
  int x = position.x / _tileMap->getTileSize().width;
  int y = (_tileMap->getMapSize().height * _tileMap->getTileSize().height - position.y) / _tileMap->getTileSize().height;
  return Point(x, y);
}
void TileMapDemo::setPlayerPosition(Point position)
{
  Point tileCoord = this->tileCoordForPosition(position);
  int tileGid = _meta->getTileGIDAt(tileCoord);
  if (tileGid)
  {
    cocos2d::Value prop = _tileMap->getPropertiesForGID(tileGid);
    if (!prop.isNull())
    {
      cocos2d::ValueMap vm = prop.asValueMap();
      if (vm.find("Collidable") != vm.cend() && !vm.at("Collidable").asString().compare("True"))
      {
        AudioEngine::play2d("res/tilemap/hit.caf");
        return;
      }
      if (vm.find("Collectable") != vm.cend() && !vm.at("Collectable").asString().compare("True"))
      {
        _meta->removeTileAt(tileCoord);
        _foreground->removeTileAt(tileCoord);
        _numCollected++;
        _gameInfo->numCollectedChanged(_numCollected);
        AudioEngine::play2d("res/tilemap/pickup.caf");
      }
      else
      {
        AudioEngine::play2d("res/tilemap/move.caf");
      }
    }
  }
  _player->setPosition(position);
}