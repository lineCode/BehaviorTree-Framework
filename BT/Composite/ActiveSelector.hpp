#ifndef ACTIVESELECTOR_HPP
#define ACTIVESELECTOR_HPP

#include "./Selector.hpp"

namespace BT {
namespace Composite {

class ActiveSelector : public Selector {
public:
  ActiveSelector(IAgent *agent) : Selector(agent){};

  ~ActiveSelector() = default;

  void Enter() override { m_itCurrent = m_lChildren.end(); }

  EStatus Execute() override {
    std::list<IBehavior *>::iterator prev = m_itCurrent;
    Selector::Enter();
    EStatus result = Selector::Execute();
    if (prev != m_lChildren.end() && m_itCurrent != prev)
      (*prev)->Abort();
    return result;
  }
};

} // namespace Composite
} // namespace BT

#endif // ACTIVESELECTOR_HPP
