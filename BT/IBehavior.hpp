#ifndef IBehavior_HPP
#define IBehavior_HPP

#include "../Agent/IAgent.hpp"
#include <stdexcept>

namespace BT {

enum struct EStatus { Invalid, Running, Success, Failure, Suspended, Aborted };

class IBehavior {
protected:
  IAgent *m_pAgent = nullptr;
  EStatus m_eStatus = EStatus::Invalid;

  virtual void Enter() = 0;
  virtual EStatus Execute() = 0;
  virtual void Exit() {}

public:
  IBehavior(IAgent *agent) : m_pAgent(agent) {}

  virtual ~IBehavior() = default;

  void Reset() { m_eStatus = EStatus::Invalid; }

  void Suspend() { m_eStatus = EStatus::Suspended; }

  void Abort() {
    m_eStatus = EStatus::Aborted;
    Exit();
  }

  bool IsTerminated() const {
    return m_eStatus == EStatus::Success || m_eStatus == EStatus::Failure;
  }

  bool IsRunning() const { return m_eStatus == EStatus::Running; }

  EStatus GetStatus() { return m_eStatus; }

  EStatus Tick() {
    if (m_eStatus != EStatus::Running)
      Enter();
    m_eStatus = Execute();
    if (m_eStatus != EStatus::Running)
      Exit();
    return m_eStatus;
  }
};

} // namespace BT

#endif // IBehavior_HPP
