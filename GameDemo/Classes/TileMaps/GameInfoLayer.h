#ifndef __GameInfoLayer_H__
#define __GameInfoLayer_H__

#include "cocos2d.h"

class GameInfoLayer : public cocos2d::Layer
{
private:
  cocos2d::Label *_label;

public:
  virtual bool init();
  static cocos2d::Scene(scene);
  void menuCloseCallback(cocos2d::Ref *pSender);
  void numCollectedChanged(int numCollected);

  CREATE_FUNC(GameInfoLayer);
};

#endif //__GameInfoLayer_H__