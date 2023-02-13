#ifndef IBEHAVIOR_HPP
#define IBEHAVIOR_HPP

#include "../../Agent/IAgent.hpp"
#include <stdexcept>

namespace BT
{
  namespace Node
  {
    enum struct EStatus
    {
      Invalid,
      Running,
      Success,
      Failure,
      Suspended,
      Aborted
    };

    class INode
    {
    protected:
      IAgent *m_pAgent = nullptr;
      EStatus m_eStatus = EStatus::Invalid;

      virtual void Enter() = 0;
      virtual EStatus Execute() = 0;
      virtual void Exit(EStatus status) {}

    public:
      INode(IAgent *agent) : m_pAgent(agent) {}

      virtual ~INode() = default;

      void Reset() { m_eStatus = EStatus::Invalid; }

      void Suspend() { m_eStatus = EStatus::Suspended; }

      void Abort() { Exit(EStatus::Aborted); }

      bool IsTerminated() const
      {
        return m_eStatus == EStatus::Success || m_eStatus == EStatus::Failure;
      }

      bool IsRunning() const { return m_eStatus == EStatus::Running; }

      EStatus GetStatus() { return m_eStatus; }

      EStatus Tick();
    };

    inline EStatus INode::Tick()
    {
      if (m_eStatus != EStatus::Running)
        Enter();
      m_eStatus = Execute();
      if (m_eStatus != EStatus::Running)
        Exit(m_eStatus);
      return m_eStatus;
    }
  } // namespace Node
} // namespace BT

#endif // IBEHAVIOR_HPP
