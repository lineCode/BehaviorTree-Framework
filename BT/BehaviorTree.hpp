#if !defined(BEHAVIORTREE_HPP)
#define BEHAVIORTREE_HPP

#include "./Composite/ActiveSelector.hpp"
#include "./Composite/Filter.hpp"
#include "./Composite/Monitor.hpp"
#include "./Composite/Parallel.hpp"
#include "./Composite/Selector.hpp"
#include "./Composite/Sequence.hpp"
#include "./Decorator/Repeat.hpp"
#include "./Node/Action.hpp"
#include "./Node/Condition.hpp"
#include <list>

using namespace BT;

class BehaviorTree {
  std::list<INode *> m_lBehaviors;

public:
  BehaviorTree() = default;
  
  ~BehaviorTree() = default;
};

#endif // BEHAVIORTREE_HPP
