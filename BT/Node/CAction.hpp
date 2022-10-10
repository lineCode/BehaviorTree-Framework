#if !defined(ACTION_HPP)
#define ACTION_HPP

#include "./IBehavior.hpp"
#include <functional>

namespace BT {
namespace Node {
  
class CAction : public IBehavior {
protected:
  void Enter() override {}

  EStatus Execute() override {
    return m_pTask ? m_pTask(m_pAgent) : EStatus::Failure;
  }

  void Exit(EStatus status) override {}

public:
  typedef std::function<EStatus(IAgent *agent)> Task;
  Task m_pTask = nullptr;

  CAction(IAgent *agent, Task task) : IBehavior(agent), m_pTask(task) {}

  ~CAction() = default;
};

} // namespace Node
} // namespace BT

#endif // ACTION_HPP
