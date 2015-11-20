#pragma once

class Entity {
public:
private:
  std::unordered_map<std::string, ComponentList> _components;
};

// vim: ts=2:sw=2:et:
