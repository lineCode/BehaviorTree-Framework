#ifndef MONITOR_HPP
#define MONITOR_HPP

#include "./Parallel.hpp"

namespace BT {
namespace Composite {

class Monitor : public Parallel {
public:
  Monitor(IAgent *agent)
      : Parallel(agent, Policy::RequireOne, Policy::RequireOne) {}

  ~Monitor() = default;

  void AddCondition(INode *condition) { m_lChildren.push_front(condition); }

  void AddAction(INode *action) { m_lChildren.push_back(action); }
};

} // namespace Composite
} // namespace BT

#endif // MONITOR_HPP
