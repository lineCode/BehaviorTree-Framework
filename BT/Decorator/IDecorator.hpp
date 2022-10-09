#ifndef IDECORATOR_HPP
#define IDECORATOR_HPP

#include "../IBehavior.hpp"

namespace BT {
namespace Decorator {

class IDecorator : public IBehavior {
protected:
  IBehavior *m_pChild = nullptr;

public:
  IDecorator(IAgent *agent, IBehavior *child)
      : IBehavior(agent), m_pChild(child){};

  virtual ~IDecorator() = default;
};

} // namespace Decorator
} // namespace BT

#endif // IDECORATOR_HPP
