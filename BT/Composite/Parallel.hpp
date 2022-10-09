#ifndef PARALLEL_HPP
#define PARALLEL_HPP

#include "./IComposite.hpp"

namespace BT {
namespace Composite {

class Parallel : public IComposite {
public:
  enum struct Policy { RequireOne, RequireAll };

protected:
  Policy m_eSuccessPolicy, m_eFailurePolicy;

public:
  Parallel(IAgent *agent, Policy successPolicy = Policy::RequireAll,
           Policy failurePolicy = Policy::RequireOne)
      : IComposite(agent), m_eSuccessPolicy(successPolicy),
        m_eFailurePolicy(failurePolicy) {}

  virtual ~Parallel() = default;

  EStatus Execute() override {
    int iSuccessCount = 0, iFailureCount = 0;
    auto iter = m_lChildren.begin();
    while (iter != m_lChildren.end()) {
      IBehavior *node = *iter++;
      if (!node->IsTerminated()) {
        switch (node->Tick()) {
        case EStatus::Success:
          ++iSuccessCount;
          if (m_eSuccessPolicy == Policy::RequireOne) {
            return EStatus::Success;
          }
          break;
        case EStatus::Failure:
          ++iFailureCount;
          if (m_eFailurePolicy == Policy::RequireOne) {
            return EStatus::Failure;
          }
          break;
        default:
          break;
        }
      }
    }
    if (m_eFailurePolicy == Policy::RequireAll &&
        iFailureCount == m_lChildren.size()) {
      return EStatus::Failure;
    }
    if (m_eSuccessPolicy == Policy::RequireAll &&
        iSuccessCount == m_lChildren.size()) {
      return EStatus::Success;
    }
    return EStatus::Running;
  }

  void Exit() override {
    for (auto iter = m_lChildren.begin(); iter != m_lChildren.end(); ++iter) {
      IBehavior *node = *iter;
      if (node->IsRunning())
        node->Abort();
    }
  }
};

} // namespace Composite
} // namespace BT

#endif // PARALLEL_HPP
