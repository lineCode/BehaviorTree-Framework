#ifndef ACTIVESELECTOR_HPP
#define ACTIVESELECTOR_HPP

#include "./CSelector.hpp"

namespace BT {
namespace Composite {

class CActiveSelector : public CSelector {
public:
  CActiveSelector(IAgent *agent) : CSelector(agent){};

  ~CActiveSelector() = default;

  void Enter() override { m_itCurrent = m_lChildren.end(); }

  EStatus Execute() override {
    std::list<IBehavior *>::iterator prev = m_itCurrent;
    CSelector::Enter();
    EStatus result = CSelector::Execute();
    if (prev != m_lChildren.end() && m_itCurrent != prev)
      (*prev)->Abort();
    return result;
  }
};

} // namespace Composite
} // namespace BT

#endif // ACTIVESELECTOR_HPP
