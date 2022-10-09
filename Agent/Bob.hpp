#ifndef BOB_HPP
#define BOB_HPP

#include "./IAgent.hpp"
#include <iostream>

class Bob : public IAgent {
public:
  Bob() : IAgent("Bob") {}

  ~Bob() = default;

  void Eat(std::string food) override {
    std::cout << m_strName << " eating: " << food << "\n";
  }

  void Speak(std::string dialog) override {
    std::cout << m_strName << " speak: " << dialog << "\n";
  }
};

#endif // BOB_HPP
