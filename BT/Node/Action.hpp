#if !defined(ACTION_HPP)
#define ACTION_HPP

#include "./IBehavior.hpp"
#include <functional>

namespace BT {
namespace Node {
  
class Action : public INode {
protected:
  void Enter() override {}

  EStatus Execute() override {
    return m_pTask ? m_pTask(m_pAgent) : EStatus::Failure;
  }

  void Exit(EStatus status) override {}

public:
  typedef std::function<EStatus(IAgent *agent)> Task;
  Task m_pTask = nullptr;

  Action(IAgent *agent, Task task) : INode(agent), m_pTask(task) {}

  ~Action() = default;
};

} // namespace Node
} // namespace BT

#endif // ACTION_HPP
