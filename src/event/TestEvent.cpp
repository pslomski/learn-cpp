#include <gmock/gmock.h>
#include <gtest/gtest.h>

class EventManager
{
public:
    using EventCallback = std::function<void()>;

    void subscribe(EventCallback callback) { callbacks.push_back(callback); }

    void notify()
    {
        for (const auto& callback : callbacks)
        {
            callback();
        }
    }

private:
    std::vector<EventCallback> callbacks;
};

class EventHandler
{
public:
    void onEvent() { std::cout << "Event occurred!" << std::endl; }
};

namespace testing
{
TEST(Event, testEvent)
{
    EventManager eventManager;
    EventHandler eventHandler;

    // Subscribe the event handling method
    eventManager.subscribe(std::bind(&EventHandler::onEvent, &eventHandler));

    // Notify when the event happens
    eventManager.notify();
}
} // namespace testing
