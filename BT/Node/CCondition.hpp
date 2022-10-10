#if !defined(CONDITION_HPP)
#define CONDITION_HPP

#include "./IBehavior.hpp"
#include <functional>

namespace BT {
namespace Node {

class CCondition : public IBehavior {
protected:
  void Enter() override {}

  EStatus Execute() override {
    if (m_pTask && m_pTask(m_pAgent))
      return EStatus::Success;
    return EStatus::Failure;
  }

  void Exit() override {}

public:
  typedef std::function<bool(IAgent *agent)> Task;
  Task m_pTask = nullptr;

  CCondition(IAgent *agent, Task task) : IBehavior(agent), m_pTask(task) {}

  ~CCondition() = default;
};

} // namespace Node
} // namespace BT

#endif // CONDITION_HPP
