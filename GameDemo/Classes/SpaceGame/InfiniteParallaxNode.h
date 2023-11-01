#ifndef SpaceGame_InfiniteParallaxNode_h
#define SpaceGame_InfiniteParallaxNode_h

#include "cocos2d.h"

USING_NS_CC;

class InfiniteParallaxNode : public ParallaxNode
{
public:
  static InfiniteParallaxNode *create();
  void updatePosition();
};

#endif