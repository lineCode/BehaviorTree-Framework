#ifndef ICOMPOSITE_HPP
#define ICOMPOSITE_HPP

#include "../Node/IBehavior.hpp"
#include <list>
using namespace BT::Node;

namespace BT {
namespace Composite {

class IComposite : public INode {
protected:
  std::list<INode *> m_lChildren;
  std::list<INode *>::iterator m_itCurrent;

public:
  IComposite(IAgent *agent) : INode(agent){};

  virtual ~IComposite() = default;

  void AddChild(INode *child) { m_lChildren.push_back(child); }

  void RemoveChild(INode *node) { m_lChildren.remove(node); }

  void Clear() { m_lChildren.clear(); }

  virtual void Enter() override { m_itCurrent = m_lChildren.begin(); }
};

} // namespace Composite
} // namespace BT

#endif // ICOMPOSITE_HPP
