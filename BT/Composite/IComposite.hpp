#ifndef ICOMPOSITE_HPP
#define ICOMPOSITE_HPP

#include "../IBehavior.hpp"
#include <list>

namespace BT {
namespace Composite {

class IComposite : public IBehavior {
protected:
  std::list<IBehavior *> m_lChildren;
  std::list<IBehavior *>::iterator m_itCurrent;

public:
  IComposite(IAgent *agent) : IBehavior(agent){};

  virtual ~IComposite() = default;

  void AddChild(IBehavior *child) { m_lChildren.push_back(child); }

  void RemoveChild(IBehavior *node) { m_lChildren.remove(node); }

  void Clear() { m_lChildren.clear(); }

  virtual void Enter() override { m_itCurrent = m_lChildren.begin(); }
};

} // namespace Composite
} // namespace BT

#endif // ICOMPOSITE_HPP
