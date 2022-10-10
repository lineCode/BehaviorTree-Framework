#if !defined(BEHAVIORTREE_HPP)
#define BEHAVIORTREE_HPP

#include "./Node/CAction.hpp"
#include "./Composite/CActiveSelector.hpp"
#include "./Composite/CFilter.hpp"
#include "./Composite/CMonitor.hpp"
#include "./Composite/CParallel.hpp"
#include "./Composite/CSelector.hpp"
#include "./Composite/CSequence.hpp"
#include "./Node/CCondition.hpp"
#include "./Decorator/CRepeat.hpp"
using namespace BT;

class CBehaviorTree
{
private:
  /* data */
public:
  CBehaviorTree(/* args */) = default;
  ~CBehaviorTree() = default;
};

#endif // BEHAVIORTREE_HPP
