#ifndef IAGENT_HPP
#define IAGENT_HPP

#include <string>

class IAgent {
protected:
  std::string m_strName;

public:
  IAgent(std::string name) { m_strName = name; }

  ~IAgent() = default;

  virtual void Eat(std::string food) = 0;

  virtual void Speak(std::string dialog) = 0;
};

#endif // IAGENT_HPP
