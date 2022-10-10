#ifndef FILTER_HPP
#define FILTER_HPP

#include "./CSequence.hpp"

namespace BT {
namespace Composite {

class CFilter : public CSequence {
public:
  CFilter(IAgent *agent) : CSequence(agent) {}

  ~CFilter() = default;

  void AddCondition(IBehavior *condition) { m_lChildren.push_front(condition); }

  void AddAction(IBehavior *action) { m_lChildren.push_back(action); }
};

} // namespace Composite
} // namespace BT

#endif // FILTER_HPP
