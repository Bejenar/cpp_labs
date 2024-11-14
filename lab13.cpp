#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>
#include <string>

struct EventInfo {
    void* data;

    template<typename T>
    T* getData() {
        return static_cast<T*>(data);
    }
};

using EventHandlerFunc = std::function<void(EventInfo*)>;

struct EventHandler {
    size_t id;
    EventHandlerFunc func;

    EventHandler(size_t id, EventHandlerFunc func) : id(id), func(std::move(func)) {}
};

struct EventHandle {
    size_t id;
    std::string name;

    EventHandle() : id(0), name("") {}

    EventHandle(size_t id, const std::string& name) : id(id), name(name) {}
};

struct EventHandlerHandle {
    size_t id;
};

struct EventSystem {
    std::unordered_map<size_t, std::vector<EventHandler>> handlers;
    std::unordered_map<size_t, EventHandle> events;
    size_t nextEventId = 1;
    size_t nextHandlerId = 1;

    EventHandle createEvent(const std::string& eventName) {
        EventHandle event(nextEventId++, eventName);
        events[event.id] = event;
        return event;
    }

    EventHandlerHandle subscribe(size_t eventId, EventHandlerFunc func) {
        if (events.find(eventId) == events.end()) {
            throw std::invalid_argument("Event ID not found.");
        }
        handlers[eventId].emplace_back(nextHandlerId, std::move(func));
        return { nextHandlerId++ };
    }

    bool unsubscribe(size_t eventId, size_t handlerId) {
        if (handlers.find(eventId) == handlers.end()) return false;

        auto& handlerList = handlers[eventId];
        auto it = std::remove_if(handlerList.begin(), handlerList.end(),
                                 [handlerId](const EventHandler& handler) {
                                     return handler.id == handlerId;
                                 });
        if (it != handlerList.end()) {
            handlerList.erase(it, handlerList.end());
            return true;
        }
        return false;
    }

    void dispatch(size_t eventId, EventInfo* eventInfo) {
        if (handlers.find(eventId) == handlers.end()) return;

        for (auto& handler : handlers[eventId]) {
            handler.func(eventInfo);
        }
    }

    void printEvents() const {
        for (const auto& [eventId, event] : events) {
            std::cout << "Event ID: " << eventId << " (" << event.name << ")\n";
            if (handlers.find(eventId) != handlers.end()) {
                for (const auto& handler : handlers.at(eventId)) {
                    std::cout << "  Handler ID: " << handler.id << "\n";
                }
            }
        }
    }
};

void exampleHandlerAdd(EventInfo* eventInfo) {
    int* data = eventInfo->getData<int>();
    *data += 10;
    std::cout << "Added 10: " << *data << "\n";
}

void exampleHandlerMultiply(EventInfo* eventInfo) {
    int* data = eventInfo->getData<int>();
    *data *= 2;
    std::cout << "Multiplied by 2: " << *data << "\n";
}

void menu(EventSystem& system) {
    while (true) {
        int choice;
        std::cout << "Menu:\n1. Create Event\n2. Subscribe Handler\n3. Unsubscribe Handler\n4. Print Events\n5. Dispatch Event\n6. Exit\n";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            std::cout << "Enter event name: ";
            std::cin >> name;
            EventHandle event = system.createEvent(name);
            std::cout << "Created event with ID " << event.id << "\n";
        } else if (choice == 2) {
            size_t eventId;
            std::cout << "Enter event ID: ";
            std::cin >> eventId;

            std::cout << "Choose handler:\n1. Add 10\n2. Multiply by 2\n";
            int handlerChoice;
            std::cin >> handlerChoice;

            EventHandlerFunc func;
            if (handlerChoice == 1) {
                func = exampleHandlerAdd;
            } else if (handlerChoice == 2) {
                func = exampleHandlerMultiply;
            } else {
                std::cout << "Invalid choice.\n";
                continue;
            }

            EventHandlerHandle handle = system.subscribe(eventId, func);
            std::cout << "Subscribed handler with ID " << handle.id << "\n";
        } else if (choice == 3) {
            size_t eventId, handlerId;
            std::cout << "Enter event ID and handler ID to unsubscribe: ";
            std::cin >> eventId >> handlerId;
            if (system.unsubscribe(eventId, handlerId)) {
                std::cout << "Unsubscribed handler.\n";
            } else {
                std::cout << "Handler not found.\n";
            }
        } else if (choice == 4) {
            system.printEvents();
        } else if (choice == 5) {
            size_t eventId;
            std::cout << "Enter event ID to dispatch: ";
            std::cin >> eventId;

            int data;
            std::cout << "Enter data: ";
            std::cin >> data;
            EventInfo eventInfo{ &data };
            system.dispatch(eventId, &eventInfo);
        } else if (choice == 6) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

int main() {
    EventSystem system;
    menu(system);
    return 0;
}
