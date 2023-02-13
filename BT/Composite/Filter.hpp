#ifndef FILTER_HPP
#define FILTER_HPP

#include "./Sequence.hpp"

namespace BT {
namespace Composite {

class Filter : public Sequence {
public:
  Filter(IAgent *agent) : Sequence(agent) {}

  ~Filter() = default;

  void AddCondition(INode *condition) { m_lChildren.push_front(condition); }

  void AddAction(INode *action) { m_lChildren.push_back(action); }
};

} // namespace Composite
} // namespace BT

#endif // FILTER_HPP
