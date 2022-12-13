#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include "./IComposite.hpp"

namespace BT {
namespace Composite {

class Selector : public IComposite {
protected:
  EStatus Execute() override {
    while (m_itCurrent != m_lChildren.end()) {
      EStatus status = (*m_itCurrent)->Tick();
      switch (status) {
      case EStatus::Failure:
        if (++m_itCurrent == m_lChildren.end()) {
          return EStatus::Failure;
        }
        break;
      default:
        return status;
      }
    }
    return m_eStatus;
  }

public:
  Selector(IAgent *agent) : IComposite(agent) {}

  virtual ~Selector() = default;
};

} // namespace Composite
} // namespace BT

#endif // SELECTOR_HPP
