#ifndef MONITOR_HPP
#define MONITOR_HPP

#include "./CParallel.hpp"

namespace BT {
namespace Composite {

class CMonitor : public CParallel {
public:
  CMonitor(IAgent *agent)
      : CParallel(agent, Policy::RequireOne, Policy::RequireOne) {}

  ~CMonitor() = default;

  void AddCondition(IBehavior *condition) { m_lChildren.push_front(condition); }

  void AddAction(IBehavior *action) { m_lChildren.push_back(action); }
};

} // namespace Composite
} // namespace BT

#endif // MONITOR_HPP
