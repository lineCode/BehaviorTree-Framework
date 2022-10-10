#if !defined(BEHAVIORTREE_HPP)
#define BEHAVIORTREE_HPP

#include "./Composite/CActiveSelector.hpp"
#include "./Composite/CFilter.hpp"
#include "./Composite/CMonitor.hpp"
#include "./Composite/CParallel.hpp"
#include "./Composite/CSelector.hpp"
#include "./Composite/CSequence.hpp"
#include "./Decorator/CRepeat.hpp"
#include "./Node/CAction.hpp"
#include "./Node/CCondition.hpp"
#include <list>

using namespace BT;

class CBehaviorTree {
  std::list<IBehavior *> m_lBehaviors;

public:
  CBehaviorTree() = default;
  
  ~CBehaviorTree() = default;
};

#endif // BEHAVIORTREE_HPP
