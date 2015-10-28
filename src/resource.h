#pragma once

#include <unordered_map>

class Resource {
};

class ResourceManager {
public:
    ResourceManager() : _resources() {}
    ResourceManager(ResourceManager&&) = default;

    template<typename T>
    void add(const T&) {
    }

    template<typename T>
    void add(const T&&) {
    }

private:
    std::unordered_map<std::string, Resource> _resources;
};

