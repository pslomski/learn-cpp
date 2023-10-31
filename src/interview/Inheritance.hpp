#pragma once

#include <iostream>
#include <sstream>
#include <string>

class Base
{
public:
    virtual std::string fun() { return "Hello from Base"; }
};

class Engine
{
public:
    virtual ~Engine(){};
    virtual std::string start() = 0;
};

class GasEngine : public Engine
{
public:
    std::string start() override { return "GasEngine::start"; }
};

class Derived : public Base
{
public:
    ~Derived() {}
    std::string fun() override { return "Hello from Derived.fun"; }
    std::unique_ptr<Engine> engine{new GasEngine};
};

using UPtrEngine = std::unique_ptr<Engine>;

std::string run(Engine* engine)
{
    return engine->start();
}
