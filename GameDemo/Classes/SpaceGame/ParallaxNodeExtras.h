#ifndef SpaceGame_ParallaxNodeExtras_h
#define SpaceGame_ParallaxNodeExtras_h

#include "cocos2d.h"

USING_NS_CC;

class ParallaxNodeExtras : public ParallaxNode
{

public:
  // Need to provide a constructor
  ParallaxNodeExtras();

  // just to avoid ugly later cast and also for safety
  static ParallaxNodeExtras *node();

  // Facility method (it’s expected to have it soon in COCOS2D-X)
  void incrementOffset(Point offset, Node *node);
};

#endif