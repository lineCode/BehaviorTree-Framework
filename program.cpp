#include "./Agent/Bob.hpp"
#include "./BT/Nodes.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
  IAgent *bob = new Bob();
  BT::Composite::Sequence seq(bob);
  seq.AddChild(new BT::Condition(bob, [](IAgent *agent) {
    std::cout << "Sequence 1st condition\n";
    return true;
  }));
  seq.AddChild(new BT::Action(bob, [](IAgent *agent) {
    std::cout << "Sequence 2nd action\n";
    return BT::EStatus::Failure;
  }));
  seq.AddChild(new BT::Action(bob, [](IAgent *agent) {
    std::cout << "Sequence 3rd action\n";
    return BT::EStatus::Success;
  }));
  for (int i = 0; i < 3; i++) {
    seq.Tick();
  }
  BT::Composite::Selector sel(bob);
  sel.AddChild(new BT::Action(bob, [](IAgent *agent) {
    std::cout << "Selector 1st action\n";
    return BT::EStatus::Success;
  }));
  sel.AddChild(new BT::Action(bob, [](IAgent *agent) {
    std::cout << "Selector 2nd action\n";
    return BT::EStatus::Failure;
  }));
  for (int i = 0; i < 3; i++) {
    sel.Tick();
  }
  BT::Composite::Parallel par(bob);
  par.AddChild(new BT::Action(bob, [](IAgent *agent) {
    agent->Eat("Apple");
    return BT::EStatus::Running;
  }));
  par.AddChild(new BT::Action(bob, [](IAgent *agent) {
    agent->Speak("Hello!");
    return BT::EStatus::Running;
  }));
  for (int i = 0; i < 3; i++) {
    par.Tick();
  }
  return 0;
}
