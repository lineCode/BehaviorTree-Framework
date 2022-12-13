#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include "./IComposite.hpp"
#include <list>

namespace BT {
namespace Composite {

class Sequence : public IComposite {
protected:
  EStatus Execute() override {
    while (m_itCurrent != m_lChildren.end()) {
      EStatus status = (*m_itCurrent)->Tick();
      switch (status) {
      case EStatus::Success:
        if (++m_itCurrent == m_lChildren.end()) {
          return EStatus::Success;
        }
        break;
      default:
        return status;
      }
    }
    return m_eStatus;
  }

public:
  Sequence(IAgent *agent) : IComposite(agent) {}

  virtual ~Sequence() = default;
};

} // namespace Composite
} // namespace BT

#endif // SEQUENCE_HPP
