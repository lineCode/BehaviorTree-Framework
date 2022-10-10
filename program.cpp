#include "./Agent/Bob.hpp"
#include "./BT/CBehaviorTree.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
  IAgent *bob = new Bob();
  Composite::CSequence sequence(bob);
  sequence.AddChild(new Node::CCondition(bob, [](IAgent *agent) {
    std::cout << "Sequence 1st condition\n";
    return true;
  }));
  sequence.AddChild(new Node::CAction(bob, [](IAgent *agent) {
    std::cout << "Sequence 2nd action\n";
    return Node::EStatus::Failure;
  }));
  sequence.AddChild(new Node::CAction(bob, [](IAgent *agent) {
    std::cout << "Sequence 3rd action\n";
    return Node::EStatus::Success;
  }));
  for (int i = 0; i < 3; i++) {
    sequence.Tick();
  }
  Composite::CSelector selector(bob);
  selector.AddChild(new Node::CAction(bob, [](IAgent *agent) {
    std::cout << "Selector 1st action\n";
    return Node::EStatus::Success;
  }));
  selector.AddChild(new Node::CAction(bob, [](IAgent *agent) {
    std::cout << "Selector 2nd action\n";
    return Node::EStatus::Failure;
  }));
  for (int i = 0; i < 3; i++) {
    selector.Tick();
  }
  Composite::CParallel parallel(bob);
  parallel.AddChild(new Node::CAction(bob, [](IAgent *agent) {
    agent->Eat("Apple");
    return Node::EStatus::Running;
  }));
  parallel.AddChild(new Node::CAction(bob, [](IAgent *agent) {
    agent->Speak("Hello!");
    return Node::EStatus::Running;
  }));
  for (int i = 0; i < 3; i++) {
    parallel.Tick();
  }
  return 0;
}
