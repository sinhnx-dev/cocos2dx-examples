#include "ParallaxNodeExtras.h"

// Hack to access CCPointObject (which is not a public class)
class PointObject : public Ref
{
  CC_SYNTHESIZE(Point, m_tRatio, Ratio)
  CC_SYNTHESIZE(Point, m_tOffset, Offset)
  CC_SYNTHESIZE(Node *, m_pChild, Child) // weak ref
};

// Need to provide a constructor
ParallaxNodeExtras::ParallaxNodeExtras()
{
  ParallaxNode(); // call parent constructor
}

ParallaxNodeExtras *ParallaxNodeExtras::node()
{
  return new ParallaxNodeExtras();
}

void ParallaxNodeExtras::incrementOffset(Point offset, Node *node)
{
  auto m_pParallaxArray = this->getChildren();
  for (unsigned int i = 0; i < m_pParallaxArray.size(); i++)
  {
    PointObject *point = (PointObject *)m_pParallaxArray.at(i);
    Node *curNode = point->getChild();
    if (curNode == node)
    {
      point->setOffset(point->getOffset() + offset);
      break;
    }
  }
}