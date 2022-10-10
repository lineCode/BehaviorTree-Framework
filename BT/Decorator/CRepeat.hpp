#ifndef REPEAT_HPP
#define REPEAT_HPP

#include "./IDecorator.hpp"

namespace BT {
namespace Decorator {

class CRepeat : public IDecorator {
  int m_iLimit = 0, m_iCount = 0;

  void Enter() override { m_iCount = 0; }

  EStatus Execute() override {
    while (m_iCount < m_iLimit) {
      switch (m_pChild->Tick()) {
      case EStatus::Success:
        if (++m_iCount == m_iLimit) {
          return EStatus::Success;
        }
        break;
      case EStatus::Failure:
        return EStatus::Failure;
      case EStatus::Suspended:
        return EStatus::Suspended;
      case EStatus::Aborted:
        return EStatus::Aborted;
      default:
        break;
      }
      m_pChild->Reset();
    }
    return m_eStatus;
  }

public:
  CRepeat(IAgent *agent, IBehavior *child, int count)
      : IDecorator(agent, child), m_iCount(count) {}

  ~CRepeat() = default;

  void SetCount(int count) { m_iCount = count; }
};

} // namespace Decorator
} // namespace BT

#endif // REPEAT_HPP
