#if !defined(CONDITION_HPP)
#define CONDITION_HPP

#include "./IBehavior.hpp"
#include <functional>

namespace BT {
namespace Node {

class Condition : public INode {
protected:
  void Enter() override {}

  EStatus Execute() override {
    if (m_pTask && m_pTask(m_pAgent))
      return EStatus::Success;
    return EStatus::Failure;
  }

  void Exit(EStatus status) override {}

public:
  typedef std::function<bool(IAgent *agent)> Task;
  Task m_pTask = nullptr;

  Condition(IAgent *agent, Task task) : INode(agent), m_pTask(task) {}

  ~Condition() = default;
};

} // namespace Node
} // namespace BT

#endif // CONDITION_HPP
