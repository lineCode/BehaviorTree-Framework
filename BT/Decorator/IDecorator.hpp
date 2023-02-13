#ifndef IDECORATOR_HPP
#define IDECORATOR_HPP

#include "../Node/IBehavior.hpp"
using namespace BT::Node;

namespace BT {
namespace Decorator {

class IDecorator : public INode {
protected:
  INode *m_pChild = nullptr;

public:
  IDecorator(IAgent *agent, INode *child)
      : INode(agent), m_pChild(child){};

  virtual ~IDecorator() = default;
};

} // namespace Decorator
} // namespace BT

#endif // IDECORATOR_HPP
